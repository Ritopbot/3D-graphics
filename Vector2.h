#pragma once

struct Vector2
{
    double x, y;

    Vector2(double _value) :x(_value), y(_value) {}
    Vector2(double _x, double _y) :x(_x), y(_y) {}

    Vector2 operator+ (Vector2 other) { return Vector2(x + other.x, y + other.y); }
    Vector2 operator- (Vector2 other) { return Vector2(x - other.x, y - other.y); }
    Vector2 operator* (Vector2 other) { return Vector2(x * other.x, y * other.y); }
    Vector2 operator/ (Vector2 other) { return Vector2(x / other.x, y / other.y); }
};

//​оператор вычитания: 
//const vec2& operator-(const vec2& other) 
//{ this->x = this->x - other.x; this->y = this->y - other.y; return *this; }