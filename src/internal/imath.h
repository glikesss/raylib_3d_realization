#ifndef IMATH_H
#define IMATH_H


#include "../raylib/raylib.h"



#ifndef CALC_H
#define CALC_H
#endif


Vector2 PosToScreen(Vector3 position, float distance_to_screen, char is_rounded);
float MinF(float a, float b);

#endif
