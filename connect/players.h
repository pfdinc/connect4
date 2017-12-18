// players.h

#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#pragma once

class Player
{
public:
	enum PlayerType { UNDEFINED, HumanPlayer, AiPlayer};

	Player();
	virtual ~Player();

	virtual int getNextTurn(int boardState[], int _w, int _h) = 0;

	// Identify which type of player this is.
	virtual int getPlayerType();
	virtual void setPlayerType(PlayerType p_type);

protected:
	// Type of actor.
	PlayerType player_type;

private:

};

class HumanPlayer: public Player
{
public:
	HumanPlayer();
	virtual ~HumanPlayer();

	virtual int getNextTurn(int boardState[], int _w, int _h);

private:

};

class AiPlayer: public Player
{
public:
	AiPlayer();
	virtual ~AiPlayer();

	virtual int getNextTurn(int boardState[], int _w, int _h);

private:

};

#endif