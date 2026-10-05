#include "../raylib/raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



char *int_to_string(int n)
{
    char *s = malloc(32);
    snprintf(s, 32, "%d", n);
    return s;
}

char *uint_to_string(unsigned int n)
{
    char *s = malloc(32);
    snprintf(s, 32, "%u", n);
    return s;
}

char *long_to_string(long n)
{
    char *s = malloc(32);
    snprintf(s, 32, "%ld", n);
    return s;
}

char *ulong_to_string(unsigned long n)
{
    char *s = malloc(32);
    snprintf(s, 32, "%lu", n);
    return s;
}

char *float_to_string(float n)
{
    char *s = malloc(64);
    snprintf(s, 64, "%g", n);
    return s;
}

char *double_to_string(double n)
{
    char *s = malloc(64);
    snprintf(s, 64, "%g", n);
    return s;
}

char *vector2_to_string(Vector2 vector) {
    int size = 30 * sizeof(char);
    char* str = malloc(size);
    snprintf(str, size, "(%g, %g)", vector.x, vector.y);
    return str;
}
char *vector3_to_string(Vector3 vector) {
    int size = 40 * sizeof(char);
    char* str = malloc(size);
    snprintf(str, size, "(%g, %g, %g)", vector.x, vector.y, vector.z);    
    return str;
}
char *vector4_to_string(Vector4 vector) {
    int size = 50 * sizeof(char);
    char* str = malloc(size);
    snprintf(str, size, "(%g, %g, %g, %g)", vector.x, vector.y, vector.z, vector.w );
    return str;
}

// Vector Operations
// Vector2
Vector2 AddVector2(Vector2 vec1, Vector2 vec2) {

  Vector2 res;
  res.x = vec1.x + vec2.x;
  res.y = vec1.y + vec2.y;
  return res;
}

Vector2 SubVector2(Vector2 vec1, Vector2 vec2) {
    Vector2 res;
    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;

    return res;
}

Vector2 MulVector2(Vector2 vec, float n) {
    Vector2 vector = vec;
    vector.x *= n;
    vector.y *= n;
    return vector;
}


float DotProdVector2(Vector2 vec1, Vector2 vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

float LengthVector2(Vector2 vec){
    return DotProdVector2(vec, vec);
}

Vector2 MVector2(float x, float y) {
    Vector2 var;
    var.x = x;
    var.y = y;
    
    return var;
}


Vector2 NormalizeVector2(Vector2 vec) {
    float length = sqrtf(LengthVector2(vec));

    if (length == 0.0f)
        return MVector2(0, 0);

    return MVector2(
           vec.x / length,
           vec.y / length
           );
}



// Vector3
Vector3 AddVector3(Vector3 vec1, Vector3 vec2) {

  Vector3 res;
  res.x = vec1.x + vec2.x;
  res.y = vec1.y + vec2.y;
  res.z = vec1.z + vec2.z;

  return res;
}

Vector3 SubVector3(Vector3 vec1, Vector3 vec2) {
    Vector3 res;
    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;
    res.z = vec1.z - vec2.z;

    return res;
}

Vector3 MulVector3(Vector3 vec, float n) {
    Vector3 vector = vec;
    vector.x *= n;
    vector.y *= n;
    vector.z *= n;
    return vector;
}


float DotProdVector3(Vector3 vec1, Vector3 vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}


float LengthVector3(Vector3 vec){
    return DotProdVector3(vec, vec);
}

Vector3 MVector3(float x, float y, float z) {
    Vector3 var;
    var.x = x;
    var.y = y;
    var.z = z;
    
    return var;
}

Vector3 NormalizeVector3(Vector3 vec) {
    float length = sqrtf(LengthVector3(vec));

    if (length == 0.0f)
        return MVector3(0, 0, 0);

    return MVector3(
           vec.x / length,
           vec.y / length,
           vec.z / length
           );
}


Vector3 CrossProdVector3(Vector3 vec1, Vector3 vec2) {
    return MVector3(
           vec1.y * vec2.z - vec1.z * vec2.y,
           vec1.z * vec2.x - vec1.x * vec2.z,
           vec1.x * vec2.y - vec1.y * vec2.x
           );
}


// Vector4
Vector4 AddVector4(Vector4 vec1, Vector4 vec2) {
    Vector4 res;
    res.x = vec1.x + vec2.x;
    res.y = vec1.y + vec2.y;
    res.z = vec1.z + vec2.z;
    res.w = vec1.w + vec2.w;
    
    return res;
}

Vector4 SubVector4(Vector4 vec1, Vector4 vec2) {
    Vector4 res;
    res.x = vec1.x - vec2.x;
    res.y = vec1.y - vec2.y;
    res.z = vec1.z - vec2.z;
    res.w = vec1.w - vec2.w;
    
    return res;
}

Vector4 MulVector4(Vector4 vec, float n) {
    Vector4 vector = vec;
    vector.x *= n;
    vector.y *= n;
    vector.z *= n;
    vector.w *= n;
    return vector;
}


float DotProdVector4(Vector4 vec1, Vector4 vec2) {
    return
        vec1.x * vec2.x +
        vec1.y * vec2.y +
        vec1.z * vec2.z +
        vec1.w * vec2.w;
}


float LengthVector4(Vector4 vec){
    return DotProdVector4(vec, vec);
}

Vector4 MVector4(float x, float y, float z, float w) {
    Vector4 var;
    var.x = x;
    var.y = y;
    var.z = z;
    var.w = w;
    
    return var;
}


Vector4 NormalizeVector4(Vector4 vec) {
    float length = sqrtf(LengthVector4(vec));

    if (length == 0.0f)
        return MVector4(0, 0, 0, 0);

    return MVector4(
           vec.x / length,
           vec.y / length,
           vec.z / length,
           vec.w / length
           );
}



// Cross Product



Vector3 TriangleNormal(Vector3 vec1, Vector3 vec2, Vector3 vec3) {
    Vector3 vec21 = SubVector3(vec2, vec1);
    Vector3 vec31 = SubVector3(vec3, vec1);

    return NormalizeVector3(CrossProdVector3(vec21, vec31));
}
