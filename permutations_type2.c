/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_type2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:22:12 by valero            #+#    #+#             */
/*   Updated: 2025/10/21 12:10:58 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	permutation(int start, int *selected, char *result, char *str, int len);
static void	put_str(char *str);
static int	ft_strlen(char *str);
static void	*ft_bzero(void *s, int size);

int	main(int argc, char **argv)
{
	int		len;

	if (argc < 2)
		return (1);
	len = ft_strlen(argv[1]);
	char	result[len + 1];
	int		seleted[len];
	ft_bzero(result, (len + 1) * sizeof(char));
	ft_bzero(seleted, len * sizeof(int));
	permutation(0, seleted, result, argv[1], len);
}

static void	permutation(int start, int *selected, char *result, char *str, int len)
{
	int	i;

	if (start == len)
		put_str(result);
	else
	{
		i = -1;
		while (++i < len)
		{
			if (!selected[i])
			{
				selected[i] = 1;
				result[start] = str[i];
				permutation(start + 1, selected, result, str, len);
				selected[i] = 0;
			}
		}
	}
}

static void	put_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, str + i, 1);
	write(1, "\n", 1);
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

	ptr = (unsigned char *)s;
	i = -1;
	while (++i < size)
		ptr[i] = 0;
	return (s);
}
