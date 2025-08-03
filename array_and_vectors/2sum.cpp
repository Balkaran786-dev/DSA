#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>

using namespace std;

// =========================
// Patient Class Definition
// =========================
class Patient {
public:
    string name;
    int severity;
    int arrivalTime;

    Patient(string n, int s, int t) {
        name = n;
        severity = s;
        arrivalTime = t;
    }

    // Overload operator for priority_queue (max-heap)
    bool operator<(const Patient& other) const {
        if (severity == other.severity)
            return arrivalTime > other.arrivalTime; // earlier arrival = higher priority
        return severity < other.severity; // higher severity = higher priority
    }
};

// =============================
// Triage System using Max-Heap
// =============================
class TriageSystem {
private:
    priority_queue<Patient> pq;

public:
    void addPatient(string name, int severity, int arrivalTime) {
        pq.push(Patient(name, severity, arrivalTime));
    }

    void getNextPatient() {
        if (pq.empty()) {
            cout << "No patients in queue.\n";
            return;
        }
        Patient p = pq.top();
        pq.pop();
        cout << "Next patient to treat: " << p.name
             << " (Severity: " << p.severity
             << ", Arrival Time: " << p.arrivalTime << ")\n";
    }

    bool isEmpty() {
        return pq.empty();
    }
};

// =========================
// Hospital Room Graph (BFS)
// =========================
class Hospital {
private:
    unordered_map<string, list<string>> adjList;

public:
    void addRoom(string room) {
        adjList[room] = list<string>();
    }

    void connectRooms(string r1, string r2) {
        adjList[r1].push_back(r2);
        adjList[r2].push_back(r1);
    }

    string findNearestAvailableRoom(string startRoom, set<string>& availableRooms) {
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(startRoom);
        visited[startRoom] = true;

        while (!q.empty()) {
            string room = q.front();
            q.pop();

            if (availableRooms.find(room) != availableRooms.end()) {
                return room;
            }

            for (string neighbor : adjList[room]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return "None";
    }
};

// =========================
// Main Simulation
// =========================
int main() {
    TriageSystem triage;

    triage.addPatient("Alice", 9, 1);
    triage.addPatient("Bob", 6, 2);
    triage.addPatient("Charlie", 8, 3);

    cout << "=== Patient Queue ===\n";
    triage.getNextPatient();
    triage.getNextPatient();

    // Room Graph Setup
    Hospital hospital;
    hospital.addRoom("ER1");
    hospital.addRoom("ER2");
    hospital.addRoom("ER3");
    hospital.connectRooms("ER1", "ER2");
    hospital.connectRooms("ER2", "ER3");

    set<string> availableRooms = {"ER2", "ER3"};

    cout << "\n=== Room Allocation ===\n";
    string nearest = hospital.findNearestAvailableRoom("ER1", availableRooms);
    if (nearest != "None")
        cout << "Nearest available room from ER1: " << nearest << endl;
    else
        cout << "No available rooms found.\n";

    return 0;
}
