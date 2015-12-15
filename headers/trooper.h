/** @file trooper.h
 *  @brief A file that contains definition of Trooper class.
 *  @see trooper.cpp
 */
 
#ifndef TROOPER_H
#define TROOPER_H

#include "player.h"
#include "unit.h"

namespace model
{
    /**
     * @brief Trooper's stance - prone, kneeling or standing.
     * @details Troopers can be in either of this three stances. They can lower
     * or raise their stance by setting action of Move to LOWER_STANCE or
     * LOWER_STANCE.
     * @see Move
     * @see ActionType
     */
    enum TrooperStance
    {
        /**
         * @brief Trooper lies on the ground
         * @details He is protected from sight by all CellType's but free, and
         * moving cost is the most.
         */
        PRONE,

        /**
         * @brief Trooper stands on his knees.
         * @details He is protected from sight by all CellType's but free and
         * low cover, medium move cost.
         */
        KNEELING,

        /**
         * @brief Trooper stands on two legs.
         * @details He is protected from sight only by high cover and moving is
         * most cost-effective.
         */
        STANDING,

        /**
         * @brief This enum value is used to store the amount of positions.
         */
        COUNT
    };


    /**
     * @brief Type of a trooper. Commander, field medic, sniper, scout.
     */
    enum TrooperType
    {
        /**
         * @brief Commander.
         * @details His presence increases initial action points of any allied
         * trooper in the radius of 5 cells around him by 2. Commander himself
         * does not receive this bonus.
         */
        COMMANDER,

        /**
         * @brief Field medic.
         * @details Can heal trooper's wounds on a battlefield. Upon spending
         * one action point, he can heal adjacent(horizontally or vertically)
         * unit for 5 health, or himself for 3 health. Unit's health cannot
         * exceed 100.
         */
        FIELD_MEDIC,

        /**
         * @brief Soldier.
         * @details Soldier has steel armour that grants him 20 more initial
         * health. But, as any other soldier, he cannot be healed above 100 hp.
         */
        SOLDIER,

        /**
         * @brief Sniper.
         * @details Disguise master. When he is kneeling, vision radius of
         * troopers that attempt to look at him is decreased by 0,5. When he
         * is prone - by 1. Also when he kneels, he has 1 bonus shooting range,
         * when prone - 2.
         */
        SNIPER,

        /**
         * @brief Scout.
         * @details His vision radius is not decreased by sniper's disguise
         * ability. Has 2 more action points. However, he is used to acting
         * alone, so he does not receive commander's action points bonus.
         */
        SCOUT
    };


    /**
     * @brief How many damage deals a soldier of stated type in stated stance.
     */
    int damageByTypeAndStance(TrooperType type,
                              TrooperStance stance);


    class Trooper : public Unit
    {
    private:
        /**
         * @brief Current action points.
         */
        int actionPoints;

        /**
         * @brief True if this trooper has grenade
         */
        bool hasGrenade;

        /**
         * @brief True if this trooper has field ration
         */
        bool hasFieldRation;

        /**
         * @brief Current hitpoints
         */
        int hitpoints;

        /**
         * @brief Maximal action points
         */
        int initialActionPoints;

        /**
         * @brief True if this trooper has medkit
         */
        bool hasMedkit;

        /**
         * @brief Player that controls this trooper
         */
        Player player;

        /**
         * @brief Stance of this trooper
         * @see TrooperStance
         */
        TrooperStance stance;

        /**
         * @brief True if this trooper is your teammate
         */
        bool teammate;

        /**
         * @brief 0-indexed number of this trooper in his team
         */
        int teammateIndex;

        /**
         * @brief Type of a trooper
         * @see TrooperType
         */
        TrooperType type;
    public:
        Trooper(int x,
                int y,
                long long id,
                int actionPoints,
                bool hasGrenade,
                bool hasFieldRation,
                int hitpoints,
                bool hasMedkit,
                Player player,
                TrooperStance stance,
                bool teammate,
                int teammateIndex,
                TrooperType type);

        /**
         * @returns Current action points.
         * @see actionPoints
         */
        int getActionPoints() const;

        /**
         * @returns Damage of this trooper in current stance.
         * @see TrooperType
         * @see TrooperStance
         * @see damageByTypeAndStance
         */
        int getDamage() const;

        /**
         * @returns Damage of this trooper in different stances.
         * @see TrooperStance
         */
        int getDamage(TrooperStance stance) const;

        /**
         * @returns Current amount of health of this trooper.
         * @see hitPoints
         */
        int getHitpoints() const;

        /**
         * @returns The amount of action points given to a trooper at the
         * beginning of a move.
         * @see initialActionPoints
         */
        int getInitialActionPoints() const;

        /**
         * @returns Damage of this trooper when kneeling.
         * @see TrooperStance
         */
        int getKneelingDamage() const;

        /**
         * @returns Maximal amount of hitpoints. Troopers cannot be healed
         * beyond this number of HP.
         */
        int getMaximalHitPoints() const;

        /**
         * @returns ID of a Player that controls this trooper.
         * @see Player::id
         */
        long long getPlayerId() const;

        /**
         * @returns Damage of this trooper when prone.
         * @see TrooperStance
         */
        int getProneDamage() const;

        /**
         * @returns The amount of action points this trooper needs to shoot from
         * his current stance.
         * @see actionPoints
         * @see stance
         */
        int getShootCost() const;

        /**
         * @returns How far this trooper can shoot. Maximal distance from this
         * trooper to another, at which this trooper will shoot another.
         * @see TrooperType
         */
        float getShootingRange() const;

        /**
         * @returns Stance of this trooper
         * @see stance
         */
        TrooperStance getStance() const;

        /**
         * @returns Damage of this trooper when standing.
         * @see TrooperStance
         */
        int getStandingDamage() const;

        /**
         * @returns 0-indexed number of this trooper in his team.
         * @see teammateIndex
         */
        int getTeammateIndex() const;

        /**
         * @returns Type of this trooper.
         * @see type
         */
        TrooperType getType() const;

        /**
         * @returns How far this trooper can see. Maximal distance from this
         * trooper to another cell when he can see that cell.
         * @see
         */
        float getVisionRange() const;

        /**
         * @returns Does this trooper hold a field ration?
         * @see hasFieldRation
         */
        bool isHoldingFieldRation() const;

        /**
         * @returns Does this trooper hold a grenade?
         * @see hasGrenade
         */
        bool isHoldingGrenade() const;

        /**
         * @returns Does this trooper hold a med kit?
         * @see isHoldingMedkit
         */
        bool isHoldingMedkit() const;

        /**
         * @returns Is this trooper a teammate of a trooper, who calls this
         * method?
         * @see teammate
         * @see Move
         */
        bool isTeammate() const;
    };
}

#endif