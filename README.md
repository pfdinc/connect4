The goal of this lab is to program the game Connect Four. See [1] if you are unfamiliar with the game.
You are already given a  le main.cpp (which you may not change). You have to implement the remaining of the game. 
Next to the main.cpp, your program should contain the  les game.h, game.cpp, players.h, and players.cpp.
The  le game.h should de ne an enumeration GameState which represents the possible game states, an enumeration 
BoardField which represents the possible state of a  eld of the game-board, and the class Game. The  le players.h 
should de ne an abstract class Player, a class HumanPlayer, and a class AiPlayer. The classes HumanPlayer and AiPlayer 
should be subclasses of the class Player. The header  les should only contain declarations. All class members should only
be implemented in the corresponding .cpp  les.

Player Classes
Player. The abstract class Player de nes the interface which is used by the Game class. It should contain a pure virtual function getNextTurn which 
takes as parameter the current game (to read the game state and board) and return an integer in the range from 1 to 7 representing the column in which 
the player puts its next stone.HumanPlayer. Represents a human player. Its function getNextTurn should read an integer from the terminal and return it. 
It may not create any output!AiPlayer. Represents a non-human player. Its function getNextTurn should determine in which column the player can add its 
next stone. Then, out of all possible columns, one is picked randomly and returned. It also outputs the selected column together with a newline) to the terminal,
i. e., if column 3 is selected, the output should be "3\n".


Game Class
The class Game contain the logic for the game. It determines if turns of players are valid, 
keeps track of the board, determines if a player has won, and updates its state accordingly. The class should have the members listed below. Feel free to add additional private members.
BoardWidth. A public constant with the value 7.
BoardHeight. A public constant with the value 6.
Game(Player &p1, Player &p2). Public constructor which takes the players of the game as
arguments
getState(). A public function which returns the current state of the game.
isRunning(). A public function which returns true if the game is still running, or false if the game
concluded with either a draw or a player winning.
operator() (int x, int y) const. Publicly overrides the ()-operator. Returns the state at the board at 
the given coordinate. The top left element has coordinate (0, 0). Returns Empty if the coordinate is out of 
range of the board.
nextTurn(). Public function which performs the next turn. To do so, the Game class calls the function getNextTurn
of the current player. If the return value is invalid, nothing should happen. Otherwise, the function should process
the move of the player. That is, it should update the board, determine if the player won or if a draw was reached, and 
update the game state accordingly.
