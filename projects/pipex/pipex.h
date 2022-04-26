/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:29:37 by jiyoo             #+#    #+#             */
/*   Updated: 2021/11/17 15:00:06 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_parse
{
	char	*infile;
	char	**cmd1;
	char	*path1;
	char	**cmd2;
	char	*path2;
	char	*outfile;
}			t_parse;

t_parse	*ft_argv_parse(char **argv);
void	ft_put_path1(t_parse *parse, char **split);
void	ft_put_path2(t_parse *parse, char **split);
void	ft_path_parse(t_parse *parse, char *path);
void	ft_envp_parse(t_parse *parse, char **envp);
void	ft_fork(t_parse *parse, int *fd, char **envp);
void	ft_child_check(t_parse *parse, int *pipe);
void	ft_child_proc(t_parse *parse, int *fd, char **envp);
void	ft_parent_check(t_parse *parse, int *pipe);
void	ft_parent_proc(t_parse *parse, int *pipe, char **envp);
int		get_word_cnt(char *str, char c);
void	ft_strput(char *dst, char *from, char *until);
void	ft_split_check(char *str);
char	*ft_putwords_quote(char *str, char **ret, int idx);
char	*ft_putwords_c(char *str, char **ret, char c, int idx);
char	**ft_putwords(char *str, char c, char **ret);
char	**ft_split(char *str, char c);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif