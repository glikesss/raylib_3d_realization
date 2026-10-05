//#include "imath.h"
#include "../raylib/raylib.h"
#include <math.h>
#include "ivector.h"


Vector2 Vector2MatrixMult(Vector2 vec, const Vector2 matrix[2]) {
    Vector2 vector = vec;
    vec.x = DotProd(vector, matrix[0]);
    vec.y = DotProd(vector, matrix[1]);
    return vec;
}


Vector3 Vector3MatrixMult(Vector3 vec, const Vector3 matrix[3]) {
    Vector3 vector = vec;
    vec.x = DotProd(vector, matrix[0]);
    vec.y = DotProd(vector, matrix[1]);
    vec.z = DotProd(vector, matrix[2]);
    return vec;
}


Vector4 Vector4MatrixMult(Vector4 vec, const Vector4 matrix[4]) {
    Vector4 vector = vec;
    vec.x = DotProd(vector, matrix[0]);
    vec.y = DotProd(vector, matrix[1]);
    vec.z = DotProd(vector, matrix[2]);
    vec.w = DotProd(vector, matrix[3]);
    return vec;
}


void RotateVector3(Vector3 *vec, Vector3 point, float angle_x, float angle_y, float angle_z) {
    *vec = SubVector(*vec, point);
    
    Vector3 matrix_x[] = {
        MVector3(1,             0,            0),
        MVector3(0,  cos(angle_x), sin(angle_x)),
        MVector3(0, -sin(angle_x), cos(angle_x)),
    };
    
    Vector3 matrix_y[] = {
        MVector3(cos(angle_y), 0, -sin(angle_y)),
        MVector3(0,            1,             0),
        MVector3(sin(angle_y), 0,  cos(angle_y)),
    };
    
    Vector3 matrix_z[] = {
        MVector3( cos(angle_z), sin(angle_z), 0),
        MVector3(-sin(angle_z), cos(angle_z), 0),
        MVector3(0,          0,               1),
    };
    

    *vec = Vector3MatrixMult(*vec, matrix_x);
    *vec = Vector3MatrixMult(*vec, matrix_y);
    *vec = Vector3MatrixMult(*vec, matrix_z);

    *vec = AddVector3(*vec, point);
}
