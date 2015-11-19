#include <iostream>
#include <string>
#include "../include/cyberpc.h"
#include "../include/cyberdns.h"
#include "../include/cyberexpert.h"
#include "../include/cyberworm.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;
using boost::property_tree::ptree;

void readComputers(CyberDNS server){
    
    ptree pt;
    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/computers.xml", pt);

    // iterate over the list of computers
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
        CyberPC * cyber_pc_ = new CyberPC(it->second.get<string>("name"), it->second.get<string>("os"));
        
        // cout << "Computer" + it->first << "\n";
        // cout << "name: " + it->second.get<string>("os") << "\n";
        // cout << "Operating System: " + it->second.get<string>("name") << "\n";

        server.AddPC(*cyber_pc_);
    }
    
}
void connectComputers(CyberDNS server){
    ptree pt;
    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/network.xml", pt);

    // iterate over the list of computers
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
        string first_pc_str = it->second.get<string>("pointA");
        string second_pc_str = it->second.get<string>("pointB");
        CyberPC first_pc_add = server.GetCyberPC(first_pc_str);
        CyberPC second_pc_add = server.GetCyberPC(second_pc_str);
        second_pc_add.AddConnection(first_pc_str);
        first_pc_add.AddConnection(second_pc_str);
    }
} 

void hackEvent(CyberDNS dns, ptree::const_iterator it){
    CyberPC soon_to_b_hacked_pc = dns.GetCyberPC(it->second.get<string>("computer"));
    string hacking_worm_name = it->second.get<string>("wormName");
    string hacking_worm_os = it->second.get<string>("wormOs");
    int hacking_worm_dorm = it->second.get<int>("wormDormancy");
    CyberWorm *worm = new CyberWorm(hacking_worm_name, hacking_worm_os, hacking_worm_dorm);
    soon_to_b_hacked_pc.Infect(*worm);   
} 

void clockIn(vector<CyberExpert> experts){
    CyberExpert * expert = new CyberExpert(it->second.get<string>("name"),
                                            it->second.get<int>("workTime"),
                                            it->second.get<int>("restTime"),
                                            it->second.get<int>("efficiency"));
    experts.push_back(expert);
}

void readEvents(CyberDNS dns){
    ptree pt;
    vector<CyberExpert> experts;
    int dayOfTermination = 0;
    vector<string> computerslist;
    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/events.xml", pt);
    // iterate over the list of events
    int day = 0;
    ptree::const_iterator it = pt.begin();

    while (it != pt.end() || day < dayOfTermination) {
        if (it->first == "hack") {
            hackEvent(dns, it);
        } else if (it->first == "clock-in") {  
            clockIn(experts);
        } else if (it->first =="termination"){
            dayOfTermination = it->second.get<int>("time");
        } 
        computerslist = dns.GetCyberPCList();
        for (vector<string>::iterator it = computerslist.begin(); it != computerslist.end(); ++it){
            for (vector<CyberExpert>::iterator it_expert = experts.begin(); it_expert != experts.end(); ++it_expert) {
                *it_expert.Clean();
            }
            dns.GetCyberPC(*it).Run();  
        }
            
         ++it;
         day++;
    }
}

int main() {
   CyberDNS dns;
   readComputers(dns);


    cout<<"sgg";
    return 0;
}
