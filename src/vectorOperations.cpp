#include "headings/vectorOperations.hpp"
#include <cmath>

namespace VectorOP
{
    namespace
    { // Private namespace
        float floatLerp(float v1, float v2, float t)
        {
            return v1 + (v2 - v1) * t;
        }
    }

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

    Vector2 multiply(Vector2 v1, float scalar)
    {
        return {v1.x * scalar, v1.y * scalar};
    }

    Vector3 multiply(Vector3 v1, float scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar};
    }

    Vector4 multiply(Vector4 v1, float scalar)
    {
        return {v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w * scalar};
    }

    Vector2 reverse(Vector2 v)
    {
        return {1 / v.x, 1 / v.y};
    }
    Vector3 reverse(Vector3 v)
    {
        return {1 / v.x, 1 / v.y, 1 / v.z};
    }
    Vector4 reverse(Vector4 v)
    {
        return {1 / v.x, 1 / v.y, 1 / v.z, 1 / v.w};
    }

    Vector2 divideComponents(Vector2 v1, Vector2 v2)
    {
        return multiplyComponents(v1, reverse(v2));
    }

    Vector3 divideComponents(Vector3 v1, Vector3 v2)
    {
        return multiplyComponents(v1, reverse(v2));
    }
    Vector4 divideComponents(Vector4 v1, Vector4 v2)
    {
        return multiplyComponents(v1, reverse(v2));
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

    Vector2 multiplyComponents(Vector2 v1, Vector2 v2)
    {
        return {v1.x * v2.x, v1.y * v2.y};
    }
    Vector3 multiplyComponents(Vector3 v1, Vector3 v2)
    {
        return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
    }
    Vector4 multiplyComponents(Vector4 v1, Vector4 v2)
    {
        return {v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w};
    }

    float dot(Vector2 v1, Vector2 v2)
    {
        Vector2 result{multiplyComponents(v1, v2)};
        return result.x + result.y;
    }

    float dot(Vector3 v1, Vector3 v2)
    {
        Vector3 result{multiplyComponents(v1, v2)};
        return result.x + result.y + result.z;
    }

    float dot(Vector4 v1, Vector4 v2)
    {
        Vector4 result{multiplyComponents(v1, v2)};
        return result.x + result.y + result.z + result.w;
    }

    Vector2 lerp(Vector2 v1, Vector2 v2, float t)
    {
        return {
            floatLerp(v1.x, v2.x, t),
            floatLerp(v1.y, v2.y, t)};
    }

    Vector3 lerp(Vector3 v1, Vector3 v2, float t)
    {
        return {
            floatLerp(v1.x, v2.x, t),
            floatLerp(v1.y, v2.y, t),
            floatLerp(v1.z, v2.z, t)};
    }

    Vector4 lerp(Vector4 v1, Vector4 v2, float t)
    {
        return {
            floatLerp(v1.x, v2.x, t),
            floatLerp(v1.y, v2.y, t),
            floatLerp(v1.z, v2.z, t),
            floatLerp(v1.w, v2.w, t)};
    }

    float magnitude(Vector2 v)
    {
        return sqrt(v.x * v.x + v.y * v.y);
    }
    float magnitude(Vector3 v)
    {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }
    float magnitude(Vector4 v)
    {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
    }

    float distance(Vector2 v1, Vector2 v2)
    {
        return magnitude(subtract(v1, v2));
    }

    float distance(Vector3 v1, Vector3 v2)
    {
        return magnitude(subtract(v1, v2));
    }

    float distance(Vector4 v1, Vector4 v2)
    {
        return magnitude(subtract(v1, v2));
    }

}