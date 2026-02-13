#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "CHIP-8/chip8.h"


int main(int argc, char** argv) {
	// Try to load the rom first.
	// If it can't be found, then we shouldn't initialize the window.
	Chip8 machine;

	setupMachine(&machine);

	if(!loadRom(&machine, argv[1]))
	{
		printf("Something went wrong.\n");
		exit(1);
	}


	int res_mul = 20;
	Color off_color = {0x92, 0x68, 0x1A, 0xFF};
	Color on_color = {0xF5, 0xCE, 0x3A, 0xFF};
	InitWindow(64 * res_mul, 32 * res_mul, "CHIPPIE");


	while(!WindowShouldClose())
	{
		tick(&machine);

		BeginDrawing();
		ClearBackground(off_color);
		
		for(int y = 0; y < 32; y++)
		{
			for(int x = 0; x < 64; x++)
			{
				if(machine.display[positionToDisplay(x, y)])
				{
					DrawRectangle(x, y, res_mul, res_mul, on_color);
				}
			}
		}

		EndDrawing();
	}

	return 0;
}