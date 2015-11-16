#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace std;


int main() {

    using boost::property_tree::ptree;


    ptree pt;
    //CyberDNS() *dns= new CyberDNS();

    // read the xml file
    read_xml("/Users/renathomas/Documents/BGU_Fall/SPL/Assignments/Assignment1/xml/computers.xml", pt);

    // iterate over the wires
    for (ptree::const_iterator it = pt.begin(); it != pt.end(); ++it) {
		cout << "Node key: " + it->first << "\n";
	    cout << "Point A: " + it->second.get<string>("os") << "\n";
		cout << "Point B: " + it->second.get<string>("name") << "\n";
	}
    return 0;
}
