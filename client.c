/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:31:58 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 12:47:19 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

static void	end_p(int sig)
{
	if (sig == 2)
		exit(EXIT_SUCCESS);
	exit (EXIT_SUCCESS);
}
	//system ("leaks client");

int	main(int argc, char *argv[])
{
	int	i;

	i = INT_MAX;
	if (argc != 3)
		return (0);
	send_messaje(ft_atoi(argv[1]), getpid(), argv[2]);
	signal(SIGUSR1, get_messaje);
	signal(SIGUSR2, get_messaje);
	signal(SIGINT, end_p);
	while (i)
		i--;
	ft_printf ("Error en el envio o recepción del mensaje.\n");
	end_p(0);
	return (0);
}
