
// RMON STATISTICS SIMULATOR
// Author: ChatGPT | Replit-friendly version with varied stats
// This program simulates Remote Network Monitoring (RMON) statistics
// for network interfaces like eth0, eth1, eth2

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstdint> // For uint64_t

using namespace std;

// -----------------------------
// STRUCT DEFINITION
// -----------------------------
struct RmonData {
    uint64_t packets;
    uint64_t errors;
    uint64_t collisions;
    uint64_t octets;
    double bandwidthUtilization; // In percentage
};

// -----------------------------
// CLASS DEFINITION
// -----------------------------
class RmonStats {
private:
    map<string, RmonData> interfaceStats;

public:
    // Simulate RMON data for a given interface with variation
    void simulateData(const string& interfaceName, int ifaceIndex) {
        RmonData data;
        data.packets = rand() % 10000 + 500 + ifaceIndex * 7;
        data.errors = rand() % 10 + ifaceIndex;
        data.collisions = rand() % 20 + (ifaceIndex % 3);
        data.octets = data.packets * (rand() % 500 + 64);
        data.bandwidthUtilization = ((rand() % 1000) + ifaceIndex * 17) / 10.0;

        interfaceStats[interfaceName] = data;
    }

    // Display all stats in a clean table format
    void displayStats() const {
        cout << left << setw(15) << "Interface"
             << setw(10) << "Packets"
             << setw(10) << "Errors"
             << setw(12) << "Collisions"
             << setw(10) << "Octets"
             << setw(12) << "Util(%)" << endl;

        cout << string(70, '-') << endl;

        for (const auto& pair : interfaceStats) {
            const RmonData& d = pair.second;
            cout << left << setw(15) << pair.first
                 << setw(10) << d.packets
                 << setw(10) << d.errors
                 << setw(12) << d.collisions
                 << setw(10) << d.octets
                 << setw(12) << d.bandwidthUtilization << endl;
        }
    }
};

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    RmonStats monitor;

    srand(time(0)); // Set random seed once

    vector<string> interfaces = {"eth0", "eth1", "eth2"};

    for (int i = 0; i < interfaces.size(); ++i) {
        monitor.simulateData(interfaces[i], i); // Use index to vary data
    }

    cout << "\nSimulated RMON Statistics:\n";
    monitor.displayStats();

    return 0;
}
