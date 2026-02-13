#include <stdint.h>
#include <math.h>
#include "chip8.h"


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

