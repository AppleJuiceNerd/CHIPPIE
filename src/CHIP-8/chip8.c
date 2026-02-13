#include <stdio.h>
#include "chip8.h"


bool loadrom(Chip8 *machine, char *filename) {
	// Open file
	FILE* rom;
	rom = fopen(filename, "rb");

	// If something goes wrong, stop
	if(rom == NULL) {
		return false;
	}

	// Read the rom into machine memory
	fread(&machine->ram[0x200], 1, 4096 - 0x200, rom);


	// Close and return true
	fclose(rom);
	return true;
}