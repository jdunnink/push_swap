/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 12:09:19 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/03/29 15:10:15 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	count_word counts and returns the number of
**	word seperators (c) in the string s.
*/

static	int		count_word(char const *s, char c)
{
	int x;

	x = 0;
	s++;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c && *(s - 1) != c)
			x++;
		s++;
	}
	if (*s == '\0' && *(s - 1) != c)
		x++;
	return (x);
}

/*
**	word_cpy takes a pointer to the start of a word, allocates
**	a sufficient memory block and copies from ptr until
**	a word separator is found.
*/

static	char	*word_cpy(char const *ptr, char c)
{
	int		i;
	char	*dest;

	i = 0;
	while (ptr[i] != c && ptr[i] != '\0')
		i++;
	dest = (char*)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (ptr[i] != c && ptr[i] != '\0')
	{
		dest[i] = ptr[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
**	filter_front is used to filter redundant word separators
**	found at the start of the string s.
*/

static	void	filter_front(char const **s, char c)
{
	while (**s == c)
		*s = *s + 1;
}

/*
**	ft_strsplit takes a string sentence and returns
**	an array of strings with each word in the sentence being
**	a nul-terminated string within this array. the character
**	passed as argument is used as a word separator to determine
**	what constitutes a word.
*/

char			**ft_strsplit(char const *s, char c)
{
	char			**dest;
	unsigned int	psize;
	unsigned int	x;

	if (!s)
		return (NULL);
	psize = count_word(s, c);
	dest = (char**)malloc(sizeof(char*) * (psize + 1));
	if (!dest)
		return (NULL);
	filter_front(&s, c);
	x = 0;
	while (x < psize)
	{
		dest[x] = word_cpy(s, c);
		while (*s != c && *s != '\0')
			s++;
		if (x != psize - 1)
			s++;
		while (*s == c)
			s++;
		x++;
	}
	dest[x] = 0;
	return (dest);
}
