#ifndef BOARD_H
#define BOARD_H

#include "../Utils/move.h"
#include "../Utils/player.h"
#include "../Utils/point.h"
#include "constants.h"
#include "piece.h"
#include <map>
#include <vector>

namespace board
{
enum class PieceMoveType
{
    ILLEGAL,
    SHORT,
    LONG
};

class Checkerboard
{
public:
    player::Player CurrentPlayer = player::Player(player::PlayerType::PLAYER1);
    piece::Piece State[constants::BOARD_HEIGHT][constants::BOARD_WIDTH];

    Checkerboard();
    void Show() const;
    bool IsMoveValid(const Point& from, const Point& to, player::PlayerType) const;
    bool IsGameCompleted();
    void MovePiece(const Move& path);
    player::PlayerType GetWinner();

private:
    std::map<player::PlayerType, int> m_PiecesAlive;

    void PrintLettersBelow() const;
    piece::Piece GetFieldPiece(const Point& position) const;
    std::string GetFieldIcon(int i, int j) const;
    std::string GetFieldNumber(int i) const;
    std::string GetFieldString(int i, int j) const;
    bool IsInitiallyEmpty(const Point& point, int middleRow);

    void ChangePositionOfPiece(const Point& from, const Point& to, PieceMoveType move);
    bool IsPiecePromotion(const Point& position) const;
    bool IsEndPositionForPlayer(const Point& position, player::PlayerType player) const;
    void PromotePiece(const Point& position);
    void Capture(const Point& from, const Point& to);
    bool IsAnyMovePossible() const;
    PieceMoveType GetMoveType(const Point& from, const Point& to) const;
    bool ValidateShortMove(const Point& from, const Point& to) const;
    bool ValidateLongMove(const Point& from, const Point& to) const;
};
}
#endif