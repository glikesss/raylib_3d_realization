#include "../raylib/raylib.h"
#include "./imath.h"
#include <math.h>

Vector2 PosToScreen(Vector3 position, float distance_to_screen, char is_rounded) {
    Vector2 screen_position;
  
    if (is_rounded){
        screen_position.x = (int)((distance_to_screen / (position.z + distance_to_screen)) * position.x);
        screen_position.y = (int)((distance_to_screen / (position.z + distance_to_screen)) * position.y);
    } else {
        screen_position.x = (distance_to_screen / (position.z + distance_to_screen)) * position.x;
        screen_position.y = (distance_to_screen / (position.z + distance_to_screen)) * position.y;
    }
    return screen_position;
}

float MinF(float a, float b){
    if (a > b)
        return b;
    else
        return a;
}
