#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Step 1: Initialize board
char **init_board(int width, int height) {
    char **board = malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        board[i] = calloc(width, 1); // zeros = dead cells
    }
    return board;
}

// Step 2: Process drawing commands
void process_commands(char **board, int width, int height) {
    int x = 0, y = 0;           // pen position (start top-left)
    bool drawing = false;        // pen lifted initially
    char cmd;
    
    while ((read(0, &cmd, 1)) > 0) {
        if (cmd == 'x') 
		{
            drawing = !drawing;   // toggle pen
            if (drawing) 
				board[y][x] = '1';
        }
        else if (cmd == 'w' && y > 0) 
			y--; // up
        else if (cmd == 'a' && x > 0) 
			x--; // left
        else if (cmd == 's' && y < height - 1)
			y++; // down
        else if (cmd == 'd' && x < width - 1)
			x++; // right

        if (drawing && cmd != 'x')
			board[y][x] = '1';  // draw at new position (but not when toggling)
    }
}

// Step 3: Count neighbors (key helper function)
int count_neighbors(char **board, int width, int height, int x, int y) {
    int count = 0;
    
    for (int dy = -1; dy <= 1; dy++) 
	{
        for (int dx = -1; dx <= 1; dx++) 
		{
            if (dx == 0 && dy == 0) 
				continue;  // skip center cell        
            int nx = x + dx;
            int ny = y + dy;
            // bounds check - out of bounds = dead
            if (nx >= 0 && nx < width && ny >= 0 && ny < height)
                if (board[ny][nx] == '1')
                    count++;
        }
    }
    return count;
}

// Step 4: Simulate one iteration
void simulate(char **board, int width, int height) {
    char **next = init_board(width, height);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = count_neighbors(board, width, height, x, y);
            
            // Game of Life rules (memorize these!)
            if (board[y][x] == '1') {
                // Live cell
                if (neighbors == 2 || neighbors == 3)
                    next[y][x] = '1';  // survives
                // else dies (already 0)
            } else {
                // Dead cell
                if (neighbors == 3)
                    next[y][x] = '1';  // becomes alive
            }
        }
    }
    
    // Copy next back to board
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++)
            board[y][x] = next[y][x];
        free(next[y]);
    }
    free(next);
}

// Step 5: Print board
void print_board(char **board, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (board[y][x] == '1')
                write(1, "0", 1);  // alive = '0' character
            else
                write(1, " ", 1);  // dead = space
        }
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) return 1;
    
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    
    char **board = init_board(width, height);
    
    process_commands(board, width, height);
    
    for (int i = 0; i < iterations; i++)
        simulate(board, width, height);
    
    print_board(board, width, height);
    
    // Free memory
    for (int i = 0; i < height; i++)
        free(board[i]);
    free(board);
    
    return 0;
}