// game.h

#ifndef _GAME_H_
#define _GAME_H_

#pragma once

#include "players.h"

enum BoardField {Empty,	Player1, Player2};

enum GameState {TurnP1, TurnP2, P1Won, P2Won, Draw};

class Game
{
public:

	int count;

	Game(Player &p1, Player &p2);
	~Game();

	bool isRunning();
	BoardField operator() (int x, int y) const;
	void nextTurn();
	GameState getState();
	void determineGameState();

	static const int BoardHeight = 6;
	static const int BoardWidth = 7;

private:
	GameState m_curState;
	int m_BoardState[BoardWidth * BoardHeight];

	Player* player1;
	Player* player2;
};

#endif