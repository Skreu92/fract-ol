/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 20:02:18 by etranchi          #+#    #+#             */
/*   Updated: 2017/05/15 20:02:19 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void ft_error_arg(void)
{
	ft_putstr("No arg required\n");
	exit(0);
}

void ft_error_malloc(void)
{
	ft_putstr("Error on malloc, try again ! \n");
	exit(0);
}