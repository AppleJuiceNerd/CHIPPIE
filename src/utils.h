#include <stdint.h>
#include <stdbool.h>


// Get a bit from a byte and return as a bool
// 0 gets the least significant, while 7 gets the most significant
bool getBit(uint8_t byte, uint8_t bit);