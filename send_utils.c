/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:49:32 by fraalmei          #+#    #+#             */
/*   Updated: 2022/09/21 17:12:44 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

	// function to roam the char bit by bit
	// and send a signalfor every bit
int	send_char(int pid, int chr)
{
	int		i;
	int		bit_snt;

	bit_snt = 0;
	i = 8;
	while (i--)
	{
		if (chr >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit_snt++;
		usleep (100);
	}
	return (bit_snt);
}

	// function to send the string char by char
int	send_str(int pid, char *str)
{
	int		bit_snt;
	int		i;

	i = 0;
	bit_snt = 0;
	while (str[i])
	{
		if (str[i] == 92 && !(str[i + 1] == 0))
		{
			i++;
			bit_snt += np_selector(pid, str[i++]);
		}
		else
			bit_snt += send_char(pid, str[i++]);
	}
	return (bit_snt);
}

	// function to send a number
int	send_nbr(int pid, int nbr_sent)
{
	int		i;
	int		bit_snt;

	bit_snt = 0;
	i = 10000;
	while (i)
	{
		bit_snt += send_char (pid, ('0' + nbr_sent / i));
		nbr_sent = nbr_sent % i;
		i /= 10;
	}
	return (bit_snt);
}

	// function to send no printable chars
int	np_selector(int pid, char str)
{
	int		bit_snt;

	bit_snt = 0;
	if (str == 'n')
		bit_snt += send_char(pid, 10);
	else if (str == 'a')
		bit_snt += send_char(pid, 7);
	else if (str == 'b')
		bit_snt += send_char(pid, 8);
	else if (str == 'f')
		bit_snt += send_char(pid, 12);
	else if (str == 'r')
		bit_snt += send_char(pid, 13);
	else if (str == 't')
		bit_snt += send_char(pid, 9);
	else if (str == 'v')
		bit_snt += send_char(pid, 11);
	else if (str == '\\')
		bit_snt += send_char(pid, '\\');
	else
	{
		bit_snt += send_char(pid, '\\');
		bit_snt += send_char(pid, str);
	}
	return (bit_snt);
}

	// function to compose the message to send
int	send_messaje(int pid, int nbr_sent, char *str)
{
	int		bit_snt;

	bit_snt = 0;
	bit_snt += send_nbr(pid, nbr_sent);
	bit_snt += send_str(pid, str);
	bit_snt += send_nbr(pid, bit_snt + 40 + 16);
	bit_snt += send_char(pid, 128);
	bit_snt += send_char(pid, 0);
	return (bit_snt);
}
