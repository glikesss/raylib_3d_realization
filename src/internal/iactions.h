#ifndef IACTIONS_H
#define IACTIONS_H

#import "../raylib/raylib.h"
#import "iobjects.h"

typedef enum{
    ACTION_NONE                 = 0,

    ACTION_MOVE_POINT_3D        = 1,
    ACTION_MOVE_LINE_3D         = 2,
    ACTION_DELETE               = 3,
    ACTION_CREATE               = 4,
    ACTION_COPY                 = 5,
    ACTION_CUT                  = 6,
    ACTION_PASTE                = 7,
    ACTION_ROTATE_X_AXIS_3D_CV  = 8, 
    ACTION_ROTATE_X_AXIS_3D_CCV = 9,
    ACTION_ROTATE_Y_AXIS_3D_CV  = 10,
    ACTION_ROTATE_Y_AXIS_3D_CCV = 11,
    ACTION_ROTATE_Z_AXIS_3D_CV  = 12,
    ACTION_ROTATE_Z_AXIS_3D_CCV = 13,
} Action;

void MovePoint3D(Point3D *point, Vector3 new_pos);
void MoveLine3D(Point3D *point1, Point3D *point2, Vector3 new_pos);

#endif
