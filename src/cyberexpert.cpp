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

void CyberExpert::ClockIn(){
    for(int i = 0; i<= it-> second.get<int>("efficiency"); i++){ 
        CyberExpert.Clean(expert)
    }
}