/* 
    File: main.cpp

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

    main program for Individual Assignment
*/

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "main.h"

/*--------------------------------------------------------------------------*/
/* GLOBAL DATA STORAGE */ 
/*--------------------------------------------------------------------------*/

//global data storage, does not transfer across sessions
	vector<Player> data_players;
	vector<Game> data_games;
	
/*--------------------------------------------------------------------------*/
/* PRINT FUNCTIONS */
/*--------------------------------------------------------------------------*/
void print_players(){
	for(int i = 0; i < data_players.size(); i++){
		data_players[i].print();
	}
}

void print_games(){
	for(int i = 0; i < data_games.size(); i++){
		data_games[i].print();
	}
}
/*--------------------------------------------------------------------------*/
/* COMMAND FUNCTIONS */
/*--------------------------------------------------------------------------*/

int AddPlayer(int player_ID, string player_name){
//error checking for already there
	for(int i = 0; i < data_players.size(); i++){
		if(data_players[i].get_player_ID() == player_ID){
			cerr<<"AddPlayer_ERROR:: player_ID: "<<player_ID<<" already found, "<<player_ID<<" NOT added\n";
			return -1;
		}
	}
	
	data_players.push_back( Player(player_ID, player_name) );
	cout<<"AddPlayer:: player: "<<player_ID<<" Inserted\n";
}


int AddGame(int game_ID, string game_name){
//error checking for already there
	for(int i = 0; i < data_games.size(); i++){
		if(data_games[i].get_game_ID() == game_ID){
			cerr<<"AddGame_ERROR:: game_ID: "<<game_ID<<" already found, "<<game_ID<<" NOT added\n";
			return -1;
		}
	}
	data_games.push_back( Game(game_ID, game_name) );
	cout<<"AddGame:: Game: "<<game_ID<<" Inserted\n";
}


int AddAchievement(int game_ID, int achieve_ID, string achieve_name, int achieve_point){
//error checking for achieve_ID already there
	for(int i = 0; i < data_games.size(); i++){
		if(data_games[i].get_game_ID() == game_ID){
			vector<Achieve> vec_achieve_temp = data_games[i].get_achievements();
			for(int j = 0; j < vec_achieve_temp.size(); j++){
				if(vec_achieve_temp[j].get_achieve_ID() == achieve_ID){
					cerr<<"AddAchievement_ERROR:: achieve_ID: "<<achieve_ID<<" already found, "<<achieve_ID<<" NOT added\n";
					return -1;
				}
			}
		}
	}
//temp variable
	Achieve achieve_add_temp(achieve_name, achieve_ID, achieve_point);
//add achieve	
	for(int i = 0; i < data_games.size(); i++){
		if(data_games[i].get_game_ID() == game_ID){
			data_games[i].add_achievements(achieve_add_temp);
			cout<<"AddAchievement:: Achieve: "<<achieve_add_temp.get_achieve_ID()<<" Inserted\n";
			return 1;
		}
	}
//if get here, then game_ID not found
	cerr<<"AddAchievement_ERROR:: game_ID: "<<game_ID<<"or achieve_ID: "<<achieve_ID<<" NOT found "<<achieve_ID<<" NOT added\n";
	return -1;	
}


int Plays(int player_ID, int game_ID, string player_IGN){
//error checking if game is already there for the player
	for(int i = 0; i < data_players.size(); i++){
		//finding player
		if(data_players[i].get_player_ID() == player_ID){

			//temp vector for easy read
			vector<Game> game_vector_found = data_players[i].get_games();
			//finding game
			for(int j = 0; j < game_vector_found.size(); j++){
				if(game_vector_found[j].get_game_ID() == game_ID){
					//error check, game is already there
					cerr<<"Player_ID: "<<player_ID<<" Already has game_ID: "<<game_ID<<" NOT inserted\n";
					return -1;
				}
			}
		}
	}
	
//now insert game for player with appropriate player_IGN
	Game game_insert_found;
	for(int i = 0; i < data_games.size(); i++){
		//finding game to be inserted from the global database
		if(data_games[i].get_game_ID() == game_ID){
			data_games[i].set_player_IGN(player_IGN);
			//update IGN for temp game to be inserted
			game_insert_found.set_player_IGN(player_IGN);
			game_insert_found = data_games[i];
		}
	}
	for(int i = 0; i < data_players.size(); i++){
		//finding player
		if(data_players[i].get_player_ID() == player_ID){
			//insert game for particular player
			data_players[i].add_games(game_insert_found);	
			cout<<"Plays:: player_ID: "<<player_ID<<" Successful\n"; 
			return 1;
		}
	}
	cerr<<"Plays_ERROR:: player_ID: "<<player_ID<<" OR game_ID: "<<game_ID<<" NOT found\n";
			return -1;
}


