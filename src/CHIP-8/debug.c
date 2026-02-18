#include <stdio.h>
#include "chip8.h"


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