/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:52:26 by dabouab           #+#    #+#             */
/*   Updated: 2024/05/30 11:01:48 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

# define START(name) printf("\033[0;35m----- %s -----\033[0m\n", name)
# define STRTEST(s) printf("Test: %s\n", s)
# define OK printf("\033[0;32m//  OK  //\033[0m\n")
# define KO printf("\033[0;31m//  KO  //\033[0m\n")

int	main(void)
{
	int		fd;
	char	*line;


	START("Get_next_line");
	fd = open("test.txt", O_RDONLY);
	
	// Test 1
	// STRTEST("One line");
	// line = get_next_line(fd);
	// if (strcmp("Rules of the Internet\n", line) != 0)
	// {
	// 	printf("Expected: 'Rules of the Internet\\n'\nGot: %s\n", line);
	// 	KO;
	// 	free(line);
	// 	return (0);
	// }
	// free(line);
	// OK;

	// Test 2
	STRTEST("Whole text");
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	
	close(fd);

	return (0);
}
