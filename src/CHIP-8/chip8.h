#include <stdbool.h>
#include <stdint.h>


// Struct representation of a CHIP-8 machine
typedef struct _Chip8 {
	unsigned char ram[4096];     // 4 KB of memory
	bool display[64 * 32];       // 64 x 32 monochrome display
	unsigned int pc;             // Program counter
	uint16_t stack[100];         // Stack (limited; unsure what a good cap would be)
	unsigned char delay_timer;   // Delay Timer
	unsigned char sound_timer;   // Sound Timer
	unsigned char registers[16]; // All 16 variable registers
} Chip8;