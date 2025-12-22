#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/stat.h>

void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

// Validate map: only '.', 'X', '\n' allowed, all lines same width
bool	validate_map(char *map, int size, int *width)
{
	int i = 0;
	int line_len = 0;

	while (i < size)
	{
		if (map[i] != '.' && map[i] != 'X' && map[i] != '\n')
			return false;
		if (map[i] == '\n')
		{
			if (*width == 0)
				*width = line_len;
			else if (line_len != *width)
				return false;
			line_len = 0;
		}
		else
			line_len++;
		i++;
	}
	// Must end with newline (line_len should be 0)
	if (line_len != 0 || *width <= 0)
		return false;
	return true;
}

// Flood fill: mark visited by changing 'X' to '.'
// Returns island size
int	flood_fill(char *map, int idx, int width, int size)
{
	if (idx < 0 || idx >= size || map[idx] != 'X')
		return (0);
	map[idx] = '.';
	return (1 +
		flood_fill(map, idx + 1, width, size) +           // Right
		flood_fill(map, idx - 1, width, size) +           // Left
		flood_fill(map, idx + width + 1, width, size) +   // Down (+1 for '\n')
		flood_fill(map, idx - width - 1, width, size));   // Up
}

int	main(int argc, char **argv)
{
	int			fd;
	struct stat	st;
	char		*file_data;
	char		*map;
	int			width = 0;
	int			largest = 0;
	int			i;

	if (argc != 2)
		return (write(1, "\n", 1), 1);

	// Open file
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "\n", 1), 1);

	// Get file size with fstat
	if (fstat(fd, &st) < 0 || st.st_size == 0)
		return (close(fd), write(1, "\n", 1), 1);

	// Map file into memory
	file_data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	close(fd);
	if (file_data == MAP_FAILED)
		return (write(1, "\n", 1), 1);

	// Copy to writable buffer (mmap is read-only, we need to modify for flood-fill)
	map = malloc(st.st_size);
	if (!map)
		return (munmap(file_data, st.st_size), write(1, "\n", 1), 1);
	i = 0;
	while (i < st.st_size)
	{
		map[i] = file_data[i];
		i++;
	}
	munmap(file_data, st.st_size);

	// Validate
	if (!validate_map(map, st.st_size, &width))
		return (free(map), write(1, "\n", 1), 1);

	// Find largest island
	i = 0;
	while (i < st.st_size)
	{
		if (map[i] == 'X')
		{
			int size = flood_fill(map, i, width, st.st_size);
			if (size > largest)
				largest = size;
		}
		i++;
	}

	ft_putnbr(largest);
	write(1, "\n", 1);
	free(map);
	return (0);
}
