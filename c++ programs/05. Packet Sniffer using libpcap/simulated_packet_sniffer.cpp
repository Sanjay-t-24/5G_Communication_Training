
// SIMULATED PACKET SNIFFER (No libpcap)
// Author: Sanjay Kumar - TelcoLearn Services
// Part of Wipro FDP program
// This program simulates packet capture and parsing for training/demo purposes

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// -----------------------------
// STRUCT TO SIMULATE A PACKET
// -----------------------------
struct Packet {
    string srcIP;
    string dstIP;
    int protocol; // 1 = ICMP, 6 = TCP, 17 = UDP
    int length;
};

// -----------------------------
// CLASS TO SIMULATE PACKET CAPTURE AND PARSING
// -----------------------------
class PacketSnifferSimulator {
private:
    vector<Packet> capturedPackets;

    // Generate a random IP address
    string generateIP() {
        return to_string(rand() % 256) + "." +
               to_string(rand() % 256) + "." +
               to_string(rand() % 256) + "." +
               to_string(rand() % 256);
    }

    // Generate a random protocol
    int generateProtocol() {
        int p[] = {1, 6, 17};
        return p[rand() % 3];
    }

public:
    // Simulate capturing packets
    void simulateCapture(int count) {
        for (int i = 0; i < count; ++i) {
            Packet pkt;
            pkt.srcIP = generateIP();
            pkt.dstIP = generateIP();
            pkt.protocol = generateProtocol();
            pkt.length = rand() % 1500 + 64;
            capturedPackets.push_back(pkt);
        }
    }

    // Display simulated packets
    void displayPackets() const {
        cout << left << setw(20) << "Source IP"
             << setw(20) << "Destination IP"
             << setw(10) << "Protocol"
             << setw(10) << "Length" << endl;

        cout << string(60, '-') << endl;

        for (const auto& pkt : capturedPackets) {
            string protoName = pkt.protocol == 1 ? "ICMP" :
                               pkt.protocol == 6 ? "TCP" :
                               pkt.protocol == 17 ? "UDP" : "Other";

            cout << left << setw(20) << pkt.srcIP
                 << setw(20) << pkt.dstIP
                 << setw(10) << protoName
                 << setw(10) << pkt.length << endl;
        }
    }
};

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    srand(time(0));

    PacketSnifferSimulator sniffer;
    sniffer.simulateCapture(10);

    cout << "\nSimulated Packet Sniffer Output:\n";
    sniffer.displayPackets();

    return 0;
}
