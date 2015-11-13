//
//  Cyber_Worm.cpp
//  
//
//  Created by Rena Thomas on 11/10/15.
//
//

#include "../include/cyberworm.h"
#include <iostream>
#include <string>

using namespace std;

class CyberWorm {
private:
    const string 	cyber_worm_os_;
    const string 	cyber_worm_name_;
    const int cyber_worm_dormancy_time_;
    CyberWorm(); // Prevent the use of an empty constructor
	// Add your variables here
 
public:
    string CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time){
    	cyber_worm_os_ = cyber_worm_os;
    	cyber_worm_name_ = cyber_worm_name;
    	cyber_worm_dormancy_time_ = cyber_worm_dormancy_time;
    }
	
	CyberWorm(const CyberWorm& other); //copy constructor;
	// Add your own functions here
};
