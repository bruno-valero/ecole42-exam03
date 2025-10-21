/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:25:22 by valero            #+#    #+#             */
/*   Updated: 2025/10/21 14:18:28 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// static int	ft_strlen(char *str);
static void	*ft_bzero(void *s, int size);
static int	sum_array(int *array, int len);
static void	putnbr(int number);
static void	put_numbers(int *array, int len);
static int	has_it_before(int searched_number, int index, int *src);
static void	powerset(int start, int number, int *selected, int *permutated_set, int *integer_set, int len);

int	main(int argc, char **argv)
{
	int	number;
	int	i;

	if (argc < 3)
		return (1);
	number = atoi(argv[1]);
	int	integer_set[argc - 2];
	int	permutated_set[argc - 2];
	int	selected[argc - 2];
	ft_bzero(selected, (argc - 2) * sizeof(int));
	ft_bzero(permutated_set, (argc - 2) * sizeof(int));
	i = 1;
	while (++i < argc)
		integer_set[i - 2] = atoi(argv[i]);
	powerset(0, number, selected, permutated_set, integer_set, argc - 2);
}

static void	powerset(int start, int number, int *selected, int *permutated_set, int *integer_set, int len)
{
	int	i;

	if (sum_array(permutated_set, start) == number)
		put_numbers(permutated_set, start);
	else
	{
		i = -1;
		while (++i < len)
		{
			if (!selected[i])
			{
				if (start && !has_it_before(permutated_set[start - 1], i, integer_set))
					continue ;
				selected[i] = 1;
				permutated_set[start] = integer_set[i];
				powerset(start + 1, number, selected, permutated_set, integer_set, len);
				selected[i] = 0;
			}
		}
	}
}

static int	has_it_before(int searched_number, int index, int *src)
{
	int	i;

	if (!index)
		return (0);
	i = -1;
	while (++i <= --index)
		if (src[index] == searched_number || src[i] == searched_number)
			return (1);
	return (0);
}

static int	sum_array(int *array, int len)
{
	int	i;
	int	sum;

	sum = 0;
	i = -1;
	while (++i < len)
		sum += array[i];
	return (sum);
}

static void	put_numbers(int *array, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		putnbr(array[i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

static void	putnbr(int number)
{
	char	char_unit;

	if (number > 9)
		putnbr(number / 10);
	char_unit = (number % 10) + '0';
	write(1, &char_unit, 1);
}

// static int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

static void	*ft_bzero(void *s, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)s;
	i = -1;
	while (++i < size)
		ptr[i] = 0;
	return (s);
}
