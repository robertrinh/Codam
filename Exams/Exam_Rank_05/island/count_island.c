// Assignment name  : count_island
// Expected files   : *.c, *.h
// Allowed functions: open, close, read, write, malloc, free
// --------------------------------------------------------------------------------
// Write a program that takes a file that contains lines of equal length. Those
// lines contain characters that are either '.' or 'X'. All those lines put
// together form rectangles of '.' containing "islands" of 'X'.
// The maximum size of a line is 1024 characters, including the terminating
// newline.
// A column if formed of the set of characters in the file that are separated from
// the start of their respective lines by the same number of characters.
// Two characters are said to be touching if they are contiguous and on the same
// line, or on contiguous lines and on the same column.
// An "island" of 'X' means a set of 'X' touching each other.
// The program must walk though the file and display it after replacing all the
// 'X' by a number corresponding to the position their island appears in the file,
// starting at the beginning of the file.
// There can be only one result.
// If the file is empty, or there is an error (Incoherent input, for example), or
// no parameters are passed, the program must display a newline.
// The file contains at most 10 islands.
// You will find examples in the subject directory.
// Examples:
// $>cat toto
// .................XXXXXXXX..........................................
// ....................XXXXXXXXX.......XXXXXXXX.......................
// .................XXXXXXXX..............XXX...XXXXX.................
// .....................XXXXXX.....X...XXXXXXXXXXX....................
// ................................X..................................
// ......XXXXXXXXXXXXX.............X..................................
// ..................X.............XXXXXXXXX..........................
// ..................X.........XXXXXXXXXXXX...........................
// ..................X................................................
// XX.............................................................XXXX
// XX..................XXXXXXXXXXXXX.................................X
// ...................................................................
// .................................................................X.
// .....................XXXXX.......................................XX
// $>
// $>./count_island toto
// .................00000000..........................................
// ....................000000000.......11111111.......................
// .................00000000..............111...11111.................
// .....................000000.....2...11111111111....................
// ................................2..................................
// ......3333333333333.............2..................................
// ..................3.............222222222..........................
// ..................3.........222222222222...........................
// ..................3................................................
// 44.............................................................5555
// 44..................6666666666666.................................5
// ...................................................................
// .................................................................7.
// .....................88888.......................................77
// $>
// $>cat qui_est_la
// ...................................................................
// ...X........X.....XXXXX......XXXXXXX...XXXXXXXXXX..XXXXXXXXXX......
// ...XX......XX....XX...XX....XX.....XX.....XXXX.....XXXXXXXXXX......
// ...XXXX..XXXX...XX.....XX...XX.....XX......XX......XX..............
// ...XX.XXXX.XX...XX.....XX...XX.....XX......XX......XX..............
// ...XX...X..XX...XX.....XX...XXXXXXXX.......XX......XXXXX...........
// ...XX......XX...XXXXXXXXX...XXXX...........XX......XXXXX...........
// ...XX......XX..XX.......XX..XX.XX..........XX......XX..............
// ...XX......XX..XX.......XX..XX...X.........XX......XX..............
// ...XX......XX..XX.......XX..XX....X......XXXXXX....XXXXXXXXXX......
// ...XX......XX.XX.........XX.XX.....XX..XXXXXXXXXX..XXXXXXXXXX..X...
// ...................................................................
// $>
// $>./count_island qui_est_la
// ...................................................................
// ...0........0.....11111......2222222...3333333333..4444444444......
// ...00......00....11...11....22.....22.....3333.....4444444444......
// ...0000..0000...11.....11...22.....22......33......44..............
// ...00.0000.00...11.....11...22.....22......33......44..............
// ...00...0..00...11.....11...22222222.......33......44444...........
// ...00......00...111111111...2222...........33......44444...........
// ...00......00..11.......11..22.22..........33......44..............
// ...00......00..11.......11..22...5.........33......44..............
// ...00......00..11.......11..22....6......333333....4444444444......
// ...00......00.11.........11.22.....77..3333333333..4444444444..8...
// ...................................................................
// $>
// $>cat -e rien
// $>./count_island rien | cat -e
// $
// $>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// Helper: validate map and get line width
// Returns 1 if valid, 0 if invalid
int validate_map(char *map, int size, int *width)
{
	int i = 0;
	int check_len = 0;
	
	while (i < size)
	{
		// Check for invalid characters
		if (map[i] != '.' && map[i] != 'X' && map[i] != '\n')
			return (0);
		
		if (map[i] == '\n')
		{
			// First line sets the width
			if (*width == 0)
				*width = check_len;
			// All other lines must match the width
			else if (check_len != *width)
				return (0);
			check_len = 0;
		}
		else
		{
			check_len++;
			// Check max line length (1024 chars excluding newline)
			if (check_len > 1024)
				return (0);
		}
		i++;
	}
	return (1);
}

// Recursive flood fill - marks all connected 'X' with island number
// Uses 1D array index math for 2D navigation
void flood_fill(char *map, int idx, int width, int size, char num)
{
	// Check bounds and if it's still an 'X'
	if (idx < 0 || idx >= size || map[idx] != 'X')
		return;
	
	// Mark with island number
	map[idx] = num;
	
	// 4-directional fill (account for '\n' in 1D array)
	flood_fill(map, idx + 1, width, size, num);           // Right
	flood_fill(map, idx - 1, width, size, num);           // Left
	flood_fill(map, idx + width + 1, width, size, num);   // Down (+1 for '\n')
	flood_fill(map, idx - width - 1, width, size, num);   // Up (-1 for '\n')
}

// Main island counting function
int count_island(char *filename)
{
	int fd, ret, size = 0, width = 0;
	char buf[4096];
	char *map = NULL;
	
	// Open and read file
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	
	// Read file into dynamically growing buffer
	while ((ret = read(fd, buf, 4096)) > 0)
	{
		char *temp = malloc(size + ret);
		if (!temp)
		{
			if (map)
				free(map);
			close(fd);
			return (0);
		}
		
		// Copy existing map to temp
		if (map)
		{
			int i = 0;
			while (i < size)
			{
				temp[i] = map[i];
				i++;
			}
			free(map);
		}
		
		// Copy new data to temp
		int i = 0;
		while (i < ret)
		{
			temp[size + i] = buf[i];
			i++;
		}
		
		map = temp;
		size += ret;
	}
	close(fd);
	
	// Validate map (check chars and line widths)
	if (!map || size == 0 || !validate_map(map, size, &width))
	{
		if (map)
			free(map);
		return (0);
	}
	
	// Find and number islands
	char island_num = '0';
	int i = 0;
	while (i < size)
	{
		if (map[i] == 'X')
		{
			flood_fill(map, i, width, size, island_num);
			island_num++;
		}
		i++;
	}
	
	// Output result
	write(1, map, size);
	free(map);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!count_island(argv[1]))
			write(1, "\n", 1);
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}
