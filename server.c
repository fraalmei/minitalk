/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:45:02 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 09:14:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	end_p(int sig)
{
	if (sig == 2)
		exit(EXIT_SUCCESS);
	exit (EXIT_SUCCESS);
}
	//system ("leaks server");

int	main(void)
{
	ft_printf("PID: %i\n", getpid());
	signal(SIGUSR1, get_messaje);
	signal(SIGUSR2, get_messaje);
	signal(SIGINT, end_p);
	while (1)
		pause();
	return (0);
}
