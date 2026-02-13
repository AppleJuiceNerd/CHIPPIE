#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"


bool getBit(uint8_t byte, uint8_t bit)
{
	// Generate a mask
	uint8_t mask = (uint8_t) pow(2, bit) >> (uint8_t) pow(2, bit - 1);
	
	// Return masked and shifted value
	return (byte & mask) >> bit;
}