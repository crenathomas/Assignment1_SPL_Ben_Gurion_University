#include <iostream>
#include <string>
#include "../include/cyberpc.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;

CyberPC::CyberPC(string pc_os,string pc_name):cyber_pc_os_(pc_os),cyber_pc_name_(pc_name){
        cyber_pc_os_ = cyber_pc_os;
        cyber_pc_name_ = cyber_pc_name;                        // Only use this constructor
    } 
    

    const string getName(){
        return string cyber_pc_name_;
    }

    const string getWorm(){
        return yber_worm_;
    }

    void AddConnection(string  second_pc){
        cyber_pc_connections_.push_back second_pc;               // Add a connection to this PC
    }                

    void Infect(CyberWorm & worm){                              //refers to the copied constructor in class cyberworm.pcc where other, in this case, is worm here
                                                                // Add a worm to this PC
    }
                                                                  
    void Run(const CyberDNS & server){                           // Activate PC and infect others if worm is active

    }                             
    void Disinfect();                                            // called by cyber expert, disinfect PC
    //Add additional functions here if necessary
    
};



/*int main() {
    using boost::property_tree::ptree;
    ptree pt;

    // read the xml file
    read_xml("xml/computers.xml", pt);
    
    // iterate over the wires
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
        cout << "Node key: " + it->first << "\n";
        cout << "Name: " + it->second.get<std::string>("name") << "\n";
        cout << "OS: " + it->second.get<std::string>("os") << "\n";
    }
}
*/