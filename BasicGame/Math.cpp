#include "Math.h"

using namespace std;
using namespace sf;

float Math::vLength(const Vector2f& v) {
	// Calculate the length of a 2D vector
	return sqrt(v.x * v.x + v.y * v.y);
}

Vector2f Math::normalize(const Vector2f& v) {
	// Normalize a 2D vector
	float len = vLength(v);
	return len != 0 ? Vector2f(v.x / len, v.y / len) : Vector2f();
}