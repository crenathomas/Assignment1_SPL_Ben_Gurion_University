#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include "../include/cyberexpert.h"
#include "../include/cyberworm.h"

using namespace std;

CyberDNS::CyberDNS() {}

void CyberDNS::AddPC(CyberPC & cyber_pc_){
    cyber_DNS_.insert(pair <string, CyberPC &> (cyber_pc_.getName(), cyber_pc_));
}

CyberPC & CyberDNS::GetCyberPC(const string & cyber_pc_name) const{
    return cyber_DNS_.find(cyber_pc_name)->second;
}

vector<string> CyberDNS::GetCyberPCList() {
    vector <string> pcNames;
    for (map<const string, CyberPC &>::iterator it = cyber_DNS_.begin(); it != cyber_DNS_.end(); ++it) {
       pcNames.push_back(it->second);
    }
    return pcNames;
}
