/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:23:47 by misaev            #+#    #+#             */
/*   Updated: 2021/11/14 11:43:13 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_extension_1(t_philo *philo, long int i)
{
	pthread_mutex_lock(&philo->print);
	printf("[%ld] philo %d is eating\n",
		i - philo->time_s, philo->id);
	pthread_mutex_unlock(&philo->print);
}

void	eating_extension(t_philo *philo, long int i)
{
	i = actual_time();
	if (philo->death == 0)
	{
		pthread_mutex_lock(&philo->print);
		printf("[%ld] philo %d is sleeping\n",
			i - philo->time_s, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
	ft_usleep(philo->time_to_sleep);
	i = actual_time();
	if (philo->death == 0)
	{
		pthread_mutex_lock(&philo->print);
		printf("[%ld] philo %d is thinking\n",
			i - philo->time_s, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
}

int	routin_extension(t_philo *titi, int i)
{
	if (i >= titi[i].number_of_philosophers)
		i = 0;
	return (i);
}

void	philo_init_extension(t_philo *toto)
{
	int	i;

	i = 0;
	while (i < toto[i].number_of_philosophers)
	{
		if (i + 1 == toto[i].number_of_philosophers)
			toto[i].right_fork = &toto[0].left_fork;
		else
			toto[i].right_fork = &toto[i + 1].left_fork;
		i++;
	}
}

void	philo_init_extension_1(t_philo *toto, char **argv, int ac, int i)
{
	if (ac == 6)
	{
		toto[i].ac = ac;
		toto[i].philosopher_must_eat = ft_atoi(argv[5]);
	}
}
