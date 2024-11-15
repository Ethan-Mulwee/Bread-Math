#include <raylib.h>
#include "bMath/bMath.hpp"
#include "bMath/ext/raylib.hpp"
#include "bMath/ext/iostream.hpp"

// g++ RaylibTesting.cpp -lraylib -I../include

Camera camera;
const float axisLength = 4;

void DrawAxes() {
  DrawGrid(5,1);
  DrawLine3D(Vector3{-axisLength,0,0}, Vector3{axisLength,0,0}, RED);
  DrawLine3D(Vector3{0,-axisLength,0}, Vector3{0,axisLength+0.5,0}, GREEN);
  DrawLine3D(Vector3{0,0,-axisLength}, Vector3{0,0,axisLength}, BLUE);
}



int main() {
  InitWindow(750,750, "testing");
  camera.position = Vector3{5,5,-5};
  camera.target = Vector3{0,0,0};
  camera.up = Vector3{0,1,0};
  camera.fovy = 45;
  camera.projection = CAMERA_PERSPECTIVE;

    bMath::float3 b(1,0.5,0);
    bMath::float3 a(1,1,0);

  while(!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_ORBITAL);
    // b = rotate(b, bMath::QuaternionAxisAngle(0.001, bMath::float3(0,1,0)));
    a.normalize();
    b.normalize();
    bMath::float4 q = bMath::rotationBetween(a,b);
    q.normalize();
    // TODO: a*q should work as well
    // q*a implicitly converts to a transform matrix?
    bMath::float3 c = rotate(a,q);
    std::cout << bMath::QuaternionAngle(q) << "\n";

    BeginDrawing();
    ClearBackground(Color{35,35,35,255});
      BeginMode3D(camera);
        DrawAxes();
        drawVector(a, ORANGE);
        drawVector(b, PURPLE);
        drawVector(c, WHITE);
      EndMode3D();
    EndDrawing();
  }

}