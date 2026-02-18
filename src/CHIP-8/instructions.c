#include <stdint.h>
#include "chip8.h"
#include "../utils.h"


void clear(Chip8 *machine)
{
	for(int i = 0; i < 64*32; i++)
	{
		machine->display[i] = 0;
	}
}

void jump(Chip8 *machine, uint16_t dest)
{
	machine->pc = dest;
}

void loadV(Chip8 *machine, uint8_t reg, uint8_t value)
{
	machine->registers[reg] = value;
}

void loadI(Chip8 *machine, uint16_t value)
{
	machine->i = value;
}

void draw(Chip8 *machine, uint8_t reg1, uint8_t reg2, uint8_t height)
{
	// Sprite draw position
	uint8_t x = machine->registers[reg1];
	uint8_t y = machine->registers[reg2];


	// Make sure that where the sprite starts drawing is on the screen
	x %= 64;
	y %= 32;

	// Set VF to 0
	machine->registers[0xF] = 0;

	// Current byte being used in the loop
	uint8_t data = 0;
	
	// Current bit being used in the loop
	int bit = 0; 

	// Loop through each row of the sprite
	for(int row = 0; row < height; row++)
	{
		// Take a byte
		data = machine->ram[machine->i + row];

		// Loop through each bit in the byte
		for(int col = 0; col < 8; col++)
		{
			// Take a bit(e)
			bit = getBit(data, 7 - col);
			
			// If both the sprite and display pixels are on, turn the display pixel off
			if(machine->display[positionToDisplay(x + col, y + row)] && bit)
			{
				machine->display[positionToDisplay(x + col, y + row)] = 0;
				machine->registers[0xF] = 1;
			}
			else if(bit)
			{
				machine->display[positionToDisplay(x + col, y + row)] = 1;	
			}
			
			if(x + col == 64)
			{
				break;
			}
		}

		if(y + row == 32)
		{
			break;
		}
	}
}