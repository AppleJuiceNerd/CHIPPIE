#include <stdio.h>
#include "chip8.h"


// int positionToDisplay(int x, int y)
// {
// 	return x + (y * 32);
// }

void tick(Chip8 *machine)
{
	uint16_t opcode = machine->ram[machine->pc];
	opcode = (opcode << 8) + machine->ram[machine->pc + 1];
	
	switch (opcode >> 12)
	{
		case 0x0:
			switch (opcode)
			{
				case 0x00E0:
					clear(machine);
			}

			break;
		
		case 0x1:
			jump(machine, opcode & 0xF);
			break;
		
		case 0x6:
			loadV(machine, (opcode >> 8) & 0xF, opcode & 0xFF);
			break;

		case 0xA:
			loadI(machine, opcode & 0xFFF);
			break;

		case 0xD:
			draw(machine, (opcode >> 8) & 0xF, (opcode >> 4) & 0xF, opcode & 0xF);
			break;

		default:
			; // Unimplemented	
	}

	// Increment program counter
	machine->pc += 2;
}


void setupMachine(Chip8 *machine)
{
	// Clear ram
	for(int i = 0; i < 4096; i++)
	{
		machine->ram[i] = 0;
	}

	// Clear display
	clear(machine);

	// Clear stack
	for(int i = 0; i < 24; i++)
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