/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valero <valero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:50:14 by valero            #+#    #+#             */
/*   Updated: 2025/10/22 18:28:34 by valero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	verify(const char *parenthesis);
static int	ft_strlen(char *str);
static void	*ft_bzero(void *s, int size);
static int	is_valid_closing(const char *parenthesis);
static void	rip(int start, char *result, const char *src, const char *original, int len, char target);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int		len = ft_strlen(argv[1]);
	char	result[len + 1];
	ft_bzero(result, (len + 1) * sizeof(char));
	int	balance = verify(argv[1]);
	char target = '(';
	if (balance < 0)
		target = ')';
	rip(0, result, "() ", argv[1], len, target);
}

static void	rip(int start, char *result, const char *src, const char *original, int len, char target)
{
	int	i;

	if (is_valid_closing(original))
		puts(original);
	else if (result[len - 1] && is_valid_closing(result))
		puts(result);
	else
	{
		i = -1;
		while (src[++i])
		{
			if (src[i] == ' ' && original[start] != target)
				continue ;
			else if (src[i] != ' ' && original[start] != src[i])
				continue ;
			result[start] = src[i];
			rip(start + 1, result, src, original, len, target);
			result[start] = 0;
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
