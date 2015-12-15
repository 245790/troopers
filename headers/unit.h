/** @file unit.h
 *  @brief A file that contains definition of Unit class.
 *  @see unit.cpp
 */

#ifndef UNIT_H
#define UNIT_H

namespace model
{
    /**
     *  @brief A class that describes a unit on a battlefield.
     *  @details Unit is any instance of a battlefield. Inherited by Trooper and
     *  Bonus
     */
    class Unit
    {
    private:
        /**
         * X-coordinate of a unit.
         */
        int x;

        /**
         * Y-coordinate of a unit.
         */
        int y;

        /**
         * Unique ID.
         */
        long long id;
    public:
        /**
         * @brief A parametrized constructor.
         * @details Constructs a Unit given x, y and id.
         * @param x X-coordinate of a unit.
         * @param y Y-coordinate of a unit.
         * @param id Unique ID.
         */
        Unit(int x, int y, long long id);

        /**
         * @brief Calculates the distance between this Unit and cell with
         * coordinates x and y
         * @return Distance between center of this Unit and center of a cell
         * with coordinates x and y
         */
        float getDistanceTo(int x, int y) const;

        /**
         * @brief Calculates distance between two Unit's
         * @return Distance between center of this Unit and center of argument
         */
        float getDistanceTo(Unit unit) const;

        /**
         * @return Unique ID of this Unit
         */
        virtual long long getId() const final;

        /**
         * @return X-coordinate of this Unit
         */
        virtual int getX() const final;

        /**
         * @return Y-coordinate of this Unit
         */
        virtual int getY() const final;
    };
}

#endif