/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:55:04 by brunofer          #+#    #+#             */
/*   Updated: 2025/10/20 19:02:35 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static void	permutations(int start, int end, char *str);
static void	ft_putstr(char *str);
static void	ft_swap(char *ptr1, char *ptr2);
static int	ft_strlen(char *str);

int	main(int argc, char **argv)
{
	int		len;

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	permutations(0, len, argv[1]);
}

static void	permutations(int start, int end, char *str)
{
	int	i;

	if (start == end)
	{
		ft_putstr(str);
		return ;
	}
	i = start;
	while (start < end)
	{
		ft_swap(str + i, str + start);
		permutations(start + 1, end, str);
		ft_swap(str + i, str + start);
		i++;
	}
}

static void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
	write(1, "\n", 1);
}

static void	ft_swap(char *ptr1, char *ptr2)
{
	char	tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
