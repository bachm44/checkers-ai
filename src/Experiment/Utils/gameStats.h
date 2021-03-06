#ifndef GAME_STATS_H
#define GAME_STATS_H

#include "../../Utils/player.h"
#include <vector>

namespace game_stats
{
class GameStats
{
public:
    double AvgMoveDuration;
    double GameDuration;
    player::PlayerType Winner;

    GameStats() = default;
    void AppendMove(double duration);
};

class TotalGameStats
{
public:
    double AvgMoveDuration;
    double GameDuration;
    double Player1WinRate;

    TotalGameStats(int depth);
    void AppendGame(const GameStats& stats);
    void Show() const;
    static void ShowMany(const std::vector<TotalGameStats>& stats);

private:
    int m_GameCount;
    int m_Player1Wins;
    int m_Depth;
};

}
#endif