/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:49:18 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/17 21:13:17 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_parse	*ft_argv_parse(char **argv)
{
	t_parse	*parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	if (parse == 0)
	{
		perror("memory allocation error");
		exit(1);
	}
	parse->infile = ft_strdup(argv[1]);
	parse->cmd1 = ft_split(argv[2], ' ');
	parse->cmd2 = ft_split(argv[3], ' ');
	parse->outfile = ft_strdup(argv[4]);
	return (parse);
}

void	ft_put_path1(t_parse *parse, char **split)
{
	int		i;
	int		ret;
	char	*tmp;
	char	*path;

	i = 0;
	tmp = ft_strjoin("/", parse->cmd1[0]);
	while (split[i])
	{
		path = ft_strjoin(split[i], tmp);
		ret = access(path, F_OK | X_OK);
		if (ret == 0)
			break ;
		else if (ret == -1)
		{
			free(path);
			path = 0;
		}
		i++;
	}
	free(tmp);
	if (path == 0)
		parse->path1 = parse->cmd1[0];
	else
		parse->path1 = path;
}

void	ft_put_path2(t_parse *parse, char **split)
{
	int		i;
	int		ret;
	char	*tmp;
	char	*path;

	i = 0;
	tmp = ft_strjoin("/", parse->cmd2[0]);
	while (split[i])
	{
		path = ft_strjoin(split[i], tmp);
		ret = access(path, F_OK | X_OK);
		if (ret == 0)
			break ;
		else if (ret == -1)
		{
			free(path);
			path = 0;
		}
		i++;
	}
	free(tmp);
	if (path == 0)
		parse->path2 = parse->cmd2[0];
	else
		parse->path2 = path;
}

void	ft_path_parse(t_parse *parse, char *path)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(path, ':');
	while ((*split)[i + 5])
	{
		split[0][i] = split[0][i + 5];
		i++;
	}
	while ((*split)[i])
	{
		split[0][i] = '\0';
		i++;
	}
	ft_put_path1(parse, split);
	ft_put_path2(parse, split);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split[i]);
	free(split);
	split = 0;
}

void	ft_envp_parse(t_parse *parse, char **envp)
{
	char	*path;

	path = 0;
	while (*envp != 0)
	{
		if ((*envp)[0] == 'P' && (*envp)[1] == 'A' &&
		(*envp)[2] == 'T' && (*envp)[3] == 'H')
		{
			path = *envp;
			break ;
		}
		envp++;
	}
	ft_path_parse(parse, path);
}
