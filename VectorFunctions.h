#pragma once

#include"Vector2.h"
#include"Vector3.h"
#include <cmath>

int sign(double a) {
    return 0 < a - a < 0;
}
double step(double x, double edge) {
    return x > edge;
}
double length(Vector2 v) {
    return sqrt(v.x * v.x + v.y * v.y);
}
double length(Vector3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
Vector2 norm(Vector2 v) {
    return v / length(v);
}
Vector3 norm(Vector3 v) {
    return v / length(v);
}
Vector3 abs(Vector3 v) {
    return Vector3(fabs(v.x), fabs(v.y), fabs(v.z));
}
double dot(Vector3 a, Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector3 sign (Vector3 v){
    return Vector3(sign(v.x), sign(v.y), sign(v.z));
}
Vector3 step(Vector3 v, Vector3 edge) {
    return Vector3(step(v.x, edge.x), step(v.y, edge.y), step(v.z, edge.z));
}

Vector2 sphIntersect(Vector3 ro, Vector3 rd, Vector3 ce, double ra) {
    Vector3 oc = ro - ce;
    double b = dot(oc, rd);
    double c = dot(oc, oc) - ra * ra;
    double h = b * b - c;
    if (h < 0.0) return Vector2(-1.0);
    h = sqrt(h);
    return Vector2(-b - h, -b + h);
}
Vector3 rotateX(Vector3 a, double angle)
{
    Vector3 b = a;
    b.z = a.z * cos(angle) - a.y * sin(angle);
    b.y = a.z * sin(angle) + a.y * cos(angle);
    return b;
}

Vector3 rotateY(Vector3 a, double angle)
{
    Vector3 b = a;
    b.x = a.x * cos(angle) - a.z * sin(angle);
    b.z = a.x * sin(angle) + a.z * cos(angle);
    return b;
}

Vector3 rotateZ(Vector3 a, double angle)
{
    Vector3 b = a;
    b.x = a.x * cos(angle) - a.y * sin(angle);
    b.y = a.x * sin(angle) + a.y * cos(angle);
    return b;
}

Vector2 boxIntersection(Vector3 ro, Vector3 rd, Vector3 boxSize, Vector3 outNormal)
{
    Vector3 m = Vector3(1.0) / rd;
    Vector3 n = m * ro;
    Vector3 k = abs(m) * boxSize;
    Vector3 t1 = -n - k;
    Vector3 t2 = -n + k;
    double tN = fmax(fmax(t1.x, t1.y), t1.z);
    double tF = fmin(fmin(t2.x, t2.y), t2.z);
    if (tN > tF || tF < 0.0) return Vector2(-1.0);
    Vector3 yzx = Vector3(t1.y, t1.z, t1.x);
    Vector3 zxy = Vector3(t1.z, t1.x, t1.y);
    outNormal = -sign(rd) * step(yzx, t1) * step(zxy, t1);
    return Vector2(tN, tF);
}