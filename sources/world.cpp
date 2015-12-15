#include "world.h"

using namespace model;

vector<Bonus> World::getBonuses() const
{
    return bonuses;
}

vector<vector<CellType> > World::getCells() const
{
    return cells;
}

vector<bool> World::getCellVisibilities() const
{
    return *visibilities;
}

int World::getHeight() const
{
    return height;
}

int World::getMoveIndex() const
{
    return moveIndex;
}

vector<Player> World::getPlayers() const
{
    return players;
}

vector<Trooper> World::getTroopers() const
{
    return troopers;
}

int World::getWidth() const
{
    return width;
}

bool World::isVisible(double maxRange,
                      int viewerX,
                      int viewerY,
                      TrooperStance viewerStance,
                      int objectX,
                      int objectY,
                      TrooperStance objectStance) const
{
    return
    (*visibilities)[viewerX * height * width * height * TrooperStance::COUNT +
                   viewerY * width * height * TrooperStance::COUNT +
                   objectX * height * TrooperStance::COUNT +
                   objectY * TrooperStance::COUNT +
                   min(viewerStance, objectStance)];
}