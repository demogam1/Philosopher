/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:47:30 by misaev            #+#    #+#             */
/*   Updated: 2021/11/15 14:25:03 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				nbr_turns;
	int				time_eat;
	int				ac;
	int				death;
	long int		time_s;
	long int		last_meal;
	pthread_t		th;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philosopher_must_eat;
}					t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int chr);
int			check_arguments(char **argv);
long int	actual_time(void);
void		ft_usleep(int ms);
void		eating_extension_1(t_philo *philo, long int i);
void		eating_extension(t_philo *philo, long int i);
int			routin_extension(t_philo *titi, int i);
void		philo_init_extension(t_philo *toto);
void		philo_init_extension_1(t_philo *toto, char **argv, int ac, int i);
void		fork_print(t_philo *philo, long int i);
void		wait_line(t_philo *philo);
void		update_death(t_philo *titi);
#endif