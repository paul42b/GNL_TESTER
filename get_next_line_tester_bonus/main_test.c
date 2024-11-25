/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuchter <pbuchter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:49:36 by pbuchter          #+#    #+#             */
/*   Updated: 2024/11/21 15:17:33 by pbuchter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
	char	*buff;
	char	*path[5];
	char	*test;
	char	comparison[] = "File0Line0\nFile1Line0\nFile0Line1\nFile1Line1\nFile0Line2\nFile1Line2\nFile0Line3\nFile1Line3\nFile0Line4\nFile1Line4\n";
	int		i;
	int		j;
	int		difference = 0;
	int		fd[2];

	path[0] = "./0_only_new_lines.txt";
	path[1] = "./1_single char + newline.txt";

	test = malloc(2000);
	if (!test)
		return (0);
	i = 0;

	while (i < 2)
	{
		fd[i] = open(path[i], O_RDONLY);
		if (fd[i] < 0)
		{
			return (1);
		}
		i++;
	}
	j = 0;
	while (j < 5)
	{
		i = 0;
		while(i < 2)
		{
			buff = get_next_line(fd[i]);
			test = ft_strjoin(test, buff);
			free (buff);
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 2)
	{
		close(fd[i]);
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
