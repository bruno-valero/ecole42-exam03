/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_type2_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:57:17 by valero            #+#    #+#             */
/*   Updated: 2025/10/22 12:15:56 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_strlen(char *str);
static void	*ft_bzero(void *s, int size);
static void	permutation(int start, int *selected, char *result, char *src, int len);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int 	len = ft_strlen(argv[1]);
	int		selected[len];
	char	result[len];
	ft_bzero(selected, len * sizeof(int));
	ft_bzero(result, len * sizeof(char));
	permutation(0, selected, result, argv[1], len);
}

static void	permutation(int start, int *selected, char *result, char *src, int len)
{
	int	i;

	if (start == len)
		puts(result);
	else
	{
		i = -1;
		while (++i < len)
		{
			if (!selected[i])
			{
				selected[i] = 1;
				result[start] = src[i];
				permutation(start + 1, selected, result, src, len);
				selected[i] = 0;
			}
		}
	}
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
