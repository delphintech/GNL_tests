#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line_bonus.h"

# define START(name) printf("\033[0;35m----- %s -----\033[0m\n", name)
# define STRTEST(s) printf("Test: %s\n", s)
# define OK printf("\033[0;32m//  OK  //\033[0m\n")
# define KO printf("\033[0;31m//  KO  //\033[0m\n")

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	// // BONUS
	START("BONUS Get_next_line");

	// Test
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	
	// One line first file
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	
	// One line second file
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	
	// One line first file
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	
	// One line second file
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	// One line first file
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);

	// One line second file
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	close(fd1);
	close(fd2);

	
	return (0);
}