/* 
    File: player.H

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

*/

#ifndef _player_H_                   // include file only once
#define _player_H_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <string>
#include <vector>
#include <algorithm>

#include "achieve.h"
#include "game.h"

/*--------------------------------------------------------------------------*/
/* CLASS */
/*--------------------------------------------------------------------------*/

class Player{
private:

//members:

//unique integer identifier for each player
	int player_ID;
	
//name identifier for each player
	std::string player_name;
	
//total amount of achievemnt points across all games earned
	int total_achieve_points;
	
//vector of Games, holds stats pertaining to each game within
	std::vector<Game> games;
	
//vector of strings, simply keeps track of friends of player
	std::vector<std::string> friends;

public:

//constructors:

	Player(int _player_ID, std::string _player_name, int _total_achieve_points, std::vector<Game> _games, std::vector<std::string> _friends);

	Player(int _player_ID, std::string _player_name);
	
	Player();
	
//get functions:

	int get_player_ID(){return player_ID;}
	std::string get_player_name(){return player_name;}
	int get_total_achieve_points(){return total_achieve_points;}
	std::vector<Game> get_games(){return games;}
	std::vector<std::string> get_friends(){return friends;}
	
//set functions:

	void set_player_ID(int _player_ID){player_ID = _player_ID;}
	void set_player_name(std::string _player_name){player_name = _player_name;}
	void set_total_achieve_points(int _total_achieve_points){total_achieve_points = _total_achieve_points;}
	void set_games(std::vector<Game> _games){games = _games;}
	void set_friends(std::vector<std::string> _friends){friends = _friends;}
	
//add functions for vector push_back:

	void add_games(Game game_add_temp){games.push_back(game_add_temp);}
	void add_friends(std::string friend_add_temp){friends.push_back(friend_add_temp);}
	
//print functions for debugging:

	void print();	
	
//empty check function for member:

	bool empty();
};
	
#endif


