#include "../raylib/raylib.h"

void RotateVector3(Vector3 *vec, Vector3 point, float angle_x, float angle_y, float angle_z);

Vector2 Vector2MatrixMult(Vector2 vec, const Vector2 matrix[2]);          
Vector3 Vector3MatrixMult(Vector3 vec, const Vector3 matrix[3]);
Vector4 Vector4MatrixMult(Vector4 vec, const Vector4 matrix[4]);

#define VectorMatrixMul(vec, matr)       \
    _Generic((vec),                      \
             Vector2: Vector2MatrixMult, \
             Vector3: Vector3MatrixMult, \
             Vector4: Vector4MatrixMult  \
            )(vec, matr)


