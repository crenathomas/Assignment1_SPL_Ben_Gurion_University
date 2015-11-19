#include "../include/cyberpc.h"

using namespace std;

CyberPC::CyberPC(string cyber_pc_os,string cyber_pc_name):
cyber_pc_os_(cyber_pc_os),cyber_pc_name_(cyber_pc_name){
    vector<string> cyber_pc_connections_;   
}


const string CyberPC::getName(){
    return cyber_pc_name_;
}


void CyberPC::AddConnection(string second_pc){
    cyber_pc_connections_.push_back(second_pc);               // Add a connection to this PC
}

void CyberPC::Infect(CyberWorm & worm){                              //refers to the copied constructor in class cyberworm.pcc where other, in this case, is worm here
    cyber_worm_ = &worm;  
    cyber_pc_time_to_infect_ = worm.getTime();                                                         // Add a worm to this PC
}

void CyberPC::Run(const CyberDNS & server){                           // Activate PC and infect others if worm is active
    if(cyber_pc_time_to_infect_ == 0){
        vector<string> cyber_pc_connections_;
    for (vector<string>::iterator it = cyber_pc_connections_.begin(); it != cyber_pc_connections_.end(); ++it){
            server.GetCyberPC(*it).Infect(*cyber_worm_);
    }
    }else{
        cyber_pc_time_to_infect_ --;
        cout << "not time to infect"<< endl;
    }
}

void CyberPC::Disinfect(){                                           // called by cyber expert, disinfect PC
    this->cyber_worm_ = NULL;
}

