/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:03:31 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 09:07:56 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

	// function to convert signals to bits
int	get_bit(int sig)
{
	if (sig == SIGUSR1)
		return (0);
	else if (sig == SIGUSR2)
		return (1);
	return (-1);
}

	// function called when a signal is received
void	process_bits(int bits_rec, int	*str)
{
	int			pid;
	int			bits_sent;

	pid = get_nbr(-1, 39, str);
	bits_sent = get_nbr(bits_rec - 57, bits_rec - 17, str);
	if (bits_sent == bits_rec)
	{
		print_char(39, bits_rec - 56, str);
		if (pid != 0)
		{
			send_messaje(pid, 00000, "Mensaje recibido correctamente.");
			usleep(2000);
			kill(pid, SIGINT);
		}
	}
	else
	{
		send_messaje(pid, 00000, "Mensaje recibido incorrectamente.");
		usleep(2000);
		kill(pid, SIGINT);
	}
}

		// receive the signals and save in a array
		// printing that array when the transmission ends
void	get_messaje(int sig)
{
	static int	str[INT_MAX];
	static int	i;
	static int	eof;

	str[i] = get_bit(sig);
	if (str[i] == 1)
		eof = (i++, 0);
	else if (str[i] == 0)
		eof = (i++, eof + 1);
	if (eof == 15)
	{
		usleep (100);
		process_bits(i, str);
		ft_bzero(str, i);
		eof = 0;
		i = 0;
	}
}

	// function to roam the string where the bits save
	// and printing the chars in eight bits
void	print_char(int start_bit, int end_bit, int *str)
{
	while (start_bit < end_bit - 1)
	{
		ft_printf ("%c", byte_to_char(str, start_bit));
		start_bit += 8;
	}
}

	// function to search a number in a determinated position of bits
int	get_nbr(int start_bit, int end_bit, int *str)
{
	int		nbr;
	char	c;

	nbr = 0;
	while (start_bit < end_bit - 1)
	{
		c = byte_to_char(str, start_bit);
		nbr = (nbr * 10) + (c - 48);
		start_bit += 8;
	}
	return (nbr);
}
