/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuchter <pbuchter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:49:36 by pbuchter          #+#    #+#             */
/*   Updated: 2024/11/18 14:39:28 by pbuchter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
	int		fd;
	char	*buff;
	char	*path[5];
	char	*test;
	char	comparison[] = "\n\n\n\na\na\na\na\n\n\na dsnlfnskldnflksn s dfsfs    \nadsf s fsdf sdf sddd sdf sd f\nad ds fsdf sd fsdf sd\nasd fsd fsdddd\nasdf sd \n";
	int		i;
	int		difference = 0;

	path[0] = "./0_only_new_lines.txt";
	path[1] = "./1_single char + newline.txt";
	path[2] = "./2_empty.txt";
	path[3] = "./3_regular single line.txt";
	path[4] = "./4_multiple regular lines.txt";
	test = malloc(2000);
	if (!test)
		return (0);
	i = 0;
	while(i < 5)
	{
		fd = open(path[i], O_RDONLY);
		while ((buff = get_next_line(fd)) != 0)
		{
			test = ft_strjoin(test, buff);
			free (buff);
		}
		close(fd);
		i++;
	}
	difference = ft_strncmp(test,comparison,1000);
	printf("Grabbed through code:\n%s\n", test);
	printf("Comparison string:\n%s\n", comparison);
	printf("Difference: %d\n", difference);
	if (difference == 0)
		printf("TEST_PASSED BUFFER_SIZE %d", BUFFER_SIZE);
	else
		printf("TEST_NOT_PASSED BUFFER_SIZE %d", BUFFER_SIZE);
	free(test);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