int AddFriends(int player_ID1, int player_ID2){
//getting each players list of friends
	Player player_temp1; 
		vector<string> friends_temp1;
	Player player_temp2; 
		vector<string> friends_temp2;
	for(int i = 0; i < data_players.size(); i++){
		if(data_players[i].get_player_ID() == player_ID1){
			player_temp1 = data_players[i];
			friends_temp1 = data_players[i].get_friends();
		}
		if(data_players[i].get_player_ID() == player_ID2){
			player_temp2 = data_players[i];
			friends_temp2 = data_players[i].get_friends();
		}
	}
//error checking to see if friends are already added in eachothers list
	for(int i = 0; i < friends_temp1.size(); i++){
		if(!player_temp2.empty()){
			if(friends_temp1[i] == player_temp2.get_player_name()){
				cerr<<"AddFriends_ERROR:: player_ID1: "<<player_ID1<<" already has friend with player_ID2: "<<player_ID2<<endl;
				return -1;
			}
		}
	}	
	for(int i = 0; i < friends_temp2.size(); i++){
		if(!player_temp1.empty()){
			if(friends_temp2[i] == player_temp1.get_player_name()){
				cerr<<"AddFriends_ERROR:: player_ID2: "<<player_ID2<<" already has friend with player_ID1: "<<player_ID1<<endl;
				return -1;
			}
		}
	}
	
//error check for empty temps
	if(player_temp1.empty() || player_temp2.empty()){
		cerr<<"AddFriends_ERROR:: player_ID1: "<<player_ID1<<" or player_ID2: "<<player_ID2<<" NOT found, friend connection not made"<<endl;
		return -1;
	}
	else{
//if passes error check, then update eachothers list
		for(int i = 0; i < data_players.size(); i++){
			if(data_players[i].get_player_ID() == player_ID1){
				data_players[i].add_friends(player_temp2.get_player_name());
				cout<<"AddFriends:: Player_ID1: "<<player_ID1<<" Successful link"<<endl;
			}
			if(data_players[i].get_player_ID() == player_ID2){
				data_players[i].add_friends(player_temp1.get_player_name());
				cout<<"AddFriends:: Player_ID2: "<<player_ID2<<" Successful link"<<endl;
			}
		}
		return 1;
	}
}

 
int Achieve_funct(int player_ID, int game_ID, int achieve_ID){
//searching for appropriate player
	for(int i = 0; i < data_players.size(); i++){
		if(data_players[i].get_player_ID() == player_ID){

//searching for appropriate game		
			vector<Game> games_vec_temp = data_players[i].get_games();
			for(int j = 0; j < games_vec_temp.size(); j++){
				if(!games_vec_temp[j].empty()){
					if(games_vec_temp[j].get_game_ID() == game_ID){
						
//searching for appropriate achieve
						vector<Achieve> achieve_vec_temp = games_vec_temp[j].get_achievements();
						for(int k = 0; k < achieve_vec_temp.size(); k++){
							if(!achieve_vec_temp[k].empty()){
								if(achieve_vec_temp[k].get_achieve_ID() == achieve_ID){
//checking if achieve already earned
									if(achieve_vec_temp[k].get_achieve_earned() == false){
//activating achieve and adding points to both total player points and individual game points
										achieve_vec_temp[k].set_achieve_earned(true);
										
//adding to total for player							
										int total_achieve_pts_temp = data_players[i].get_total_achieve_points();
										total_achieve_pts_temp += achieve_vec_temp[k].get_achieve_points();
										data_players[i].set_total_achieve_points(total_achieve_pts_temp);
										
//adding to individual game	total			
										int game_ach_pts_tmp = games_vec_temp[j].get_game_points();
										game_ach_pts_tmp += achieve_vec_temp[k].get_achieve_points();
										games_vec_temp[j].set_game_points(game_ach_pts_tmp);
										games_vec_temp[j].add_num_achieve_earned();
										
//updating game with achieve tmps reinserted
										games_vec_temp[j].set_achievements(achieve_vec_temp);
										
//updating player with game tmps reinserted
										data_players[i].set_games(games_vec_temp);
										cout<<"Achieve_funct:: achieve_ID: "<<achieve_ID<<" Earned\n";
										return 1;
									}
									else{
										cerr<<"Achieve_ERROR:: achieve_ID: "<<achieve_ID<<" ALREADY earned, achieve_ID: "<<achieve_ID<<" NOT inserted\n";
										return -1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
//error checking if not found		
	cerr<<"Achieve_ERROR:: player_ID: "<<player_ID<<" NOT found, achieve_ID: "<<achieve_ID<<" NOT inserted\n";
	return -1;
}

int FriendsWhoPlay(int player_ID, int game_ID){
//temp assigns
	vector<string> friends_strings;
	vector<string> friends_who_play;
	vector<Player> friends_players;
	
//search for appropriate player
	for(int i = 0; i < data_players.size(); i++){
		if(data_players[i].get_player_ID() == player_ID){	
//assign string of friends to temp vector
			friends_strings = data_players[i].get_friends();
		}			
	}
	
//search through friends string vector to find player matches and insert into temp vector
	for(int i = 0;  i < friends_strings.size(); i++){
		for(int j = 0; j < data_players.size(); j++){
			if(data_players[j].get_player_name() == friends_strings[i]){
				friends_players.push_back(data_players[j]);
			}
		}
	}
	
//now for these player matches, search through their games for game_ID, if match add to friends_who_play
	for(int i = 0; i < friends_players.size(); i++){
		for(int j = 0; j < friends_players[i].get_games().size(); j++){
			if(friends_players[i].get_games()[j].get_game_ID() == game_ID){
				friends_who_play.push_back(friends_players[i].get_player_name());
			}
		}
	}
	
//print out friends_who_play
	cout<<"-------------Friends Who Play BEGIN-------------\n";
	for(int i = 0; i < friends_who_play.size(); i++){
		cout<<i+1<<": "<<friends_who_play[i]<<endl;
	}
	cout<<"-------------Friends Who Play END-------------\n";
	
//return vector of friends player_ID for other functions
}


int ComparePlayers(int player_ID1, int player_ID2, int game_ID){
//temp values for players/games found
	Player player1, player2;
	Game game1, game2;
//find players
	for(int i = 0; i < data_players.size(); i++){
		if(data_players[i].get_player_ID() == player_ID1){
			player1 = data_players[i];
		}
		if(data_players[i].get_player_ID() == player_ID2){
			player2 = data_players[i];
		}
	}
	
//find specificied game for each player
	if(!player1.empty()){
		for(int i = 0; i < player1.get_games().size(); i++){
			if(player1.get_games()[i].get_game_ID() == game_ID){
				game1 = player1.get_games()[i];
			}
		}
	}
	if(!player2.empty()){
		for(int i = 0; i < player2.get_games().size(); i++){
			if(player2.get_games()[i].get_game_ID() == game_ID){
				game2 = player2.get_games()[i];
			}
		}
	}

	
	if(!player1.empty() && !player2.empty() && !game1.empty() && !game2.empty()){
		cout<<"-------------Compare Players BEGIN-------------\n";
		
		cout<<"Player: "<<player1.get_player_name()<<" Total Gamerscore: "<<player1.get_total_achieve_points()<<endl;
		cout<<"Game: "<<game1.get_game_name()<<setw(15)<<" Gamerscore: "<<game1.get_game_points()<<endl;
		
		cout<<"    Achievement Name"<<setw(20)<<"Earned?(1 or 0)\n";
		cout<<"-----------------------------------------------------------------------------\n";
		for(int i = 0; i < game1.get_achievements().size(); i++){
			cout<<i+1<<". "<<game1.get_achievements()[i].get_name()<<"\t\t\t"<<game1.get_achievements()[i].get_achieve_earned()<<endl;
		}
		cout<<endl;
		
		cout<<"Player: "<<player2.get_player_name()<<" Total Gamerscore: "<<player2.get_total_achieve_points()<<endl;
		cout<<"Game: "<<game2.get_game_name()<<setw(15)<<" Gamerscore: "<<game2.get_game_points()<<endl;
		
		cout<<"    Achievement Name"<<setw(20)<<"Earned?(1 or 0)\n";
		cout<<"-----------------------------------------------------------------------------\n";
		for(int i = 0; i < game2.get_achievements().size(); i++){
			cout<<i+1<<". "<<game2.get_achievements()[i].get_name()<<setw(20)<<game2.get_achievements()[i].get_achieve_earned()<<endl;
		}
		
		cout<<"-------------Compare Players END-------------\n";
		return 1;
	}
	else{
		cerr<<"ComparePlayers_ERROR:: player_ID1: "<<player_ID1<<" or player_ID2: "<<player_ID2<<" NOT found. \n";
		return -1;
	}
}


int SummarizePlayer(int player_ID){
	Player player1;
//find player
	for(int i = 0; i < data_players.size(); i++){
		if(data_players[i].get_player_ID() == player_ID){
			player1 = data_players[i];
		}
	}
	
	if(!player1.empty()){
		cout<<"-------------SummarizePlayer BEGIN-------------\n";
		
		cout<<"Player: "<<player1.get_player_name()<<" Total Gamerscore: "<<player1.get_total_achieve_points()<<endl;
		cout<<endl<<"    Game"<<setw(20)<<"Achievements"<<setw(16)<<"Gamerscore"<<setw(14)<<"IGN"<<setw(20)<<endl;
		cout<<"-----------------------------------------------------------------------------\n";
		
		for(int i = 0; i < player1.get_games().size(); i++){
			cout<<i+1<<". "<<player1.get_games()[i].get_game_name()<<setw(18);
			cout<<player1.get_games()[i].get_num_achieve_earned()<<'/'<<player1.get_games()[i].get_achievements().size()<<setw(10);
			cout<<player1.get_games()[i].get_game_points()<<setw(4)<<" pts"<<setw(13);
			cout<<'"'<<player1.get_games()[i].get_player_IGN()<<'"'<<endl;
		}
		
		cout<<endl<<"    Friend"<<setw(20)<<"Gamerscore"<<setw(16)<<endl;
		cout<<"-----------------------------------------------------------------------------\n";

//find friends by name, insert for gamerscore
		vector<Player> friends_for_player;
		for(int i = 0; i < player1.get_friends().size(); i++){
			for(int j = 0; j < data_players.size(); j++){
				if(data_players[j].get_player_name() == player1.get_friends()[i]){
					friends_for_player.push_back(data_players[j]);
				}
			}
		}
		
		for(int i = 0; i < player1.get_friends().size(); i++){
			cout<<i+1<<".  "<<friends_for_player[i].get_player_name()<<setw(15)<<friends_for_player[i].get_total_achieve_points()<<setw(4)<<" pts\n";
		}
		
		
		cout<<"-------------SummarizePlayer END-------------\n";
		return 1;
	}
	else{
		cerr<<"SummarizePlayer_ERROR:: player_ID: "<<player_ID<<" NOT found. \n";
		return -1;
	}
}


int SummarizeGame(int game_ID){
//find all players who play this game, put into vector
	vector<Player> players_who_play;
	for(int i = 0; i < data_players.size(); i++){
		for(int j = 0; j < data_players[i].get_games().size(); j++){
			if(data_players[i].get_games()[j].get_game_ID() == game_ID){
				players_who_play.push_back(data_players[i]);
			}
		}
	}
	
	if(players_who_play.size() == 0){
		cerr<<"SummarizeGame_ERROR:: game_ID: "<<game_ID<<" NOT found for any players\n";
		return -1;
	}
	
//print players who play game, and how many achieves each have earned for that game
	cout<<"-------------SummarizeGame BEGIN-------------\n";
	
	Game game1;
	for(int i = 0; i < data_games.size(); i++){
		if(data_games[i].get_game_ID() == game_ID){
			game1 = data_games[i];
		}
	}
	cout<<"Game: "<<game1.get_game_name()<<endl;
	cout<<"    Player"<<setw(20)<<"Achievements\n";
	cout<<"-----------------------------------------------------------------------------\n";
	for(int i = 0; i < players_who_play.size(); i++){
		for(int j = 0; j < players_who_play[i].get_games().size(); j++){
			if(players_who_play[i].get_games()[j].get_game_ID() == game_ID){
				cout<<i+1<<". "<<players_who_play[i].get_player_name()<<setw(20);
				cout<<players_who_play[i].get_games()[j].get_num_achieve_earned()<<'/'<<players_who_play[i].get_games()[j].get_achievements().size()<<endl;
			}
		}
	}
	cout<<"-------------SummarizeGame END------------\n";
}


int SummarizeAchievement(int game_ID, int achieve_ID){
//player vector for players with this game_ID and achieve_ID earned
	vector<Player> players_w_game;
	vector<Player> players_w_achieve;
//search game	
	for(int i = 0; i < data_players.size(); i++){
		for(int j = 0; j < data_players[i].get_games().size(); j++){
			if(data_players[i].get_games()[j].get_game_ID() == game_ID){
				players_w_game.push_back(data_players[i]);
			}
		}
	}
	
//error checking for players_w_game
	if(players_w_game.size() == 0){
		cerr<<"SummarizeAchievement_ERROR:: game_ID: "<<game_ID<<" NOT found for any players\n";
		return -1;
	}
	
//search achieve and earned
	for(int i = 0; i < players_w_game.size(); i++){
		for(int j = 0; j < players_w_game[i].get_games().size(); j++){
			if(players_w_game[i].get_games()[j].get_game_ID() == game_ID){
				for(int k = 0; k < players_w_game[i].get_games()[j].get_achievements().size(); k++)
					if(players_w_game[i].get_games()[j].get_achievements()[k].get_achieve_ID() == achieve_ID
						&& players_w_game[i].get_games()[j].get_achievements()[k].get_achieve_earned() == true){
						
							players_w_achieve.push_back(players_w_game[i]);
					}
				}
			}
		}


	cout<<"-------------SummarizeAchievement BEGIN------------\n";
	
	float percent_player_achieve = ((float)players_w_achieve.size()/(float)players_w_game.size())*100;
	cout<<"% of Players who have this Achievement: "<<percent_player_achieve<<'%'<<endl;
	
	cout<<"Players who have earned Achievement: "<<achieve_ID<<" In Game: "<<game_ID<<endl;
	for(int i = 0; i < players_w_achieve.size(); i++){
		cout<<i+1<<". "<<players_w_achieve[i].get_player_name()<<endl;
	}
	
	cout<<"-------------SummarizeAchievement END------------\n";
}

int AchievementRanking(){
//first create a temp player vector and sort by total achieve points
	vector<Player> temp_data_players = data_players;
	
//bubble sort by total_achieve_pts
	bool swapped = true;
	int j = 0;
	Player tmp;
	while(swapped){
		swapped = false; j++;
		for(int i = 0; i < temp_data_players.size() - j; i++){
			if(temp_data_players[i].get_total_achieve_points() < temp_data_players[i+1].get_total_achieve_points()){
				tmp = temp_data_players[i];
				temp_data_players[i] = temp_data_players[i+1];
				temp_data_players[i+1] = tmp;
				swapped = true;
			}
		}
	}
	
	
	cout<<"-------------Achievement Ranking BEGIN------------\n";
	cout<<"Rank Player"<<setw(20)<<"Gamerscore\n";
	cout<<"-----------------------------------------------------------------------------\n";
	for(int i = 0; i < temp_data_players.size(); i++){
		cout<<i+1<<". "<<setw(10)<<temp_data_players[i].get_player_name()<<setw(15)<<temp_data_players[i].get_total_achieve_points()<<endl;
	}
	
	
	cout<<"-------------Achievement Ranking END------------\n";
}

void test_main(){
	cout<<"AddPlayer TEST:: ***********\n";
	AddPlayer(1, "player1");
	AddPlayer(2, "player2");
	AddPlayer(3, "player3");
	AddPlayer(4, "player4");
	
	AddPlayer(1, "test1");
	//print_players();
	
	cout<<"AddGame TEST:: ***********\n";
	AddGame(5, "game5");
	AddGame(6, "game6");
	AddGame(7, "game7");
	AddGame(8, "game8");
	
	AddGame(5, "test5");
	//print_games();
	
	cout<<"AddAchievement TEST:: ***********\n";
	AddAchievement(5, 10, "achieve10", 10);
	AddAchievement(6, 10, "achieve10", 10);
	AddAchievement(7, 10, "achieve10", 10);
	AddAchievement(8, 10, "achieve10", 10);
	
	AddAchievement(5, 11, "achieve11", 11);
	AddAchievement(6, 11, "achieve11", 11);
	AddAchievement(7, 11, "achieve11", 11);
	AddAchievement(8, 11, "achieve11", 11);
	
	AddAchievement(5, 10, "test10", 10);
	AddAchievement(5, 11, "test11", 11);
	//print_games();
	
	cout<<"Plays TEST:: ***********\n"; 
	Plays(1, 5, "pl1_gm5");
	Plays(2, 6, "pl2_gm6");
	Plays(3, 7, "pl1_gm7");
	Plays(4, 8, "pl1_gm5");
	
	Plays(2, 5, "pl2_gm5");
	Plays(3, 5, "pl3_gm5");
	Plays(4, 5, "pl4_gm5");
	
	Plays(9, 22, "TEST");
	//print_players();
	
	cout<<"AddFriends TEST:: ***********\n"; 
	AddFriends(1, 2);
	AddFriends(1, 3);
	AddFriends(1, 4);
	
	AddFriends(2, 1);
	//print_players();
	
	cout<<"Achieve_funct TEST:: ***********\n"; 
	Achieve_funct(1, 5, 10);
	Achieve_funct(1, 5, 11);
	Achieve_funct(2, 6, 10);
	
	Achieve_funct(1, 5, 10);
	//print_players();
	
	cout<<"FriendsWhoPlay TEST:: ***********\n";
	FriendsWhoPlay(1, 5);
	FriendsWhoPlay(2, 5);
	//print_players();
	
	cout<<"ComparePlayers TEST:: ***********\n";
	ComparePlayers(1, 2, 5);
	ComparePlayers(3, 4, 6);
	ComparePlayers(5, 6, 7);
	
	cout<<"SummarizePlayer TEST:: ***********\n";
	SummarizePlayer(1);
	SummarizePlayer(2);
	SummarizePlayer(5);
	
	cout<<"SummarizeGame TEST:: ***********\n";
	SummarizeGame(5);
	SummarizeGame(11);
	
	cout<<"SummarizeAchievement TEST:: ***********\n";
	SummarizeAchievement(5, 10);
	SummarizeAchievement(5, 11);
	SummarizeAchievement(6, 10);
	
	cout<<"AchievementRanking TEST:: ***********\n";
	AchievementRanking();
}

/*--------------------------------------------------------------------------*/
/* MAIN FUNCTION */
/*--------------------------------------------------------------------------*/

int main(int argc, char * argv[]) {
	
	while(cin){
		string input;
//get whole command line excluding strings
		getline(cin, input);
//parse for command only
		string command = input.substr(0, input.find(' '));
//select appropriate option
		if(command == "AddPlayer"){

				//finding player name
				string player_name = input.substr(input.find('"'), input.find('"'));
				//taking off quotes
				player_name = player_name.substr(1, player_name.size()-3);
				
				//finding player_ID
				string player_ID_s = input.substr(10, 5);
				//converting to int
				int player_ID = atoi(player_ID_s.c_str());
				
				//instatiate function
				AddPlayer(player_ID, player_name);
		}
		else if(command == "AddGame"){
				string game_name  = input.substr(input.find('"'), input.find('"'));
				game_name = game_name.substr(1, game_name.size()-3);
				
				string game_ID_s = input.substr(8, 4);
				int game_ID = atoi(game_ID_s.c_str());
				
				AddGame(game_ID, game_name);
		}
		else if(command == "AddAchievement"){
				string achieve_name  = input.substr(input.find('"'), input.find('"'));
				
				string game_ID_s = input.substr(15, 4);
				int game_ID = atoi(game_ID_s.c_str());
				
				string achieve_ID_s = input.substr(20, 3);
				int achieve_ID = atoi(achieve_ID_s.c_str());
				
				string achieve_point_s = input.substr(input.find('"') + achieve_name.size()-3 , 3);
				int achieve_point = atoi(achieve_point_s.c_str());
				
				achieve_name = achieve_name.substr(1, achieve_name.size()-6);
				
				AddAchievement(game_ID, achieve_ID, achieve_name, achieve_point);
		}
		else if(command == "Plays"){
				string player_IGN  = input.substr(input.find('"'), input.find('"'));
				player_IGN = player_IGN.substr(1, player_IGN.size()-3);

				string player_ID_s = input.substr(6, 5);
				int player_ID = atoi(player_ID_s.c_str());
				
				string game_ID_s = input.substr(12, 4);
				int game_ID = atoi(game_ID_s.c_str());

				Plays(player_ID, game_ID, player_IGN);
		}
		else if(command == "AddFriends"){
				string player_ID1_s = input.substr(11, 5);
				int player_ID1 = atoi(player_ID1_s.c_str());
				
				string player_ID2_s = input.substr(17, 5);
				int player_ID2 = atoi(player_ID2_s.c_str());
				
				AddFriends(player_ID1, player_ID2);
		}
		else if(command == "Achieve"){
				string player_ID_s = input.substr(8, 5);
				int player_ID = atoi(player_ID_s.c_str());
				
				string game_ID_s = input.substr(14, 4);
				int game_ID = atoi(game_ID_s.c_str());
				
				string achieve_ID_s = input.substr(18, 4);
				int achieve_ID = atoi(achieve_ID_s.c_str());
				
				Achieve_funct(player_ID, game_ID, achieve_ID);
		}
		else if(command == "FriendsWhoPlay"){
				
				string player_ID_s = input.substr(15, 5);
				int player_ID = atoi(player_ID_s.c_str());
				
				string game_ID_s = input.substr(21, 4);
				int game_ID = atoi(game_ID_s.c_str());
				
				FriendsWhoPlay(player_ID, game_ID);
		}
		else if(command == "ComparePlayers"){
				string player_ID1_s = input.substr(15, 5);
				int player_ID1 = atoi(player_ID1_s.c_str());
				
				string player_ID2_s = input.substr(21, 5);
				int player_ID2 = atoi(player_ID2_s.c_str());
				
				string game_ID_s = input.substr(26, 5);
				int game_ID = atoi(game_ID_s.c_str());
				
				ComparePlayers(player_ID1, player_ID2, game_ID);
		}
		else if(command == "SummarizePlayer"){
				string player_ID_s = input.substr(16, 5);
				int player_ID = atoi(player_ID_s.c_str());
				
				SummarizePlayer(player_ID);
		}
		else if(command == "SummarizeGame"){
				string game_ID_s = input.substr(15, 5);
				int game_ID = atoi(game_ID_s.c_str());
				
				SummarizeGame(game_ID);
		}
		else if(command == "SummarizeAchievement"){
				string player_ID_s = input.substr(15, 5);
				int player_ID = atoi(player_ID_s.c_str());
				
				string game_ID_s = input.substr(21, 4);
				int game_ID = atoi(game_ID_s.c_str());
				
				SummarizeAchievement(game_ID, player_ID);
		}
		else if(command == "AchievementRanking"){
				AchievementRanking();
		}
		else if(command == "test_main"){
			test_main();
		}
		else if(command == ""){
			cerr<<"Main:: NO MORE Functions found exiting...\n";
			return 0;
		}
		else{
			cerr<<"Main_ERROR:: Command: "<<command<<" NOT Recognized..., moving to next command\n"; 
		}
	}
}
