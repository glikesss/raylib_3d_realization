#include <stdio.h>
#include <stdlib.h>

#include "src/raylib/raylib.h"
#include "src/internal/imath.h"
#include "src/internal/imatrix.h"
#include "src/internal/ivector.h"

Vector2 ToScreenPos(Vector2 position, int width, int height);
Vector2 FromScreenPos(Vector2 position, int width, int height);

void Update();


typedef struct {
    Vector3 vertices[3];
    Vector3 normal;
} Triangle;

Triangle CreateTriangle(Vector3 a, Vector3 b, Vector3 c)
{
    Triangle triangle = {
        .vertices = {a, b, c},
        .normal = TriangleNormal(a, b, c)
    };

    return triangle;
}

typedef struct{
    Vector3 position;
    Color default_color;
    _Bool is_hovered;
    Color on_hover_color;
    _Bool is_active;
    Color active_color;
    Color color;
    float radius;
    
} Point3D;

Point3D MPoint3DV(Vector3 position,  float radius, Color default_color, Color on_hover_color, Color active_color){
    Point3D point;
    point.position = position;
    point.radius = radius;    
    point.default_color = default_color;
    point.on_hover_color = on_hover_color;
    point.active_color = active_color;
 
   return point;
} 


Point3D MPoint3D(float x, float y, float z, float radius, Color default_color, Color on_hover_color, Color active_color){
    Point3D point;
    point.position = MVector3(x, y, z);
    point.radius = radius;    
    point.default_color = default_color;
    point.on_hover_color = on_hover_color;
    point.active_color = active_color;
 
   return point;
} 

int main() {
    InitWindow(800, 600, "Hello World");
    SetTargetFPS(120);    
    
    Vector3 delta = MVector3(0, 0, 0);
    
    Point3D dots[] = {
        MPoint3D( 1,  1,  1, 6 ,GREEN, PINK, BLUE), 
        MPoint3D( 1, -1,  1, 6 ,GREEN, PINK, BLUE),
        MPoint3D( 1,  1, -1, 6 ,GREEN, PINK, BLUE),
        MPoint3D( 1, -1, -1, 6 ,GREEN, PINK, BLUE),
        MPoint3D(-1,  1,  1, 6 ,GREEN, PINK, BLUE),
        MPoint3D(-1,  1, -1, 6 ,GREEN, PINK, BLUE),
        MPoint3D(-1, -1,  1, 6 ,GREEN, PINK, BLUE),
        MPoint3D(-1, -1, -1, 6 ,GREEN, PINK, BLUE),   
    };

    int triangles[][3] = {// +X
                          {0, 1, 2},
                          {2, 1, 3},

                          // -X
                          {4, 5, 6},
                          {6, 5, 7},

                          // +Y
                          {0, 2, 4},
                          {4, 2, 5},

                          // -Y
                          {1, 6, 3},
                          {3, 6, 7},

                          // +Z
                          {0, 4, 1},
                          {1, 4, 6},

                          // -Z
                          {2, 3, 5},
                          {5, 3, 7}};
    
         for (int i = 0; i < 12; i++) {
             Vector3 a = dots[triangles[i][0]].position;
             Vector3 b = dots[triangles[i][1]].position;
             Vector3 c = dots[triangles[i][2]].position;

             Vector3 normal = NormalizeVector3( CrossProdVector3( SubVector(b, a), SubVector(c, a) ));
         }
    
    Vector2 screen_position;
    Vector3 deg = MVector3(0, 5.0 / 60.0, 0.0 / 60.0);
    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_LEFT_CONTROL)) {
            ClearBackground(GRAY);
            if (IsKeyDown(KEY_UP))
                delta.z += 0.01;
            if (IsKeyDown(KEY_DOWN))
                delta.z -= 0.01;
      
        } else {
            ClearBackground(RAYWHITE);
            if (IsKeyDown(KEY_LEFT))
                delta.x -= 0.01;
            if (IsKeyDown(KEY_RIGHT))
                delta.x += 0.01;
            if (IsKeyDown(KEY_UP))
                delta.y += 0.01;
            if (IsKeyDown(KEY_DOWN))
                delta.y -= 0.01;
        }

        Vector2 mouse_pos = FromScreenPos(GetMousePosition(), 800, 600);
      
        BeginDrawing();
        ClearBackground(GRAY);
        DrawFPS(10, 10);

        Vector2 position;
        
        for (int i = 0; i < 8; i ++){

            Point3D it_point = dots[i];
            RotateVector3( &(it_point.position), MVector3(0, 0, 0), DEG2RAD * deg.x,
                                                                   DEG2RAD * deg.y,
                                                                   DEG2RAD * deg.z);

            position = PosToScreen(AddVector3(it_point.position, delta), 10, 0);
            
            if ( LengthVector( SubVector( 
                                         ToScreenPos(mouse_pos, 800, 600),
                                         ToScreenPos(position , 800, 600)) 
                             ) < it_point.radius * 1.1){
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
                    it_point.is_active = 1;
                    if (it_point.is_hovered)
                        it_point.color = it_point.active_color;
                } else{
                    it_point.is_active = 0;
                    it_point.is_hovered = 1;
                    it_point.color = it_point.on_hover_color;

                } 
            } else {
                it_point.is_active  = 0;
                it_point.is_hovered = 0;
                it_point.color = it_point.default_color;
            }
            DrawCircleV(ToScreenPos(position, 800, 600), (int)it_point.radius, it_point.color);
            // char *text = to_string(ToScreenPos(position, 800, 600));
            
            // DrawText(text, 10, 10 + 14 * i, 14, GREEN);
            // free(text);
        }

        char *text = to_string(mouse_pos);
        DrawText(text, 10, 49, 14, GREEN);
        free(text);
        
        
        for (int i = 0; i < 12; i++) {
            Color color = RED;

            Vector3 a = dots[triangles[i][0]].position;
            Vector3 b = dots[triangles[i][1]].position;
            Vector3 c = dots[triangles[i][2]].position;

            DrawLineV(
                ToScreenPos(PosToScreen(AddVector3(a, delta), 10, 0), 800, 600),
                ToScreenPos(PosToScreen(AddVector3(b, delta), 10, 0), 800, 600),
                color);

            DrawLineV(
                ToScreenPos(PosToScreen(AddVector3(b, delta), 10, 0), 800, 600),
                ToScreenPos(PosToScreen(AddVector3(c, delta), 10, 0), 800, 600),
                color);
            
            DrawLineV(
                ToScreenPos(PosToScreen(AddVector3(c, delta), 10, 0), 800, 600),
                ToScreenPos(PosToScreen(AddVector3(a, delta), 10, 0), 800, 600),
                color);            
        }
        EndDrawing();
    }

    
    
    
    CloseWindow();
    printf("Execuded succesfully");
    
    return 0;
}
Vector2 FromScreenPos(Vector2 position, int width, int height){
    Vector2 startPos = MVector2((float)width / 2, (float)height / 2);
    Vector2 matr[] = {
        MVector2(2.0 / (float)width, 0.0f),
        MVector2(0.0f, -2.0 / (float)height)
    };

    return VectorMatrixMul(SubVector(position, startPos), matr);

}

Vector2 ToScreenPos(Vector2 position, int width, int height) {
    Vector2 startPos = MVector2((float)width / 2, (float)height / 2);
    Vector2 matr[] = {
        MVector2((float)width / 2.0, 0.0f),
        MVector2(0.0f, -(float)height / 2.0)
    };

    return AddVector(startPos, VectorMatrixMul(position, matr));
}

