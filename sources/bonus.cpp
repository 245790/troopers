/** @file bonus.cpp
 *  @brief A file that contains implementation of Bonus class members
 *  @see Bonus
 */

#include "bonus.h"

using namespace model;

Bonus::Bonus(int x, int y, long long id, BonusType type)
: Unit(x, y, id)
{
    this->type = type;
}

BonusType Bonus::getType() const
{
    return type;
}