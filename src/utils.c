#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"


bool getBit(uint8_t byte, uint8_t bit)
{
	return (uint8_t) pow(2, ( bit - 7 )) >> (uint8_t) pow(2, ( bit - 7 ) - 1);
}