# get_next_line 

## Description

In this project, we had to create a function called `get_next_line` that returns a line, which is read from a file descriptor (`fd`).

## Function
`get_next_line` must be able to allow reading a text file pointed to by the file descriptor, one line at a time.

### Return value
The line that was read.

If there is nothing else to read or an error occurs, the function should return `NULL`.
The returned line should include the terminating `\n` character. In cases where the line reaches the End of Line (EOF), it should not terminate using the `/n` character.

## Bonus :star:
The bonus included that we use a one `static variable` only. It should also be possible to handle multiple `fd`.

## Installation:
1. Clone the repository or get the source code files;
2. Create a .txt file and write some variants in there, or use the files provided in the directory;
3. Compile the program using the following command: `cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c`
4. If you want to try to bonus, compile the bonus files instead! `cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main.c`
