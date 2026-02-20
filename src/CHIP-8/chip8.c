#include <stdio.h>
#include "chip8.h"
#include "../utils.h"


void tick(Chip8 *machine)
{
	uint16_t opcode = machine->ram[machine->pc];
	opcode = (opcode << 8) + machine->ram[machine->pc + 1];
	
	switch (NIBBLE_1(opcode))
	{
		case 0x0:
			switch (opcode)
			{
				case 0x00E0:
					clear(machine);
					break;

				case 0x00EE:
					ret(machine);
					break;
			}

			break;
		
		case 0x1:
			jump(machine, C8_ADDRESS(opcode));
			break;
		
		case 0x2:
			call(machine, C8_ADDRESS(opcode));
			break;
		
		case 0x3:
			skipN(machine, NIBBLE_2(opcode), LO_BYTE(opcode), false);
			break;
		
		case 0x4:
			skipN(machine, NIBBLE_2(opcode), LO_BYTE(opcode), true);
			break;
		
		case 0x5:
			skipV(machine, NIBBLE_2(opcode), NIBBLE_3(opcode), false);
			break;
		
		case 0x6:
			loadV(machine, NIBBLE_2(opcode), LO_BYTE(opcode));
			break;
		
		case 0x7:
			addNV(machine, NIBBLE_2(opcode), LO_BYTE(opcode));
			break;
		
		case 0x8:
			arithmetic(machine, NIBBLE_2(opcode), NIBBLE_3(opcode), NIBBLE_4(opcode));
			break;
		
		case 0x9:
			skipV(machine, NIBBLE_2(opcode), NIBBLE_3(opcode), true);
			break;

		case 0xA:
			loadI(machine, C8_ADDRESS(opcode));
			break;

		case 0xD:
			draw(machine, NIBBLE_2(opcode), NIBBLE_3(opcode), NIBBLE_4(opcode));
			break;
		
		case 0xF:
			switch (LO_BYTE(opcode))
			{
				case 0x1E:
					addI(machine, NIBBLE_2(opcode));
					break;

				case 0x33:
					bcd(machine, NIBBLE_2(opcode));
					break;

				case 0x55:
					storeMem(machine, NIBBLE_2(opcode));
					break;

				case 0x65:
					loadMem(machine, NIBBLE_2(opcode));
					break;
			}

			break;

		default:
			printf("Unimplemented Instruction\n"); // Unimplemented	
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

void push(Chip8 *machine, uint16_t addr)
{
	machine->stack[machine->stack_top] = addr;
	machine->stack_top++;
}

uint16_t pop(Chip8 *machine)
{
	machine->stack_top--;
	return machine->stack[machine->stack_top];
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