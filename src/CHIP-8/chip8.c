#include <stdio.h>
#include "chip8.h"


void setupMachine(Chip8 *machine)
{
	// Clear ram
	for(int i = 0; i < 4096; i++)
	{
		machine->ram[i] = 0;
	}

	// Clear display
	for(int i = 0; i < 64*32; i++)
	{
		machine->display[i] = 0;
	}

	// Clear stack
	for(int i = 0; i < 100; i++)
	{
		machine->stack[i] = 0;
	}

	// Clear registers
	for(int i = 0; i < 16; i++)
	{
		machine->registers[i] = 0;
	}

	// Clear all other important variables
	machine->pc          = 0x200; // The program counter should start at 0x200
	machine->i           = 0;
	machine->delay_timer = 0;
	machine->sound_timer = 0;
}

bool loadRom(Chip8 *machine, char *filename)
{
	// Open file
	FILE* rom;
	rom = fopen(filename, "rb");

	// If something goes wrong, stop
	if(rom == NULL)
	{
		return false;
	}

	// Read the rom into machine memory
	fread(&machine->ram[0x200], 1, 4096 - 0x200, rom);


	// Close and return true
	fclose(rom);
	return true;
}