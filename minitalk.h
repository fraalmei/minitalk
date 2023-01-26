/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:04:11 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/12 10:16:21 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		send_char(int pid, int chr);
int		send_str(int pid, char *str);
int		send_nbr(int pid, int nbr_sent);
int		send_messaje(int pid, int pid_sent, char *str);
int		np_selector(int pid, char str);

int		get_bit(int sig);
void	get_messaje(int sig);
void	print_char(int start_bit, int end_bit, int *str);
int		get_nbr(int start_bit, int end_bit, int *str);

int		bit_to_byte(int bit, int chr, int bit_pos);
char	byte_to_char(int *str, int start_bit);

#endif
