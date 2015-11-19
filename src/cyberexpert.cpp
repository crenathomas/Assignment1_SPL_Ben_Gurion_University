#include "../include/cyberexpert.h"
#include "../include/cyberdns.h"

using namespace std;

CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
cyber_expert_name_(cyber_expert_name_), 
cyber_expert_work_time_(cyber_expert_work_time_), 
cyber_expert_rest_time_(cyber_expert_rest_time_),
cyber_expert_efficiency_(cyber_expert_efficiency_){}

int CyberExpert::getEfficiency(){
	return cyber_expert_efficiency_;
}

void CyberExpert::Clean(CyberPC & cyber_pc){
	cyber_pc.Disinfect();
}

