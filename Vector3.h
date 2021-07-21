#pragma once

#include"Vector2.h"

struct Vector3
{
    double x, y, z;

    Vector3(double _value) :x(_value), y(_value), z(_value) {}
    Vector3(Vector2 v, double _z) :x(v.x), y(v.y), z(_z) {}
    Vector3(double _x, Vector2 v) :x(_x), y(v.x), z(v.y) {}
    Vector3(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {}

    Vector3 operator+(Vector3 other) { return Vector3(x + other.x, y + other.y, z + other.z); }
    Vector3 operator-(Vector3 other) { return Vector3(x - other.x, y - other.y, z - other.z); }
    Vector3 operator/(Vector3 other) { return Vector3(x / other.x, y / other.y, z / other.z); }
    Vector3 operator*(Vector3 other) { return Vector3(x * other.x, y * other.y, z * other.z); }
    Vector3 operator-() { return Vector3(-x, -y, -z); }
};