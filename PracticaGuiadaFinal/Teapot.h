#pragma once
#include <GL/glut.h>
#include "Vector3D.h"
#include "Color.h"
#include "Solid.h"

class Teapot : public Solid
{
private:

	float size;

public:

	Teapot(Vector3D coordinates, Color color, Vector3D orientation, float size) :

		Solid(coordinates, color, orientation),
		size(size) {}

	inline float GetSize() const { return this->size; }

	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	Solid* Clone();

	void Render();
};



