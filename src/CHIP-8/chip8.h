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


/* Machine functions */

// Loads a rom from a file
void loadrom(Chip8 *machine, char *filename);

// Runs a machine for a cycle
void tick(Chip8 *machine);


/* Opcode functions */

// Clear screen (00E0)
void clear();

// Jump pc to memory location (1NNN)
void jump(uint16_t dest);

// Loads a register with a value (6XNN)
void loadv(uint8_t reg, uint8_t value); 

// Loads index register with a value (ANNN)
void loadi(uint16_t value);

// Draws a sprite to the screen (DXYN)
void draw(uint8_t reg1, uint8_t reg2, uint8_t height);
