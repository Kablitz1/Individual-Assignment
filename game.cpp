/* 
    File: game.cpp

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

*/

#ifndef _game_CPP_                   // include file only once
#define _game_CPP_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "game.h"
#include <iostream>

using namespace std;
/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

void Game::print(){
	//cout<<"----------------------------------------\n";
	cout<<"Game Name: "<<game_name<<"\tID: "<<game_ID<<"\tPlayer IGN: "<<player_IGN<<"\tAchieve Points: "<<game_points<<endl;
	cout<<"\tAchievements:\n";
	for(int i = 0; i < achievements.size(); i++){
		cout<<'\t'<<i+1<<": ";achievements[i].print();
	}
	//cout<<"----------------------------------------\n";
}

bool Game::empty(){
	if(game_name == "NO_NAME" && game_ID == 0){
		return true;
	}
	else{
		return false;
	}
}

Game::Game(int _game_ID, std::string _game_name, std::string _player_IGN, std::vector<Achieve> _achievements){
		game_ID = _game_ID;
		game_name = _game_name;
		player_IGN = _player_IGN;
		achievements = _achievements;
		game_points = 0;
		num_achieve_earned = 0;
	}
	
Game::Game(int _game_ID, std::string _game_name){
		game_ID = _game_ID;
		game_name = _game_name;
		player_IGN = "NO_NAME";
		game_points = 0;
		num_achieve_earned = 0;
	}
	
Game::Game(){
		game_ID = 0;
		game_name = "NO_NAME";
		player_IGN = "NO_IGN";
		game_points = 0;
		num_achieve_earned = 0;
	}

#endif


