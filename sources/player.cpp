/** @file player.cpp
 *  @brief A file that contains implementation of Player class members
 *  @see Player
 */

#include "player.h"
#include <string>

using namespace model;

Player::Player()
{
    this->id = 0;
    this->name = "";
    this->score = 0;
    this->strategyCrashed = false;
    this->approximateX = -100;
    this->approximateY = -100;
}

Player::Player(long long id,
               std::string name,
               int score,
               bool strategyCrashed,
               int approximateX,
               int approximateY)
{
    this->id = id;
    this->name = name;
    this->score = score;
    this->strategyCrashed = strategyCrashed;
    this->approximateX = approximateX;
    this->approximateY = approximateY;
}

Player::Player(const Player &player)
{
    this->id = player.getId();
    this->name = player.getName();
    this->score = player.getScore();
    this->strategyCrashed = player.isStrategyCrashed();
    this->approximateX = player.getApproximateX();
    this->approximateY = player.getApproximateY();
}

int Player::getApproximateX() const
{
    return approximateX;
}

int Player::getApproximateY() const
{
    return approximateY;
}

long Player::getId() const
{
    return id;
}

std::string Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}

bool Player::isStrategyCrashed() const
{
    return strategyCrashed;
}
