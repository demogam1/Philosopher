/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:46:49 by misaev            #+#    #+#             */
/*   Updated: 2021/11/15 15:40:41 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eating(void *arg)
{
	long int	i;
	t_philo		*philo;

	i = 0;
	philo = arg;
	wait_line(philo);
	while (1)
	{
		pthread_mutex_lock(philo->right_fork);
		i = actual_time();
		fork_print(philo, i);
		pthread_mutex_lock(&philo->left_fork);
		i = actual_time();
		fork_print(philo, i);
		i = actual_time();
		if (philo->death == 0)
			eating_extension_1(philo, i);
		ft_usleep(philo->time_to_eat);
		philo->time_eat++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		philo->last_meal = actual_time();
		eating_extension(philo, i);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo		*titi;
	int			i;
	long int	at;

	i = 0;
	titi = arg;
	while (1)
	{
		at = actual_time();
		if ((titi[i].time_eat > titi[i].philosopher_must_eat
				&& titi[i].ac == 6))
			return (NULL);
		if (actual_time() - titi[i].last_meal > titi[i].time_to_die)
		{
			update_death(titi);
			printf("[%ld] philo[%d] is dead\n", at - titi[i].time_s, titi[i].id);
			return (NULL);
		}
		i++;
		i = routin_extension(titi, i);
	}
	return (NULL);
}

void	philo_start(t_philo *philo)
{
	int			i;
	pthread_t	death;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		philo[i].time_s = actual_time();
		philo[i].last_meal = actual_time();
		if (pthread_create(&philo[i].th, NULL, &eating, &(philo[i])) != 0)
			return ;
		i++;
	}
	pthread_create(&death, NULL, &routine, philo);
	pthread_join(death, NULL);
}

t_philo	*philo_init(t_philo *philo, char **argv, int ac)
{
	int		i;
	t_philo	*toto;

	toto = philo;
	i = 0;
	toto = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&toto[i].left_fork, NULL);
		pthread_mutex_init(&toto[i].print, NULL);
		toto[i].id = i + 1;
		toto[i].nbr_turns = 0;
		toto[i].last_meal = 0;
		toto[i].time_eat = 0;
		toto[i].death = 0;
		toto[i].time_s = 0;
		toto[i].number_of_philosophers = ft_atoi(argv[1]);
		toto[i].time_to_die = ft_atoi(argv[2]);
		toto[i].time_to_eat = ft_atoi(argv[3]);
		toto[i].time_to_sleep = ft_atoi(argv[4]);
		philo_init_extension_1(toto, argv, ac, i);
		i++;
	}
	philo_init_extension(toto);
	return (toto);
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = NULL;
	if (argc > 6 || argc < 5 || check_arguments(argv) == 1 || argv[1] == NULL)
	{
		printf("Arguments are not correct !");
		return (0);
	}
	else
	{
		philo = philo_init(philo, argv, argc);
		philo_start(philo);
	}
	return (0);
}
