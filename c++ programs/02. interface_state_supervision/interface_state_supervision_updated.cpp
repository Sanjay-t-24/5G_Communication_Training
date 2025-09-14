
// INTERFACE STATE SUPERVISION SIMULATOR
// Author: Sanjay Kumar - TelcoLearn Services | Replit-friendly version
// This program simulates supervision of network interface states (UP/DOWN)

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// -----------------------------
// ENUM & STRUCT DEFINITION
// -----------------------------
enum InterfaceState { DOWN, UP };

struct InterfaceInfo {
    InterfaceState state;
    int uptimeSeconds;     // Seconds the interface has been up
    int downtimeSeconds;   // Seconds the interface has been down
};

// -----------------------------
// CLASS DEFINITION
// -----------------------------
class InterfaceSupervisor {
private:
    map<string, InterfaceInfo> interfaces;

public:
    // Simulate interface state (randomly UP or DOWN)
    void simulateState(const string& name) {
        InterfaceInfo info;
        int randVal = rand() % 100;

        if (randVal < 70) {
            info.state = UP;
            info.uptimeSeconds = rand() % 100000;
            info.downtimeSeconds = rand() % 1000;
        } else {
            info.state = DOWN;
            info.uptimeSeconds = rand() % 500;
            info.downtimeSeconds = rand() % 100000;
        }

        interfaces[name] = info;
    }

    // Display state for all interfaces
    void displayStates() const {
        cout << left << setw(15) << "Interface"
             << setw(10) << "State"
             << setw(15) << "Uptime(s)"
             << setw(15) << "Downtime(s)" << endl;

        cout << string(55, '-') << endl;

        for (const auto& pair : interfaces) {
            const InterfaceInfo& info = pair.second;
            cout << left << setw(15) << pair.first
                 << setw(10) << (info.state == UP ? "UP" : "DOWN")
                 << setw(15) << info.uptimeSeconds
                 << setw(15) << info.downtimeSeconds << endl;
        }
    }
};

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    InterfaceSupervisor supervisor;

    srand(time(0)); // Seed for randomness

    vector<string> interfaceNames = {"eth0", "eth1", "eth2", "eth3"};

    for (const auto& iface : interfaceNames) {
        supervisor.simulateState(iface);
    }

    cout << "\nInterface State Supervision Report:\n";
    supervisor.displayStates();

    return 0;
}
