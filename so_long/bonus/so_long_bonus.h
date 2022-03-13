/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:47:15 by jiyoo             #+#    #+#             */
/*   Updated: 2021/12/05 19:28:13 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define BUFFER_SIZE 10000

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
	int		levi_x;
	int		levi_y;
	int		left_key;
	int		count;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	char	*tile_path;
	char	*wall_path;
	char	*levi_path;
	char	*key_path;
	char	*door_path;
	t_map	*map_data;
}	t_data;

int		new_line_idx_finder(char *saved_data);
int		new_line_processor(char **saved_fd, char **line, int idx, char *buf);
int		left_data_processor(char **saved_fd, char **line, int idx, char *buf);
int		get_next_line(int fd, char **line);
int		ft_keyhook(int keycode, t_data *mlx_data);
int		ft_exit(void);
void	ft_interaction(t_data *mlx_data);
int		ft_numlen(int n);
void	ft_putnbr(int n, char *ptr, int len);
char	*ft_itoa(int n);
int		ft_map_width_check(t_map *map_data);
int		ft_map_wall_check(t_map *map_data);
int		ft_map_element_check(t_map *map_data);
int		ft_map_validity_check(t_map *map_data, int p, int e, int c);
void	ft_mapcheck(t_map *map_data);
void	ft_draw(t_data *mlx_data, int x, int y, char *path);
void	ft_doordraw(t_data *mlx_data, t_map *map_data);
void	ft_movedraw(t_data *mlx_data, t_map *map_data, int x, int y);
void	ft_ending_draw(t_data *mlx_data, t_map *map_data);
void	ft_mapinit(t_map *map_data, t_data *mlx_data);
void	ft_mapdraw(t_map *map_data, t_data *mlx_data, int x, int y);
int		ft_maplen(char	**argv);
void	ft_mapsave(char	**argv, int len, t_map *map_data);
void	ft_levi_coord(t_map *map_data, int keycode);
void	ft_collectible_manage(t_map *map_data, int x, int y);
void	ft_count_print(t_data *mlx_data, t_map *map_data);
void	ft_escape(t_data *mlx_data);
void	ft_move_up(t_data *mlx_data, t_map *map_data, int x, int y);
void	ft_move_left(t_data *mlx_data, t_map *map_data, int x, int y);
void	ft_move_down(t_data *mlx_data, t_map *map_data, int x, int y);
void	ft_move_right(t_data *mlx_data, t_map *map_data, int x, int y);
void	ft_move(int keycode, t_data *mlx_data, t_map *map_data);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	ft_puterror(void);

#endif