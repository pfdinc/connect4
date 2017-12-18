// game.cpp

#include "game.h"

Game::Game(Player &p1, Player &p2)
{
	m_curState = GameState::TurnP1;
	for (int i = 0; i < BoardHeight * BoardWidth; i++)
		m_BoardState[i] = (int)(BoardField::Empty);

	player1 = &p1;
	player2 = &p2;
}

Game::~Game()
{
	//delete player1;
	//delete player2;
}

bool Game::isRunning()
{
	bool ret = m_curState < GameState::P1Won;

	return ret;
}

BoardField Game::operator() (int x, int y) const
{
	int pos = y * BoardWidth + x;

	BoardField result = (BoardField)m_BoardState[pos];
	return result;
}
//performs the next turn
void Game::nextTurn()
{
	int sel_pos;

	switch (m_curState)
	{
	case TurnP1:
		sel_pos = player1->getNextTurn(m_BoardState, BoardWidth, BoardHeight);
		if (sel_pos > -1){
			m_BoardState[sel_pos] = (int)Player1;
		}
		count++;
		break;
	case TurnP2:
		sel_pos = player2->getNextTurn(m_BoardState, BoardWidth, BoardHeight);
		if (sel_pos > -1){
			m_BoardState[sel_pos] = (int)Player2;
		}
		count++;
		break;
	default:
		break;
	}

	determineGameState();
}
//get the current state of the game
GameState Game::getState()
{
	return m_curState;
}
//determine current game status and set it's value 
void Game::determineGameState()
{
	GameState ret = m_curState;

	int		global_size = BoardWidth * BoardHeight;
	int		empty_size = 0;

	for (int i = 0; i < global_size; i++)
	{
		if (m_BoardState[i] == 0)//Empty
		{
			empty_size++;
		}
	}

	if (count == global_size)
		ret = GameState::Draw;

	bool is_exist_count4 = false;
	BoardField obj_board;
	GameState final_won;

	if (m_curState == GameState::TurnP1){
		obj_board = BoardField::Player1;
		ret = GameState::TurnP2;
		final_won = GameState::P1Won;
	}
	else if (m_curState == GameState::TurnP2){
		obj_board = BoardField::Player2;
		ret = GameState::TurnP1;
		final_won = GameState::P2Won;
	}
	//check if there exists count 4
	for (int i = 0; i < global_size; i++)
	{
		//check row
		if ((i % BoardWidth) < (BoardWidth - 3)){
			int count = 0;
			for (int j = 0; j < 4; j++){
				if (m_BoardState[i + j] == obj_board)
					count++;
			}

			if (count == 4)
			{
				is_exist_count4 = true;
				break;
			}
		}
		//check col
		if ((i / BoardWidth) < (BoardHeight - 3)){
			int count = 0;
			for (int j = 0; j < 4; j++){
				if (m_BoardState[i + j * BoardWidth] == obj_board)
					count++;
			}

			if (count == 4)
			{
				is_exist_count4 = true;
				break;
			}
		}
		//check right diagonal
		if ((i % BoardWidth) < (BoardWidth - 3) && (i / BoardWidth) < (BoardHeight - 3)){
			int count = 0;
			for (int j = 0; j < 4; j++){
				if (m_BoardState[i + j * BoardWidth + j] == obj_board)
					count++;
			}

			if (count == 4)
			{
				is_exist_count4 = true;
				break;
			}
		}
		//check left diagonal
		if ((i % BoardWidth) > 2 && (i / BoardWidth) < (BoardHeight - 3)){
			int count = 0;
			for (int j = 0; j < 4; j++){
				if (m_BoardState[i + j * BoardWidth - j] == obj_board)
					count++;
			}

			if (count == 4)
			{
				is_exist_count4 = true;
				break;
			}
		}
	}

	if (is_exist_count4)
		ret = final_won;

	if (count == global_size)
		ret = GameState::Draw;
	//set result game state 
	m_curState = ret;
}