#include <stdio.h>
#include <string.h>
#include "chip8.h"
#include "raylib.h"


bool dumpMachine(Chip8 *machine, char *filename)
{
	// Create file
	FILE* dump;
	dump = fopen(filename, "wb");

	// If something goes wrong, stop
	if(dump == NULL)
	{
		return false;
	}

	// Write everything into the file
	fwrite(machine, sizeof(*machine), 1, dump);

	// Close and return true
	fclose(dump);
	return true;
}

void drawDebugInfo(Chip8 *machine)
{
	char dbg_text[200] = {0};
	char cat[20] = {0};


	uint16_t opcode = machine->ram[machine->pc];
	opcode = (opcode << 8) + machine->ram[machine->pc + 1];

	sprintf(dbg_text, "instr = %#4X\n", opcode);

	sprintf(cat,      "pc = %#3X\n", machine->pc);
	strcat(dbg_text, cat);

	sprintf(cat,      "i = %#3X\n", machine->i);
	strcat(dbg_text, cat);

	for(int i = 0; i < 16; i++)
	{
		sprintf(cat,      "V%2d = %#2X\n", i, machine->registers[i]);
		strcat(dbg_text, cat);
	}
	
	
	DrawText(
		dbg_text,
		0, 0,
		20,
		WHITE
	);
}