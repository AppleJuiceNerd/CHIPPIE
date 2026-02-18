#include "utils.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

bool getBit(uint8_t byte, uint8_t bit)
{
	// Generate a mask
	uint8_t mask = (uint8_t) pow(2, bit);
	
	// Return masked and shifted value
	return (byte & mask) >> ( bit );
}