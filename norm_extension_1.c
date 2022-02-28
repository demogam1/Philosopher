/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_extension_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:19:03 by misaev            #+#    #+#             */
/*   Updated: 2021/11/15 14:26:05 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

void	fork_print(t_philo *philo, long int i)
{
	if (philo->ac == 6)
	{
		if (philo->time_eat < philo->philosopher_must_eat
			&& philo->death == 0)
		{
			pthread_mutex_lock(&philo->print);
			printf("[%ld] philo %d has taken a fork\n",
				i - philo->time_s, philo->id);
			pthread_mutex_unlock(&philo->print);
		}
	}
	else if (philo->death == 0)
	{
		pthread_mutex_lock(&philo->print);
		printf("[%ld] philo %d has taken a fork\n",
			i - philo->time_s, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
}

void	wait_line(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
}

void	update_death(t_philo *titi)
{
	int	j;

	j = 0;
	while (j < titi[j].number_of_philosophers)
	{
		titi[j].death = 1;
		j++;
	}
}
