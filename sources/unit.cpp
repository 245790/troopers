/** @file unit.cpp
 *  @brief A file that contains implementation of Unit class members
 *  @see Unit
 */

#include "unit.h"

#include <math.h>

using namespace model;

Unit::Unit(int x, int y, long long id)
{
	this->x = x;
	this->y = y;
	this->id = id;
}

float Unit::getDistanceTo(int x, int y) const
{
	return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}

float Unit::getDistanceTo(Unit unit) const
{
	return getDistanceTo(unit.getX(), unit.getY());
}

long long Unit::getId() const
{
	return id;
}

int Unit::getX() const
{
	return x;
}

int Unit::getY() const
{
	return y;
}
