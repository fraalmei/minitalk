/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 09:26:41 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/05 09:46:43 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

	// function to read the next eight bits
	// and return a int
char	byte_to_char(int *str, int start_bit)
{
	int		chr;
	int		l;
	int		k;

	chr = 0;
	k = 8;
	l = start_bit + 8;
	while (++start_bit <= l)
	{
		chr = bit_to_byte(str[start_bit], chr, k);
		k--;
	}
	return (chr);
}

	// function to convert bits to dec
int	bit_to_byte(int bit, int chr, int bit_pos)
{
	int	i;

	i = 2;
	if (bit_pos == 1 && bit == 1)
		chr += 1;
	else if (bit_pos == 2 && bit == 1)
		chr += 2;
	else if (bit_pos > 2 && bit == 1)
	{
		bit_pos -= 2;
		while (bit_pos--)
			i = i * 2;
		chr += i;
	}
	return (chr);
}
