/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:41:26 by gdupont           #+#    #+#             */
/*   Updated: 2021/07/21 17:38:33 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_separateur(char *s, char c)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int computeNbWord(char *source, char *sep)
{
	int nb = 0;
	int i = 0;

	if (!sep || !source || !sep[0] || !source[0])
		return (0);
	while (source[i])
	{
		while (is_separateur(sep, source[i])) //tant que ce n'est pas un mot
			i++;
		if (!source[i])
			return (nb);
		while (is_separateur(sep, source[i]) == 0)  //tant que cest un mot
			i++;
		nb++;
	}
	return (nb);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	strncpy(dest, src, n);
}

int		ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char **ft_split(char *source, char *sep)
{
	int nb_word;
	char **final;
	int i;
	int len_word;
	int position_in_source = 0;

	
	nb_word = computeNbWord(source, sep);
	final = malloc(sizeof(char *) * (nb_word + 1));
	final[nb_word] = NULL;
	i = 0;
	while (final[i])
	{
		len_word = 0;
		while (is_separateur(sep, source[position_in_source])) //tant que ce n'est pas un mot
			position_in_source++;
		while (is_separateur(sep, source[position_in_source + len_word]) == 0)  //tant que cest un character de mot
			len_word++;
		final[i] = malloc(len_word + 1);
		ft_strncpy(final[i], &source[position_in_source], len_word);
		position_in_source += len_word;
		final[i][len_word] = '\0';
		i++;
	}
	return (final);
}

int main (int ac, char **av)
{
	char **str;
	int i = 0;

	str = ft_split(av[1], av[2]);
	while(str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}	
}