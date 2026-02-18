#include <stdint.h>
#include <stdbool.h>


/* Byte manipulation macro functions */

#define HI_NIBBLE(b) (((b) >> 4) & 0x0F) // Gets the most significant nibble of a byte
#define LO_NIBBLE(b) ((b) & 0x0F)        // Gets the least significant nibble of a byte

#define HI_BYTE(b) (((b) >> 8) & 0xFF) // Gets the most significant byte of a byte pair (uint16_t or C8 memory address)
#define LO_BYTE(b) ((b) & 0xFF)        // Gets the least significant byte of a byte pair (also a uint16_t or C8 memory address)

#define NIBBLE_1(b) HI_NIBBLE(HI_BYTE(b)) // Gets the first nibble of a uint16_t (most significant)
#define NIBBLE_2(b) LO_NIBBLE(HI_BYTE(b)) // Gets the second nibble of a uint16_t
#define NIBBLE_3(b) HI_NIBBLE(LO_BYTE(b)) // Gets the third nibble of a uint16_t
#define NIBBLE_4(b) LO_NIBBLE(LO_BYTE(b)) // Gets the last nibble of a uint16_t (least significant)

#define C8_ADDRESS(b) ( b & 0xFFF ) // Removes the most significant nibble from a byte pair


/* Normal utils */

// Get a bit from a byte and return as a bool
// 0 gets the least significant, while 7 gets the most significant
bool getBit(uint8_t byte, uint8_t bit);