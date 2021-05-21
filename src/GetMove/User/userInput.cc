#include "userInput.h"
#include "../../DrawBoard/board.h"
#include "../../Utils/move.h"
#include "../../Utils/player.h"
#include "../../Utils/point.h"
#include "position.h"
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

std::optional<Move> UserInput::GetMove(const board::Checkerboard& board, const std::vector<Move>& availableMoves)
{
    while (true)
    {
        std::string input;

        printf("\n%s>>> ", board.CurrentPlayer.GetPlayerName().c_str());

        getline(std::cin, input);
        if (input == "exit")
        {
            return std::nullopt;
        }

        auto parsedMove = ParseMove(input);

        for (const auto& move : availableMoves)
        {
            if (move == parsedMove)
            {
                return parsedMove;
            }
        }

        printf("%s\n", "Cannot make a move");
    }
}

Move UserInput::ParseMove(const std::string& input)
{
    std::istringstream stream(input);
    std::string token;
    Move result;

    while (getline(stream, token, ' '))
    {
        auto position = Position::Construct(token);
        if (!position)
        {
            printf("Unrecognised position: %s\n", token.c_str());
            break;
        }

        Point point = { position->X, position->Y };
        result.Path.push_back(point);
    }

    return result;
}