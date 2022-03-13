/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:51:52 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/16 16:53:12 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_parse	*parse;
	int		*fd;

	if (argc != 5)
		exit(1);
	parse = ft_argv_parse(argv);
	ft_envp_parse(parse, envp);
	fd = (int *)malloc(sizeof(int) * 2);
	if (fd == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	ft_fork(parse, fd, envp);
}
