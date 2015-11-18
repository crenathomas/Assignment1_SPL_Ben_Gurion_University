#include "../include/cyberexpert.h"

using namespace std;

CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
this->cyber_expert_name_(cyber_expert_name_), 
this->cyber_expert_work_time_(cyber_expert_work_time_), 
this->cyber_expert_rest_time_(cyber_expert_rest_time_),
this->cyber_expert_efficiency_(cyber_expert_efficiency){}

void CyberExpert::Clean(CyberPC & cyber_pc){
  cyber_pc.Disinfect();
}

void CyberExpert::ClockIn(vector<string> cyberPCs){
	//for(vector<int>::iterator it = cyberPCs.begin() ; it != cyberPCs.end(); ++it){
	for(int i = 0; i != this->cyber_expert_efficiency_<int>("efficiency"); i++){ 
	    CyberDNS * cyberPCs;
	    this.GetCyberPC(it)
	    this->Clean(i*);
	    }
	}
}