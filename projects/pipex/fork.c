/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:53:52 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/17 15:25:07 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_check(t_parse *parse, int *pipe)
{
	if (access(parse->path1, F_OK | X_OK) == -1)
	{
		write(1, "command not found\n", 18);
		close(pipe[1]);
		exit(127);
	}
	if (access(parse->infile, R_OK) == -1)
	{
		perror("access error");
		close(pipe[1]);
		exit(1);
	}
}

void	ft_child_proc(t_parse *parse, int *pipe, char **envp)
{
	int	r_fd;

	close(pipe[0]);
	ft_child_check(parse, pipe);
	r_fd = open(parse->infile, O_RDONLY);
	if (r_fd == -1)
	{
		perror("open error");
		exit(1);
	}
	if (dup2(r_fd, STDIN_FILENO) == -1 || dup2(pipe[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	close(r_fd);
	close(pipe[1]);
	if (execve(parse->path1, parse->cmd1, envp) == -1)
	{
		perror("execve error");
		exit(1);
	}
}

void	ft_parent_check(t_parse *parse, int *pipe)
{
	if (access(parse->path2, F_OK | X_OK) == -1)
	{
		write(1, "command not found\n", 18);
		close(pipe[0]);
		exit(127);
	}
}

void	ft_parent_proc(t_parse *parse, int *pipe, char **envp)
{
	int	w_fd;

	close(pipe[1]);
	w_fd = open(parse->outfile, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (w_fd == -1)
	{
		perror("open error");
		exit(1);
	}
	ft_parent_check(parse, pipe);
	if (dup2(w_fd, STDOUT_FILENO) == -1 || dup2(pipe[0], STDIN_FILENO) == -1)
	{
		perror("dup2 error");
		exit(1);
	}
	close(w_fd);
	close(pipe[0]);
	if (execve(parse->path2, parse->cmd2, envp) == -1)
	{
		perror("execve error");
		exit(1);
	}
}

void	ft_fork(t_parse *parse, int *fd, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("fork error");
		exit(1);
	}
	else if (!pid)
		ft_child_proc(parse, fd, envp);
	else
	{
		if (waitpid(pid, &status, WNOHANG) == -1)
			perror("");
		else
			ft_parent_proc(parse, fd, envp);
	}
}
