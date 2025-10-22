/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:26:48 by valero            #+#    #+#             */
/*   Updated: 2025/10/22 13:19:13 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	*ft_bzero(void *s, int size);
static int	sum_array(const int *array, int len);
static void	print_array(const int *array, int len);
static int	last_one_is_before(int target_value, int back_idx, const int *src);
static void	powerset(int start, int objective, int *selected, int *result, const int *src, const int len);

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 3)
		return (1);
	int objective = atoi(argv[1]);
	int	nbr_set_len = argc - 2;
	int	selected[nbr_set_len];
	int result[nbr_set_len];
	ft_bzero(selected, nbr_set_len * sizeof(int));
	ft_bzero(result, nbr_set_len * sizeof(int));
	int src[nbr_set_len];
	i = -1;
	while (++i < nbr_set_len)
		src[i] = atoi(argv[i + 2]);
	powerset(0, objective, selected, result, src, nbr_set_len);
}

static void	powerset(int start, int objective, int *selected, int *result, const int *src, const int len)
{
	int	i;

	if (sum_array(result, start) == objective)
		print_array(result, start);
	else
	{
		i = -1;
		while (++i < len)
		{
			if (!selected[i])
			{
				if (start && last_one_is_before(result[start - 1], i, src))
					continue ;
				selected[i] = 1;
				result[start] = src[i];
				powerset(start + 1, objective, selected, result, src, len);
				selected[i] = 0;
				result[start] = 0;
			}
		}
	}
}

static int	last_one_is_before(int target_value, int back_idx, const int *src)
{
	int	front_idx;

	front_idx = -1;
	while (++front_idx <= --back_idx)
		if (src[front_idx] == target_value || src[back_idx] == target_value)
			return (1);
	return (0);
}

static int	sum_array(const int *array, int len)
{
	int	sum;

	sum = 0;
	while (--len >= 0)
		sum += array[len];
	return (sum);
}

static void	print_array(const int *array, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		printf("%d", array[i]);
		if (i + 1 < len)
			printf(" ");
	}
	printf("\n");
}

static void	*ft_bzero(void *s, int size)
{
	unsigned char	*ptr;
	int				i;

	if (!s || !size || size < 0)
		return (s);
	ptr = (unsigned char *)s;
	i = -1;
	while (++i < size)
		ptr[i] = 0;
	return (s);
}
