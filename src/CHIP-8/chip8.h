#include <limits.h>
#include <stdbool.h>
#include <stdint.h>


// Struct representation of a CHIP-8 machine
typedef struct _Chip8
{
	uint8_t  ram[4096];        // 4 KB of memory
	bool     display[32][64];  // 64 x 32 monochrome display
	uint16_t pc;               // Program counter
	uint16_t i;                // Index register
	uint16_t stack[24];        // Stack (limited; unsure what a good cap would be)
	uint8_t stack_top;         // An index value that points to the top of the stack; first index is 1
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

// Pushes an address to the stack
void push(Chip8 *machine, uint16_t addr);

// Pops an address from the top of the stack and returns it
// The address won't be deleted, the top of the stack will just be redefined
uint16_t pop(Chip8 *machine);


/* Opcode functions */

// Clear screen (00E0)
void clear(Chip8 *machine);

// Return from subroutine (00EE)
void ret(Chip8 *machine);

// Jump pc to memory location (1NNN)
void jump(Chip8 *machine, uint16_t dest);

// Call subroutine
void call(Chip8 *machine, uint16_t dest);

// Skip if VX is or is not equal to NN, depending on the instruction (3XNN & 4XNN)
void skipN(Chip8 *machine, uint8_t reg, uint8_t value, bool not);

// Skip if VX is or is not equal to VY, depending on the instruction (5XY0 & 9XY0)
void skipV(Chip8 *machine, uint8_t reg1, uint8_t reg2, bool not);

// Loads a register with a value (6XNN)
void loadV(Chip8 *machine, uint8_t reg, uint8_t value); 

// Adds a value to a register (7XNN)
void addNV(Chip8 *machine, uint8_t reg, uint8_t value);

// Loads index register with a value (ANNN)
void loadI(Chip8 *machine, uint16_t value);

// Draws a sprite to the screen (DXYN)
void draw(Chip8 *machine, uint8_t reg1, uint8_t reg2, uint8_t height);


/* Debug functions */

// Dumps all of the memory used by the machine to a file
// Returns false if unsuccessful
bool dumpMachine(Chip8* machine, char* filename);

// Shows debug info on-screen
// should be called inside the draw loop
void drawDebugInfo(Chip8 *machine);