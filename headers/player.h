/** @file player.h
 *  @brief A file that contains definition of Player class.
 *  @see player.cpp
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace model
{
    /**
     * @brief A player that controls Trooper's.
     * @details A player is a human who wrote a strategy for Troopers.
     * Commander can retrieve some information about Player's Trooper's
     * positions.
     * @see TrooperType - who is Commander.
     * @see Player::getApproximateX() - what is "some information about.
     * Trooper's positions"
     * @see Player::getApproximateY() - the same as above.
     */
    class Player
    {
    private:
        /**
         * @brief A name of a player.
         */
        std::string name;

        /**
         * @brief Unique ID of a player.
         */
        long long id;

        /**
         * @brief Score of a player.
         * @details Players earn score points when:
         * -# Their troopers deal damage (1 score for each damage)
         * -# Their tropers kill enemy troopers (25 score for enemy killed).
         * This score is given for a fact of killing, for damage they earn score
         * according to rule 1
         * -# Their troopers kill the last trooper of an enemy player. Rule 2 is
         * ignored
         * -# Their troopers kill the last trooper on a battlefield and at least
         * one player's trooper remained alive or a player remained the last
         * alive in case of other's player's suicide. 100 score. Rules 2 and 3
         * are ignored.
         */
        int score;

        /**
         * @brief If a player's strategy crashed.
         * @details A player's strategy is considered crashed in following
         * cases:
         * - If a player's trooper attempts to make an incorrect move
         */
        bool strategyCrashed;

        /**
         * @brief Approximate X-coordinate of a player.
         * @details If and enemy Commander decides to call a plane to request
         * enemy disposition, then on the Commander's next turn he will know
         * approximate coordinates for each player. They are calculated by
         * calculating an average of their trooper's coordinates and then adding
         * some random number to each coordinate. That random number's module
         * does not exceed 5.
         */
        int approximateX;

        /**
         * @see approximateX
         */
        int approximateY;
    public:
        /**
         * @brief Default constructor
         * @details Constructs a player with following parameters:
         * - id = 0
         * - name = ""
         * - score = 0
         * - strategyCrashed = false
         * - approximate X and Y = -100
         */
        Player();

        /**
         * @brief Parametrized constructor
         * @details Constructs a player with parameters, passed as arguments
         * @param id Unique ID of a player.
         * @param name Name of a player.
         * @param score Score of a player.
         * @param approximateX Approximate X-coordinate of a player.
         * @param approximateY Approximate Y-coordinate of a player.
         * @see approximateX
         * @see approximateY
         */
        Player(long long id,
               std::string name,
               int score,
               bool strategyCrashed,
               int approximateX,
               int approximateY);

        /**
         * @brief Copy constructor.
         * @details Constructs a player with the same characteristics as
         * argument.
         * @param player A player to copy.
         */
        Player(const Player& player);
        
        /**
         * @returns Approximate X-coordinate of a player.
         * @see approximateX
         */
        int getApproximateX() const;

        /**
         * @returns Approximate Y-coordinate of a player.
         * @see approximateY
         */
        int getApproximateY() const;

        /**
         * @returns Unique ID of a player.
         * @see id
         */
        long getId() const;

        /**
         * @returns Name of a player.
         * @see Player::name
         */
        std::string getName() const;

        /**
         * @returns Score of a player.
         * @see Player::score
         */
        int getScore() const;

        /**
         * @returns If a player's strategy crashed
         * @see Player::strategyCrashed
         */
        bool isStrategyCrashed() const;
    };
}

#endif