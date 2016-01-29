/* 
    File: main.H

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/29/16

*/

#ifndef _main_H_                   // include file only once
#define _main_H_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "achieve.h"
#include "game.h"
#include "player.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

/*--------------------------------------------------------------------------*/
/* PRINT FUNCTIONS */
/*--------------------------------------------------------------------------*/

//print out global database of players for debugging
void print_players();

//print out global database of games for debugging
void print_games();

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION DECLERATIONS */
/*--------------------------------------------------------------------------*/

//adds player to global database of players
int AddPlayer(int player_ID, string player_name);

//adds game to global database of games
int AddGame(int game_ID, string game_name);

//adds achievement to appropriate game in global database of games
int AddAchievement(int game_ID, int achieve_ID, string achieve_name, int achieve_point);

//adds game to appropriate player in global database of players, w/player IGN
int Plays(int player_ID, int game_ID, string player_IGN);

//adds mutually exclusive friend name strings to each appropriate player's friends list in global database of players
int AddFriends(int player_ID1, int player_ID2);

//adds achieve for appropriate player in appropriate game and updates gamerscores
int Achieve_funct(int player_ID, int game_ID, int achieve_ID);

//lists friends who play specified game for appropriate player
int FriendsWhoPlay(int player_ID, int game_ID);

//prints appropriate players stats such as gamerscore and amount of achievements earned for the appropriate game
int ComparePlayers(int player_ID1, int player_ID2, int game_ID);

//prints appropriate player's info such as gamerscore, game stats and friends lists
int SummarizePlayer(int player_ID);

//prints all players who play appropriate game and all the stats with it
int SummarizeGame(int game_ID);

//prints all players who have earned this achievement and percentage who earned within this game
int SummarizeAchievement(int game_ID, int achieve_ID);

//ranks players by their gamerscore and achievements earned
int AchievementRanking();

//a test function written seperately of standard input to test all the main functions
void test_main();

#endif
