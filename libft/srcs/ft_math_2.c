/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftinkere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:21:03 by ftinkere          #+#    #+#             */
/*   Updated: 2020/12/20 16:21:06 by ftinkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"

t_i64	mround_even(long double x)
{
	t_i64	flord;

	flord = mfloor(x + 0.5);
	if (mabs_d(x - flord) == 0.5 && flord % 2 == 1)
		return (flord + (t_i64)((x - flord) * 2));
	return (flord);
}

t_u64	mflooru(long double x)
{
	if (x < 0)
		return ((t_u64)x - 1);
	return ((t_u64)x);
}

t_u64	mroundu_even(long double x)
{
	t_u64	flord;

	flord = mflooru(x + 0.5);
	if (mabs_d(x - flord) == 0.5 && flord % 2 == 1)
		return (flord + (t_u64)((x - flord) * 2));
	return (flord);
}

t_u64	sign_d(double x)
{
	t_u64	i_e;

	ft_memcpy(&i_e, &x, 8);
	return ((i_e & (1ll << 63)) >> 63);
}
