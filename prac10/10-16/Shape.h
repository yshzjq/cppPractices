#ifndef SHAPE_H
#define SHAPE_H

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint();
};

#include "Line.h"
#include "Rect.h"
#include "Circle.h"

#endif