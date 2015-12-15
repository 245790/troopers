/** @file bonus.h
 *  @brief A file that contains definition of Bonus class and BonusType
 *  enumeration.
 *  @see bonus.cpp
 */

#ifndef BONUS_H
#define BONUS_H

#include "unit.h"

namespace model
{
    /**
     * @brief Type of a Bonus.
     */
    enum BonusType
    {
        /**
         * @brief Grenade
         * @details A trooper can throw a grenade in any cell, distance to which
         * is less than 5. A cell can be inaccessible for a trooper. Trooper in
         * target cell takes 80 damage, and all the units in adjacent
         * (horizontally or vertically) cells - 60 damage.
         */
        GRENADE,
        /**
         * @brief Medkit
         * @details For two action points a trooper can heal
         * adjacent(horizontally or vertically) trooper for 50 or himself for 30.
         * Health of a trooper cannot exceed 100.
         */
        MEDKIT,
        /**
         * @brief Field ration
         * @details For two action points a trooper can restore himself five
         * action points. Action points cannot exceed initial action points.
         */
        FIELD_RATION
    };

    /**
     *  @brief A class that describes a bonus.
     *  @details A Bonus can be picked up by a Trooper if he enters a cell with
     *  a bonus, unless a trooper already has a bonus of that type.
     */
    class Bonus : public Unit
    {
    private:
        /**
         * @brief Type of a bonus.
         * @see BonusType
         */
        BonusType type;
    public:
        /**
         * @brief A parametrized constructor.
         * @details Constructs a Bonus given x, y, id and a BonusType.
         * @param x X-coordinate of a bonus.
         * @param y Y-coordinate of a bonus.
         * @param id Unique ID.
         * @param type Type of a bonus.
         * @see BonusType
         */
        Bonus(int x, int y, long long id, BonusType type);

        /**
         * @returns Type of this bonus.
         */
        BonusType getType() const;
    };
}

#endif