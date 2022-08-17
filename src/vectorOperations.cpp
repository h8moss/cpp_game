#include "headings/vectorOperations.hpp"
#include <cmath>

namespace VectorOP
{
    Vector2 add(Vector2 v1, Vector2 v2)
    {
        return {v1.x + v2.x, v1.y + v2.y};
    }

    Vector3 add(Vector3 v1, Vector3 v2)
    {
        return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    }

    Vector4 add(Vector4 v1, Vector4 v2)
    {
        return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w};
    }

    Vector2 subtract(Vector2 v1, Vector2 v2)
    {
        return {v1.x - v2.x, v1.y - v2.y};
    }
    Vector3 subtract(Vector3 v1, Vector3 v2)
    {
        return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
    }
    Vector4 subtract(Vector4 v1, Vector4 v2)
    {
        return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w};
    }

    Vector2 multiply(Vector2 v1, long int scalar)
    {
        return {v1.x * scalar, v1.y * scalar};
    }
    Vector2 multiply(Vector2 v1, int scalar)
    {
        return {v1.x * scalar, v1.y * scalar};
    }
    Vector2 multiply(Vector2 v1, float scalar)
    {
        return {v1.x * scalar, v1.y * scalar};
    }

    Vector3 multiply(Vector3 v1, long int scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar};
    }
    Vector3 multiply(Vector3 v1, int scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar};
    }

    Vector3 multiply(Vector3 v1, float scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar};
    }

    Vector4 multiply(Vector4 v1, long int scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w * scalar};
    }
    Vector4 multiply(Vector4 v1, int scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w * scalar};
    }
    Vector4 multiply(Vector4 v1, float scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w * scalar};
    }

    Vector2 normalize(Vector2 v)
    {
        float len = sqrt(v.x * v.x + v.y * v.y);
        if (len == 0)
            return {0, 0};
        return {v.x / len, v.y / len};
    }
    Vector3 normalize(Vector3 v)
    {
        float len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        if (len == 0)
            return {0, 0, 0};
        return {v.x / len, v.y / len, v.z / len};
    }
    Vector4 normalize(Vector4 v)
    {
        float len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
        if (len == 0)
            return {0, 0, 0, 0};
        return {
            v.x / len,
            v.y / len,
            v.z / len,
            v.w / len};
    }

    Vector3 cross(Vector3 v1, Vector3 v2)
    {
        return {
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x};
    }

    Vector2 dot(Vector2 v1, Vector2 v2)
    {
        return {v1.x * v2.x, v1.y * v2.y};
    }
    Vector3 dot(Vector3 v1, Vector3 v2)
    {
        return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
    }
    Vector4 dot(Vector4 v1, Vector4 v2)
    {
        return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w};
    }
}