/* 
    File: player.cpp

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

*/

#ifndef _player_CPP_                   // include file only once
#define _player_CPP_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "player.h"
#include <iostream>

using namespace std;
/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

void Player::print(){
	cout<<"----------------------------------------\n";
	cout<<"Player Name: "<<player_name<<"\tID: "<<player_ID<<"\tTotal Achievement Points: "<<total_achieve_points;
	cout<<"\nGames:\n";
	for(int i = 0; i < games.size(); i++){
		cout<<i+1<<": ";games[i].print();
	}
	cout<<"Friends:\n";
	for(int i = 0; i < friends.size(); i++){
		cout<<i+1<<": "<<friends[i]<<endl;
	}
	cout<<"----------------------------------------\n";
}

bool Player::empty(){
	if(player_name == "NO_NAME" && player_ID == 0){
		return true;
	}
	else{
		return false;
	}
}

Player::Player(int _player_ID, std::string _player_name, int _total_achieve_points, std::vector<Game> _games, std::vector<std::string> _friends){
		player_ID = _player_ID;
		player_name = _player_name;
		total_achieve_points = _total_achieve_points;
		games = _games;
		friends = _friends;
	}

Player::Player(int _player_ID, std::string _player_name){
		player_ID = _player_ID;
		player_name = _player_name;
		total_achieve_points = 0;
		//no games or friends
}
	
Player::Player(){
		player_ID = 0;
		player_name = "NO_NAME";
		total_achieve_points = 0;
}

#endif


