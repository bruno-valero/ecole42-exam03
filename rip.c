/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:50:14 by valero            #+#    #+#             */
/*   Updated: 2025/10/22 16:40:58 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	verify(const char *parenthesis);
static void	sub(const char *parenthesis, char *result);
static int	ft_strlen(char *str);
static void	*ft_bzero(void *s, int size);
static int	is_valid_closing(const char *parenthesis);
static void	rip(int start, int *selected, char *result, const char *src, const char *original, int len, char target);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int		len = ft_strlen(argv[1]);
	char	src[len + 1];
	src[len] = 0;
	sub(argv[1], src);
	int		selected[len];
	char	result[len + 1];
	ft_bzero(selected, len * sizeof(int));
	ft_bzero(result, (len + 1) * sizeof(int));
	int	balance = verify(argv[1]);
	char target = '(';
	if (balance < 0)
		target = ')';
	rip(0, selected, result, src, argv[1], len, target);
}

static void	rip(int start, int *selected, char *result, const char *src, const char *original, int len, char target)
{
	int	i;

	if (is_valid_closing(original))
		puts(original);
	else if (ft_strlen(result) == len && is_valid_closing(result))
		puts(result);
	else
	{
		i = -1;
		while (src[++i])
		{
			if (!selected[i])
			{
				if (src[i] == ' ' && original[start] != target)
					continue ;
				else if (src[i] != ' ' && original[start] != src[i])
					continue ;
				selected[i] = 1;
				result[start] = src[i];
				rip(start + 1, selected, result, src, original, len, target);
				selected[i] = 0;
				result[start] = 0;
			}
		}
	}
}

static int	is_valid_closing(const char *parenthesis)
{
	int	i;
	int	result;

	result = 0;
	i = -1;
	while (parenthesis[++i])
	{
		if (parenthesis[i] == ' ')
			continue ;
		if (!result && parenthesis[i] == ')')
			return (0);
		if (parenthesis[i] == '(')
			result++;
		else if (parenthesis[i] == ')')
			result--;
	}
	return (result == 0);
}

static int	verify(const char *parenthesis)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (parenthesis[++i])
	{
		if (parenthesis[i] == '(')
			result++;
		else if (parenthesis[i] == ')')
			result--;
	}
	return (result);
}

static void	sub(const char *parenthesis, char *result)
{
	int		i;
	int		balance;
	char	remove;

	balance = verify(parenthesis);
	remove = '(';
	if (balance < 0)
		remove = ')';
	if (balance < 0)
		balance = -balance;
	i = -1;
	while (parenthesis[++i])
	{
		if (balance && parenthesis[i] == remove)
		{
			result[i] = ' ';
			balance--;
		}
		else
			result[i] = parenthesis[i];
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

	ptr = (unsigned char *)s;
	i = -1;
	while (++i < size)
		ptr[i] = 0;
	return (s);
}
