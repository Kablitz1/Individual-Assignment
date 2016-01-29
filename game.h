/* 
    File: game.H

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

*/

#ifndef _game_H_                   // include file only once
#define _game_H_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <vector>
#include <string>
#include "achieve.h"

/*--------------------------------------------------------------------------*/
/* CLASS */
/*--------------------------------------------------------------------------*/


class Game{
private:

//members:

//unique integer identifier for each game
	int game_ID;
	
//string identifier for each game
	std::string game_name;
	
//string identifier for player IGN for this particular game
	std::string player_IGN;
	
//vector of Achieve to keep track of achievements within this game
	std::vector<Achieve> achievements;
	
//total gamerscore for player for this particular game
	int game_points;
	
//number of achievements earned for player within this game
	int num_achieve_earned;
	
public:

//constructors:

	Game(int _game_ID, std::string _game_name, std::string _player_IGN, std::vector<Achieve> _achievements);
	
	Game(int _game_ID, std::string _game_name);
	
	Game();
	
//get functions:

	int get_game_ID(){return game_ID;}
	std::string get_game_name(){return game_name;}
	std::string get_player_IGN(){return player_IGN;}
	std::vector<Achieve> get_achievements(){return achievements;}
	int get_game_points(){return game_points;}
	int get_num_achieve_earned(){return num_achieve_earned;}
	
	
//set functions:

	void set_game_ID(int _game_ID){game_ID = _game_ID;}
	void set_game_name(std::string _game_name){game_name = _game_name;}
	void set_player_IGN(std::string _player_IGN){player_IGN = _player_IGN;}
	void set_achievements(std::vector<Achieve> _achievements){achievements = _achievements;}
	void set_game_points(int _game_points){game_points = _game_points;}
	void set_num_achieve_earned(int _num_achieve_earned){num_achieve_earned = _num_achieve_earned;}
	
//add functions (for both increment and vector push_back):

	void add_achievements(Achieve achieve_add_temp){achievements.push_back(achieve_add_temp);}
	void add_num_achieve_earned(){num_achieve_earned++;}
	
//print functions for debugging:

	void print();
	
//check if member is empty:

	bool empty();
};

#endif


