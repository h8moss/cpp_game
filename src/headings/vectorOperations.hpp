#pragma once
#include "raylib.h"

namespace VectorOP
{
    Vector2 add(Vector2 v1, Vector2 v2);
    Vector3 add(Vector3 v1, Vector3 v2);
    Vector4 add(Vector4 v1, Vector4 v2);

    Vector2 subtract(Vector2 v1, Vector2 v2);
    Vector3 subtract(Vector3 v1, Vector3 v2);
    Vector4 subtract(Vector4 v1, Vector4 v2);

    Vector2 multiply(Vector2 v1, float scalar);
    Vector3 multiply(Vector3 v1, float scalar);
    Vector4 multiply(Vector4 v1, float scalar);

    Vector2 normalize(Vector2 v);
    Vector3 normalize(Vector3 v);
    Vector4 normalize(Vector4 v);

    Vector3 cross(Vector3 v1, Vector3 v2);

    Vector2 dot(Vector2 v1, Vector2 v2);
    Vector3 dot(Vector3 v1, Vector3 v2);
    Vector4 dot(Vector4 v1, Vector4 v2);

    Vector2 lerp(Vector2 v1, Vector2 v2, float t);
    Vector3 lerp(Vector3 v1, Vector3 v2, float t);
    Vector4 lerp(Vector4 v1, Vector4 v2, float t);

    float magnitude(Vector2 v);
    float magnitude(Vector3 v);
    float magnitude(Vector4 v);

    float distance(Vector2 v1, Vector2 v2);
    float distance(Vector3 v1, Vector3 v2);
    float distance(Vector4 v1, Vector4 v2);

}