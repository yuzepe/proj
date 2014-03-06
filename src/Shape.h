/*
 * Shape.h
 *
 * @author Joseph Zehe
 *
 */

#ifndef SHAPE_H
#define SHAPE_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <sstream>
#include <string>

using namespace std;

class Shape;
typedef Shape* ShapePtr;

class Shape
{
public:
	Shape() {};
	virtual ~Shape();

	virtual string toRawString() {return " ";};
	virtual string toString() {return " ";};
	virtual float getVolume() {return 0.0f;}; /*const = 0*/ // Kubikzentimeter cm³
private:
};

#endif
