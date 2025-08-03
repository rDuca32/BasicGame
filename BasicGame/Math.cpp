#include "Math.h"

using namespace std;
using namespace sf;

float Math::vLength(const Vector2f& v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

Vector2f Math::normalize(const Vector2f& v) {
	float len = vLength(v);
	return len != 0 ? Vector2f(v.x / len, v.y / len) : Vector2f();
}