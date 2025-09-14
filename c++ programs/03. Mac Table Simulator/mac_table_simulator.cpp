
// MAC TABLE ENTRY SIMULATOR
// Author: Sanjay Kumar - TelcoLearn Services
// Part of Wipro FDP program
// This program simulates filling MAC table entries like those in Ethernet switches

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// -----------------------------
// STRUCT DEFINITION
// -----------------------------
struct MacEntry {
    string macAddress;
    string port;
    int vlanId;
};

// -----------------------------
// CLASS DEFINITION
// -----------------------------
class MacTable {
private:
    map<string, MacEntry> table; // Key: MAC Address

    // Generate random MAC address
    string generateRandomMac() {
        char mac[18];
        sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X",
                rand() % 256, rand() % 256, rand() % 256,
                rand() % 256, rand() % 256, rand() % 256);
        return string(mac);
    }

public:
    void populateEntries(int count) {
        vector<string> ports = {"Gig0/1", "Gig0/2", "Gig0/3", "Gig0/4"};
        for (int i = 0; i < count; ++i) {
            MacEntry entry;
            entry.macAddress = generateRandomMac();
            entry.port = ports[i % ports.size()];
            entry.vlanId = 10 + (i % 3); // VLAN 10, 11, 12

            table[entry.macAddress] = entry;
        }
    }

    void displayTable() const {
        cout << left << setw(20) << "MAC Address"
             << setw(10) << "Port"
             << setw(10) << "VLAN" << endl;

        cout << string(40, '-') << endl;

        for (const auto& pair : table) {
            const MacEntry& e = pair.second;
            cout << left << setw(20) << e.macAddress
                 << setw(10) << e.port
                 << setw(10) << e.vlanId << endl;
        }
    }
};

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    srand(time(0)); // Seed random generator

    MacTable macTable;
    macTable.populateEntries(10); // Populate 10 MAC entries

    cout << "\nSimulated MAC Table Entries:\n";
    macTable.displayTable();

    return 0;
}
