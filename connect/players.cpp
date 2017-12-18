// players.cpp

#include "players.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>

Player::Player()
{
}

Player::~Player()
{
}

int Player::getPlayerType()
{
	return player_type;
}

void Player::setPlayerType(PlayerType p_type)
{
	player_type = p_type;
}

HumanPlayer::HumanPlayer()
{
	setPlayerType(PlayerType::HumanPlayer);
}

HumanPlayer::~HumanPlayer()
{
}

int HumanPlayer::getNextTurn(int boardState[], int _w, int _h)
{
	int ret = -1;
	int selected_col;
	bool is_selected = false;

	while (!is_selected)
	{
		std::cout << "Please select the position number of stone (1 ~ " << _w << +"): ";
		std::cin >> selected_col;

		if (selected_col > 0 && selected_col <= _w)
		{
			for (int j = _h - 1; j > -1; j--)
			{
				int id = selected_col + j * _w - 1;
				if (boardState[id] == 0)//Empty
				{
					is_selected = true;
					ret = id;
					break;
				}
			}
		}

		if (!is_selected)
		{
			std::cout << "You can't place stone on the selected position. Please try again." << "\n";
		}
	}

	return ret;
}

AiPlayer::AiPlayer()
{
	setPlayerType(PlayerType::AiPlayer);
}

AiPlayer::~AiPlayer()
{
}

int AiPlayer::getNextTurn(int boardState[], int _w, int _h)
{
	int		ret = -1;
	bool	is_selected = false;
	int		selected_col = 0;

	std::vector<int> temp_cols;

	for (int i = 0; i <= _w; i++) {
		temp_cols.push_back(i + 1);
	}

	while (!is_selected && temp_cols.size() > 0)
	{
		/* initialize random seed: */
		srand(time(NULL));

		/* generate secret number between 1 and 10: */
		int col_id = rand() % (temp_cols.size());
		selected_col = temp_cols[col_id];

		for (int j = _h - 1; j > -1; j--)
		{
			int id = selected_col + j * _w - 1;
			if (boardState[id] == 0)//Empty
			{
				is_selected = true;
				ret = id;

				std::cout << selected_col << "\\n";
				break;
			}
		}

		temp_cols.erase(temp_cols.begin() + col_id);
	}

	return ret;
}