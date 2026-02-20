#include <iso646.h>
#include <stdint.h>
#include "chip8.h"
#include "../utils.h"


void clear(Chip8 *machine)
{
	for(int y = 0; y < 32; y++)
	{
		for(int x = 0; x < 64; x++)
		{
			machine->display[y][x] = 0;
		}
	}
}

void ret(Chip8 *machine)
{
	jump(machine, pop(machine));
	machine->pc += 2; // Prevent program counter from returning to the same instruction
}

void jump(Chip8 *machine, uint16_t dest)
{
	machine->pc = dest;
	machine->pc -= 2; // Decrement program counter to prevent incorrect jumps
}

void call(Chip8 *machine, uint16_t dest)
{
	push(machine, machine->pc);
	jump(machine, dest);
}

void skipN(Chip8 *machine, uint8_t reg, uint8_t value, bool _not)
{
	// NOTE: Maybe find a better way to do this
	if(!_not)
	{
		// 3XNN
		if(machine->registers[reg] == value)
		{
			machine->pc += 2;
		}
	} else
	{
		// 4XNN
		if(machine->registers[reg] != value)
		{
			machine->pc += 2;
		}
	}
}

void skipV(Chip8 *machine, uint8_t reg1, uint8_t reg2, bool _not)
{
	// NOTE: Maybe find a better way to do this
	if(!_not)
	{
		// 5XY0
		if(machine->registers[reg1] == machine->registers[reg2])
		{
			machine->pc += 2;
		}
	} else
	{
		// 9XY0
		if(machine->registers[reg1] != machine->registers[reg2])
		{
			machine->pc += 2;
		}
	}
}

void loadV(Chip8 *machine, uint8_t reg, uint8_t value)
{
	machine->registers[reg] = value;
}

void addNV(Chip8 *machine, uint8_t reg, uint8_t value)
{
	machine->registers[reg] += value;
}

void arithmetic(Chip8 *machine, uint8_t reg1, uint8_t reg2, uint8_t operation)
{
	switch (operation)
	{
		// VX = VY (8XY0)
		case 0x0:
			machine->registers[reg1] = machine->registers[reg2];
			break;
		
		// VX |= VY (8XY0)
		case 0x1:
			machine->registers[reg1] |= machine->registers[reg2];
			break;
	}
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
			if(machine->display[y + row][x + col] && bit)
			{
				machine->display[y + row][x + col] = 0;
				machine->registers[0xF] = 1;
			}
			else if(bit)
			{
				machine->display[y + row][x + col] = 1;	
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