#include <stdarg.h>
#include "iactions.h"
#include "iobjects.h"



void DoAction(int count, Action action, ...){
    va_list args;
    va_start(args, action);

    switch(action){

    case(ACTION_NONE                ): break; 
    case(ACTION_MOVE_POINT_3D       ): MovePoint3D(va_arg(args, Point3D*), va_arg(args, Vector3)); break;
    case(ACTION_MOVE_LINE_3D        ): MoveLine3D(va_arg(args, Point3D*), va_arg(args, Point3D*), va_arg(args, Vector3)); break;
    case(ACTION_DELETE              ):
    case(ACTION_CREATE              ):
    case(ACTION_COPY                ):
    case(ACTION_CUT                 ):
    case(ACTION_PASTE               ):
    case(ACTION_ROTATE_X_AXIS_3D_CV ):
    case(ACTION_ROTATE_X_AXIS_3D_CCV):
    case(ACTION_ROTATE_Y_AXIS_3D_CV ):
    case(ACTION_ROTATE_Y_AXIS_3D_CCV):
    case(ACTION_ROTATE_Z_AXIS_3D_CV ):
    case(ACTION_ROTATE_Z_AXIS_3D_CCV):
    }

    va_end(args);
}
