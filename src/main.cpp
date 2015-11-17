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

CyberDNS readComputers(){
    CyberDNS * dns = new CyberDNS();
    ptree pt;
    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/computers.xml", pt);

    // iterate over the list of computers
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
        CyberPC * cyber_pc_ = new CyberPC(it->second.get<string>("name"), it->second.get<string>("os"));
        
        // cout << "Computer" + it->first << "\n";
        // cout << "name: " + it->second.get<string>("os") << "\n";
        // cout << "Operating System: " + it->second.get<string>("name") << "\n";

        dns->AddPC(*cyber_pc_);
    }
    return *dns;
    
}
void connect(CyberDNS * & CyberDNS){
    ptree pt;
    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/network.xml", pt);

    // iterate over the list of computers
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
        string first_pc = it->second.get<string>("pointA");
        string second_pc = it->second.get<string>("pointB");  
        CyberDNS->GetCyberPC(second_pc).AddConnection(second_pc);
        CyberDNS->GetCyberPC(first_pc).AddConnection(first_pc);
    }
}  
void readEvents{
    ptree pt;
    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/events.xml", pt);
    // iterate over the list of computers
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
        if(it->first == "hack"){
            CyberDNS.GetCyberPC(it->second.get<string>("computer"));
            CyberWorm worm = new CyberWorm(it->second.get<string>("wormName"), 
                it->second.get<string>("wormOs"), it->second.get<string>("wormDormancy")): 
            CyberPC.Infect(it->second.get<string>(CyberWorm));
        }else if(it->first == "clock-in"){
            CyberExpert expert = new CyberExpert(it->second.get<string>("name"),
                it->second.get<int>("workTime"),it->second.get<int>("restTime"),
                it->second.get<int>("efficiency"));
            CyberExpert.ClockIn();
        }else{
            
        }
    }
} 

int main() {
   CyberDNS dns = readComputers();
    cout<<"sgg";
    return 0;
}
