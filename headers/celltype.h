/** @file celltype.h
 *  @brief A file that contains definition of CellType enumeration.
 */

#ifndef CELLTYPE_H
#define CELLTYPE_H

namespace model
{
    /**
     * @brief A cell of a battlefield.
     * @details A battlefield contains multiple cells, some of which can be
     * passed by units, and some - not. Non-passable cells also protect troopers
     * from sight and bullets.
     */
    enum CellType
    {
        /**
         * @brief A free cell.
         * @details This cell can be passed by Trooper's, can have Bonus'es on
         * it and does not suppress vision and bullets.
         */
        FREE,
        /**
         * @brief A low cover.
         * @details This cell has low cover that protects PRONE troopers from
         * being shot and is not passable for Unit's.
         * @see TrooperStance
         */
        LOW_COVER,
        /**
         * @brief A cover of medium height.
         * @details This cell has medium hight cover that protects PRONE and
         * KNEELING troopers from being shot and is not passable for Unit's.
         * @see TrooperStance
         */
        MEDIUM_COVER,
        /**
         * @brief A high cover.
         * @details This cell has high cover that protects troopers from
         * being shot and is not passable for Unit's.
         * @see TrooperStance
         */
        HIGH_COVER
    };
}

#endif