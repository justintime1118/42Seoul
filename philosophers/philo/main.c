/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:35:47 by jiyoo             #+#    #+#             */
/*   Updated: 2022/03/11 11:28:02 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*vars;

	if ((argc != 5 && argc != 6))
		ft_error("invalid arguments");
	vars = ft_init(argv);
	if (pthread_create(&(vars->th_id[0]), 0, ft_simulation, vars) != 0)
		ft_error("simulation creation error");
	while (vars->begin_time == 0)
		usleep(1000);
	while (1)
	{
		ft_full_detector(vars);
		usleep(1000);
	}
	return (0);
}

// 데드락을 예방하기 위한 조처가 미흡하지 않은지, 서브젝트에 위반되지 않는지 점검
// 마지막으로 처음부터 끝까지 흐름을 쭉 따라가면서 여러가지 경우의 수들을 모두 고려해보고 빠뜨린 부분이 없는지 확인
// 막힘없이 어떤 질문도 대답 가능하도록 코드 흐름과 잘 돌아가는 원리, 각 함수와 변수들의 의미, 내부동작 원리들 잘 정리해두자