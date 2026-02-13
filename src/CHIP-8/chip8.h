#include <stdbool.h>
#include <stdint.h>


// Struct representation of a CHIP-8 machine
typedef struct _Chip8 {
	uint8_t  ram[4096];        // 4 KB of memory
	bool     display[64 * 32]; // 64 x 32 monochrome display
	uint16_t pc;               // Program counter
	uint16_t i;                // Index register
	uint16_t stack[100];       // Stack (limited; unsure what a good cap would be)
	uint8_t  delay_timer;      // Delay Timer
	uint8_t  sound_timer;      // Sound Timer
	uint8_t  registers[16];    // All 16 variable registers
} Chip8;
