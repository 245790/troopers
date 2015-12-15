#ifndef WORLD_H
#define WORLD_H

#include <algorithm>
#include <memory>
#include <vector>

#include "bonus.h"
#include "celltype.h"
#include "player.h"
#include "trooper.h"

using namespace std;

namespace model
{
    class World
    {
    private:
        vector<Bonus> bonuses;
        vector<vector<CellType> > cells;
        int height;
        int moveIndex;
        vector<Player> players;
        vector<Trooper> troopers;
        vector<bool> visibilities;
        int width;
    public:
        vector<Bonus> getBonuses() const;
        vector<vector<CellType> > getCells() const;
        vector<bool> getCellVisibilities() const;
        int getHeight() const;
        int getMoveIndex() const;
        vector<Player> getPlayers() const;
        vector<Trooper> getTroopers() const;
        int getWidth() const;
        bool isVisible(double maxRange,
                       int viewerX,
                       int viewerY,
                       TrooperStance viewerStance,
                       int objectX,
                       int objectY,
                       TrooperStance objectStance) const;
    };
}

#endif