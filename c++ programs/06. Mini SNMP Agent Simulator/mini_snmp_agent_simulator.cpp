
// MINI SNMP AGENT SIMULATOR (Simulated)
// Author: Sanjay Kumar - TelcoLearn Services
// Part of Wipro FDP program
// This program simulates SNMP GET requests and responses using a static MIB map

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// -----------------------------
// CLASS DEFINING MINI SNMP AGENT
// -----------------------------
class MiniSnmpAgent {
private:
    map<string, string> mib; // Simulated MIB with OID as key and value as string

public:
    MiniSnmpAgent() {
        // Preload some fake MIB entries
        mib["1.3.6.1.2.1.1.1.0"] = "Simulated SNMP Agent v1.0";        // sysDescr
        mib["1.3.6.1.2.1.1.5.0"] = "telco-agent";                      // sysName
        mib["1.3.6.1.2.1.2.2.1.10.1"] = "123456";                      // ifInOctets
        mib["1.3.6.1.2.1.2.2.1.16.1"] = "654321";                      // ifOutOctets
        mib["1.3.6.1.2.1.1.3.0"] = "456789";                           // sysUpTime
    }

    // Simulated GET operation
    void handleGet(const string& oid) {
        cout << "SNMP GET for OID: " << oid << endl;
        if (mib.find(oid) != mib.end()) {
            cout << "Response: " << mib[oid] << endl;
        } else {
            cout << "Error: No such OID in MIB." << endl;
        }
    }

    // List available OIDs
    void listOids() const {
        cout << left << setw(30) << "OID" << "Value" << endl;
        cout << string(50, '-') << endl;
        for (const auto& pair : mib) {
            cout << left << setw(30) << pair.first << pair.second << endl;
        }
    }
};

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    MiniSnmpAgent agent;

    cout << "Mini SNMP Agent Simulator\n";
    cout << "--------------------------\n";

    agent.listOids();

    string inputOid;
    cout << "\nEnter an OID to GET (or type 'exit'): ";
    while (cin >> inputOid) {
        if (inputOid == "exit") break;
        agent.handleGet(inputOid);
        cout << "\nEnter another OID to GET (or type 'exit'): ";
    }

    return 0;
}
