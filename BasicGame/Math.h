#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Math
{
public:
	float static vLength(const Vector2f& v);
	Vector2f static normalize(const Vector2f& v);
};