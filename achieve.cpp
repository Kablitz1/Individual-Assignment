/* 
    File: achieve.cpp

    Author: Mark Wager
            Department of Computer Science
            Texas A&M University
    Date  : 1/20/16

*/

#ifndef _achieve_CPP_                   // include file only once
#define _achieve_CPP_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "achieve.h"
#include <iostream>
using namespace std;

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

void Achieve::print(){
	//cout<<"----------------------------------------\n";
	cout<<"Achievement Name: "<<name<<"\tID: "<<achieve_ID<<"\tPoints Worth: "<<achieve_points;
	if(achieve_earned == true){
		cout<<"\tEarned?: Yes\n";
	}
	if(achieve_earned == false){
		cout<<"\tEarned?: No\n";
	}
	//cout<<"----------------------------------------\n";
}

bool Achieve::empty(){
	if(name == "NO_NAME" && achieve_ID == 0){
		return true;
	}
	else{
		return false;
	}
}

Achieve::Achieve(std::string _name, int _achieve_ID, int _achieve_points){
		name = _name;
		achieve_ID = _achieve_ID;
		achieve_points = _achieve_points;
		achieve_earned = false;
	}
	
Achieve::Achieve(){
		name = "NO_NAME";
		achieve_ID = 0;
		achieve_points = 0;
		achieve_earned = false;
	}
#endif


