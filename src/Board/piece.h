#ifndef PIECE_H
#define PIECE_H

#include "../Utils/player.h"
#include <string>

namespace piece
{
enum PieceType
{
    EMPTY,
    MAN,
    KING
};
enum FieldType
{
    NONE,
    PLAYER1,
    PLAYER2,
    PLAYER1_KING,
    PLAYER2_KING
};

class Piece
{

public:
    player::Player Player;
    PieceType Type;

    Piece();
    Piece(const player::Player& player, const PieceType& type);
    std::string GetIcon();

private:
    static const std::string m_Icons[5];
};
}

#endif