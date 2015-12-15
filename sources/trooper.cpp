/** @file trooper.cpp
 *  @brief A file that contains implementation of Trooper class members
 *  @see Trooper
 */

#include "trooper.h"

using namespace model;

int damageByTypeAndStance(TrooperType type,
                          TrooperStance stance)
{
    switch(type)
    {
    case COMMANDER:
        switch(stance)
        {
            case PRONE:
                return 25;
            break;
            case KNEELING:
                return 20;
            break;
            case STANDING:
                return 15;
            break;
            case COUNT: // abnormal
                return 0;
            break;
        }
        break;
    case FIELD_MEDIC:
        switch(stance)
        {
            case PRONE:
                return 15;
            break;
            case KNEELING:
                return 12;
            break;
            case STANDING:
                return 9;
            break;
            case COUNT: // abnormal
                return 0;
            break;
        }
        break;
    case SOLDIER:
        switch(stance)
        {
            case PRONE:
                return 35;
            break;
            case KNEELING:
                return 30;
            break;
            case STANDING:
                return 25;
            break;
            case COUNT: // abnormal
                return 0;
            break;
        }
        break;
    case SNIPER:
        switch(stance)
        {
            case PRONE:
                return 95;
            break;
            case KNEELING:
                return 80;
            break;
            case STANDING:
                return 65;
            break;
            case COUNT: // abnormal
                return 0;
            break;
        }
        break;
    case SCOUT:
        switch(stance)
        {
            case PRONE:
                return 30;
            break;
            case KNEELING:
                return 25;
            break;
            case STANDING:
                return 20;
            break;
            case COUNT: // abnormal
                return 0;
            break;
        }
        break;
    }
    return 0; // compiler gets angry
}

Trooper::Trooper(int x,
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
                 TrooperType type)
    : Unit(x, y, id),
      player(player)
{
    this->actionPoints = actionPoints;
    this->hasGrenade = hasGrenade;
    this->hasFieldRation = hasFieldRation;
    this->hitpoints = hitpoints;
    this->hasMedkit = hasMedkit;
    //this->player = player;
    this->stance = stance;
    this->teammate = teammate;
    this->teammateIndex = teammateIndex;
    this->type = type;
}

int Trooper::getActionPoints() const
{
    return actionPoints;
}

int Trooper::getDamage() const
{
    return ::damageByTypeAndStance(this->type, this->stance);
}

int Trooper::getDamage(TrooperStance stance) const
{
    return ::damageByTypeAndStance(this->type, stance);
}

int Trooper::getHitpoints() const
{
    return hitpoints;
}

int Trooper::getInitialActionPoints() const
{
    if(type == SCOUT)
    {
        return 12;
    }
    else
    {
        return 10;
    }
}

int Trooper::getKneelingDamage() const
{
    return ::damageByTypeAndStance(this->type, KNEELING);
}

int Trooper::getMaximalHitPoints() const
{
    return 100;
}

long long Trooper::getPlayerId() const
{
    return player.getId();
}

int Trooper::getProneDamage() const
{
    return ::damageByTypeAndStance(this->type, PRONE);
}

int Trooper::getShootCost() const
{
    switch(type)
    {
        case COMMANDER:
            return 3;
        case FIELD_MEDIC:
            return 2;
        case SOLDIER:
            return 4;
        case SNIPER:
            return 9;
        case SCOUT:
            return 4;
    }
    return 0; // compiler gets angry
}

float Trooper::getShootingRange() const
{
    switch(type)
    {
        case COMMANDER:
            return 7;
        case FIELD_MEDIC:
            return 5;
        case SOLDIER:
            return 8;
        case SNIPER:
            return 10;
        case SCOUT:
            return 6;
    }
    return 0; // compiler gets angry
}

TrooperStance Trooper::getStance() const
{
    return stance;
}

int Trooper::getStandingDamage() const
{
    return ::damageByTypeAndStance(this->type, STANDING);
}

int Trooper::getTeammateIndex() const
{
    return teammateIndex;
}

TrooperType Trooper::getType() const
{
    return type;
}

float Trooper::getVisionRange() const
{
    switch(type)
    {
        case COMMANDER:
            return 8;
        case FIELD_MEDIC:
            return 7;
        case SOLDIER:
            return 7;
        case SNIPER:
            return 7;
        case SCOUT:
            return 9;
    }
    return 0; // compiler gets angry
}

bool Trooper::isHoldingFieldRation() const
{
    return hasFieldRation;
}

bool Trooper::isHoldingGrenade() const
{
    return hasGrenade;
}

bool Trooper::isHoldingMedkit() const
{
    return hasMedkit;
}

bool Trooper::isTeammate() const
{
    return teammate;
}
