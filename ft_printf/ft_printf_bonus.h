/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <42.4.jiyoo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:00:37 by jiyoo             #+#    #+#             */
/*   Updated: 2021/08/16 17:29:24 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	unsigned long	type;
	int				dash;
	int				zero;
	int				width;
	int				precision;
}					t_list;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_i(int n);
void	ft_putnbr_u(unsigned int n);
void	ft_putnbr_x_lower(unsigned long n);
void	ft_putnbr_x_upper(unsigned long n);
void	ft_putnbr_p(unsigned long p);
int		ft_nbr_len(long long n);
int		ft_nbr_len_x(long long n);
int		ft_nbr_len_p(unsigned long p);
int		ft_strlen(const char *s1);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(void);
t_list	*ft_flag_init(t_list *flag);
int		ft_is_form_id(char c);
int		ft_flag_parse(const char *input, int idx, t_list *flag);
int		ft_dash_parse(const char *input, int idx, t_list *flag);
int		ft_zero_parse(const char *input, int idx, t_list *flag);
int		ft_width_parse(const char *input, int idx, t_list *flag);
int		ft_precision_parse(const char *input, int idx, t_list *flag);
void	ft_form_id_parse(const char *input, int idx, t_list *flag);
int		ft_form_id_processor(const char *input,
			int idx, t_list *flag, va_list ap);
int		ft_input_processor(const char *input,
			va_list ap, t_list *flag, int char_count);
int		ft_printf(const char *input, ...);
int		ft_c_processor(t_list *flag, va_list ap);
int		ft_c_dash(int char_count, char c, t_list *flag);
int		ft_c_width(int char_count, char c, t_list *flag);
int		ft_s_processor(t_list *flag, va_list ap);
int		ft_s_precision(int char_count, char *s, t_list *flag);
int		ft_s_width(int char_count, char *s, t_list *flag, int len);
int		ft_i_processor(t_list *flag, va_list ap);
int		ft_i_zero(int char_count, t_list *flag);
int		ft_i_zero_long_precision_wide(int precision_adder,
			int width_adder, t_list *flag);
int		ft_i_zero_long_precision_narrow(int precision_adder, t_list *flag);
int		ft_i_zero_short_precision_wide(int width_adder, t_list *flag);
int		ft_i_zero_precision(int char_count, t_list *flag);
int		ft_i_zero_width(t_list *flag);
int		ft_i_posi(int char_count, int d, int len, t_list *flag);
int		ft_i_posi_long_precision_wide(int d, int len, t_list *flag);
int		ft_i_posi_long_precision_narrow(int d, int len, t_list *flag);
int		ft_i_posi_short_precision_wide(int d, int len, t_list *flag);
int		ft_i_posi_precision(int char_count,
			int d, int len, t_list *flag);
int		ft_i_posi_width(int d, int len, t_list *flag);
int		ft_i_nega(int char_count, int d, int len, t_list *flag);
int		ft_i_nega_long_precision_wide(int d, int len, t_list *flag);
int		ft_i_nega_long_precision_narrow(int d, int len, t_list *flag);
int		ft_i_nega_short_precision_wide(int d, int len, t_list *flag);
int		ft_i_nega_precision(int char_count, int d, int len, t_list *flag);
int		ft_i_nega_width(int d, int len, t_list *flag);
int		ft_u_processor(t_list *flag, va_list ap);
int		ft_u_long_precision_wide(unsigned int u,
			int precision_adder, int width_adder, t_list *flag);
int		ft_u_long_precision_narrow(
			unsigned int u, int precision_adder, t_list *flag);
int		ft_u_short_precision_wide(unsigned int u,
			int width_adder, int len, t_list *flag);
int		ft_u_precision(int char_count, unsigned int u, int len, t_list *flag);
int		ft_u_width(unsigned int u, int len, t_list *flag);
int		ft_x_lower_processor(t_list *flag, va_list ap);
int		ft_x_lower_long_precision_wide(unsigned int x, int len, t_list *flag);
int		ft_x_lower_long_precision_narrow(unsigned int x, int len, t_list *flag);
int		ft_x_lower_short_precision_wide(unsigned int x, int len, t_list *flag);
int		ft_x_lower_precision(int char_count,
			unsigned int x, int len, t_list *flag);
int		ft_x_lower_width(unsigned int x, int len, t_list *flag);
int		ft_x_upper_processor(t_list *flag, va_list ap);
int		ft_x_upper_long_precision_wide(unsigned int x, int len, t_list *flag);
int		ft_x_upper_long_precision_narrow(
			unsigned int x, int precision_adder, t_list *flag);
int		ft_x_upper_short_precision_wide(unsigned int x, int len, t_list *flag);
int		ft_x_upper_precision(int char_count,
			unsigned int x, int len, t_list *flag);
int		ft_x_upper_width(unsigned int x, int len, t_list *flag);
int		ft_p_processor(t_list *flag, va_list ap);
int		ft_p_width(unsigned long p, t_list *flag, int char_count, int len);
#endif