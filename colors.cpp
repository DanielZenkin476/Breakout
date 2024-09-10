
#include <colors.h>
// Struct color = {R,G,B,alpha} - 0-255 values, alpha is transparancy

const Color darkGrey = { 26, 31, 40, 255 };
const Color green = { 47, 230, 23, 255 };
const Color red = { 232, 18, 18, 255 };
const Color orange = { 226, 116, 17, 255 };
const Color yellow = { 237, 234, 4, 255 };
const Color purple = { 166, 0, 247, 255 };
const Color cyan = { 21, 204, 209, 255 };
const Color blue = { 13, 64, 216, 255 };
const Color darkBlue = { 50,50,127,255 };
const Color Blue = { 20,20,180,255 };
const Color lightBlue = { 20,20,120,150 };
const Color white = { 255,255,255,255 };
const Color black = { 0, 0, 0,  255 };

std::vector<Color> GetCellcolors() {// function returns all colors as a vector of colors
	return{ red, orange, yellow, green, cyan, blue, purple ,darkBlue,darkGrey ,black, white, lightBlue };
}