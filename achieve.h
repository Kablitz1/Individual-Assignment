/* 
    File: achieve.H

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

*/

#ifndef _achieve_H_                   // include file only once
#define _achieve_H_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include <string>

/*--------------------------------------------------------------------------*/
/* CLASS */
/*--------------------------------------------------------------------------*/

class Achieve{
private:

//members:

//string identifier for achievement
	std::string name;
	
//unique integer identifer for achievement
	int achieve_ID;
	
//how many points this achievement is worth
	int achieve_points;
	
//idicator if achievement has been earned by player
	bool achieve_earned;
	
public:

//constructors:

	Achieve(std::string _name, int _achieve_ID, int _achieve_points);
	
	Achieve();
	
//get functions:

std::string get_name(){return name;}
int get_achieve_ID(){return achieve_ID;}
int get_achieve_points(){return achieve_points;}
bool get_achieve_earned(){return achieve_earned;}

//set functions:

void set_name(std::string _name){name = _name;}
void set_achieve_ID(int _achieve_ID){achieve_ID = _achieve_ID;}
void set_achieve_points(int _achieve_points){achieve_points = _achieve_points;}
void set_achieve_earned(bool _achieve_earned){achieve_earned = _achieve_earned;}

//print function for debugging:

void print();

//check if member is empty:

bool empty();
};


#endif


