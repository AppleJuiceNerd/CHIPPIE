#include <stdbool.h>
#include <stdint.h>


// Struct representation of a CHIP-8 machine
typedef struct _Chip8
{
	uint8_t  ram[4096];        // 4 KB of memory
	bool     display[64 * 32]; // 64 x 32 monochrome display
	uint16_t pc;               // Program counter
	uint16_t i;                // Index register
	uint16_t stack[24];        // Stack (limited; unsure what a good cap would be)
	uint8_t  delay_timer;      // Delay Timer
	uint8_t  sound_timer;      // Sound Timer
	uint8_t  registers[16];    // All 16 variable registers
} Chip8;


/* Machine functions */

// Sets up the machine by setting all values to zero
void setupMachine(Chip8 *machine);

// Loads a rom from a file, returns false if unsuccessful
bool loadRom(Chip8 *machine, char *filename);

// Runs a machine for a cycle
void tick(Chip8 *machine);

// Gets a display index based on a position
int positionToDisplay(int x, int y);


/* Opcode functions */

// Clear screen (00E0)
void clear(Chip8 *machine);

// Jump pc to memory location (1NNN)
void jump(Chip8 *machine, uint16_t dest);

// Loads a register with a value (6XNN)
void loadV(Chip8 *machine, uint8_t reg, uint8_t value); 

// Loads index register with a value (ANNN)
void loadI(Chip8 *machine, uint16_t value);

// Draws a sprite to the screen (DXYN)
void draw(Chip8 *machine, uint8_t reg1, uint8_t reg2, uint8_t height);


/* Debug functions */

// Dumps all of the memory used by the machine to a file
// Returns false if unsuccessful
bool dumpMachine(Chip8* machine, char* filename);