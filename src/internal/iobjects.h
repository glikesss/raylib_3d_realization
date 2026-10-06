#ifndef IOBJECTS_H
#define IOBJECTS_H

#include "../raylib/raylib.h"
#include "imath.h"
#include "ivector.h"



typedef struct{
    Vector3 position;
    Color default_color;
    bool is_hovered;
    Color on_hover_color;
    bool is_active;
    Color active_color;
    Color color;
    float radius;
    
} Point3D;

Point3D MPoint3DV(Vector3 position,  float radius, Color default_color, Color on_hover_color, Color active_color); 

Point3D MPoint3D(float x, float y, float z, float radius, Color default_color, Color on_hover_color, Color active_color);

#endif
