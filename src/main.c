#include "raylib.h"
#include "CHIP-8/chip8.h"


int main() {
	int res_mul = 20;
	Color off_color = {0x92, 0x68, 0x1A, 0xFF};
	Color on_color = {0xF5, 0xCE, 0x3A, 0xFF};
	InitWindow(64 * res_mul, 32 * res_mul, "CHIPPIE");

	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(off_color);
		DrawText("CHIPPIE is back!", 0, 0, 50, on_color);
		EndDrawing();
	}
}