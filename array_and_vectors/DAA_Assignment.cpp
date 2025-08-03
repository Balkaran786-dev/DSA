#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iomanip>
#include <ctime>
#include <random>
#include <algorithm>
#include <climits>  // For INT_MAX

using namespace std;

// Enhanced Patient class with comprehensive medical data
class Patient {
public:
    string name;
    string patientId;
    int age;
    double severity;
    int arrivalTime;
    string symptoms;
    string vitalSigns;
    bool isEmergency;
    int waitTime;
    
    Patient() = default;
    
    Patient(string n, string id, int a, double s, int t, string sym, string vitals, bool emergency = false) 
        : name(n), patientId(id), age(a), severity(s), arrivalTime(t), 
          symptoms(sym), vitalSigns(vitals), isEmergency(emergency), waitTime(0) {}
    
    // Enhanced comparison for priority queue (higher severity = higher priority)
    bool operator<(const Patient& other) const {
        if (abs(severity - other.severity) < 0.1) { // If severity is nearly equal
            if (isEmergency != other.isEmergency) {
                return !isEmergency; // Emergency patients have higher priority
            }
            return arrivalTime > other.arrivalTime; // Earlier arrival = higher priority
        }
        return severity < other.severity; // Higher severity = higher priority
    }
    
    // Method to update severity based on wait time
    void updateSeverityForWaitTime(int currentTime) {
        waitTime = currentTime - arrivalTime;
        // Increase severity slightly for patients who have been waiting too long
        if (waitTime > 60 && severity < 9.0) { // If waiting more than 60 minutes
            severity += 0.5;
        }
        if (waitTime > 120 && severity < 8.5) { // If waiting more than 2 hours
            severity += 0.5;
        }
    }
    
    void displayInfo() const {
        cout << "Patient: " << name << " (ID: " << patientId << ")" << endl;
        cout << "  Age: " << age << " | Severity: " << fixed << setprecision(1) << severity << endl;
        cout << "  Symptoms: " << symptoms << endl;
        cout << "  Vitals: " << vitalSigns << endl;
        cout << "  Arrival: " << arrivalTime << " min | Wait Time: " << waitTime << " min" << endl;
        cout << "  Emergency: " << (isEmergency ? "YES" : "NO") << endl;
    }
};

// Enhanced Triage System with comprehensive patient management
class TriageSystem {
private:
    priority_queue<Patient> patientQueue;
    unordered_map<string, Patient> patientDatabase; // For quick lookups
    int currentTime;
    
public:
    TriageSystem() : currentTime(0) {}
    
    void addPatient(const Patient& patient) {
        patientQueue.push(patient);
        patientDatabase[patient.patientId] = patient;
        cout << "\n[SYSTEM] Patient added: " << patient.name 
             << " (Severity: " << patient.severity << ")" << endl;
    }
    
    Patient getNextPatient() {
        if (patientQueue.empty()) {
            cout << "\n[SYSTEM] No patients in queue." << endl;
            return Patient();
        }
        
        Patient patient = patientQueue.top();
        patientQueue.pop();
        patientDatabase.erase(patient.patientId);
        
        cout << "\n[TRIAGE] Next patient assigned for treatment:" << endl;
        cout << "==========================================" << endl;
        patient.displayInfo();
        cout << "==========================================" << endl;
        
        return patient;
    }
    
    void updatePatientCondition(string patientId, double newSeverity, string newVitals) {
        if (patientDatabase.find(patientId) != patientDatabase.end()) {
            // Create updated patient and rebuild queue
            priority_queue<Patient> newQueue;
            vector<Patient> tempPatients;
            
            // Extract all patients and update the target patient
            while (!patientQueue.empty()) {
                Patient p = patientQueue.top();
                patientQueue.pop();
                
                if (p.patientId == patientId) {
                    p.severity = newSeverity;
                    p.vitalSigns = newVitals;
                    cout << "\n[UPDATE] Patient condition updated: " << p.name 
                         << " (New Severity: " << newSeverity << ")" << endl;
                }
                tempPatients.push_back(p);
            }
            
            // Rebuild queue
            for (const auto& p : tempPatients) {
                patientQueue.push(p);
            }
            patientDatabase[patientId].severity = newSeverity;
            patientDatabase[patientId].vitalSigns = newVitals;
        }
    }
    
    void displayQueueStatus() {
        cout << "\n[QUEUE STATUS] Current patients waiting: " << patientQueue.size() << endl;
        if (!patientQueue.empty()) {
            cout << "Next patient: " << patientQueue.top().name 
                 << " (Severity: " << patientQueue.top().severity << ")" << endl;
        }
    }
    
    int getQueueSize() const {
        return patientQueue.size();
    }
    
    void advanceTime(int minutes) {
        currentTime += minutes;
        // Update all patients' wait times and potentially their severity
        priority_queue<Patient> newQueue;
        vector<Patient> tempPatients;
        
        while (!patientQueue.empty()) {
            Patient p = patientQueue.top();
            patientQueue.pop();
            p.updateSeverityForWaitTime(currentTime);
            tempPatients.push_back(p);
        }
        
        for (const auto& p : tempPatients) {
            patientQueue.push(p);
        }
        
        cout << "\n[TIME] Advanced to " << currentTime << " minutes" << endl;
    }
};

// Enhanced Room class with additional attributes
class Room {
public:
    string roomId;
    string roomType;
    bool isOccupied;
    bool hasSpecialEquipment;
    string currentPatient;
    
    // Default constructor (required for unordered_map)
    Room() : roomId(""), roomType(""), isOccupied(false), 
             hasSpecialEquipment(false), currentPatient("") {}
    
    Room(string id, string type, bool equipment = false) 
        : roomId(id), roomType(type), isOccupied(false), 
          hasSpecialEquipment(equipment), currentPatient("") {}
};

// Enhanced Hospital class with room management
class Hospital {
private:
    unordered_map<string, list<string>> adjList;
    unordered_map<string, Room> rooms;
    
public:
    void addRoom(string roomId, string roomType, bool hasEquipment = false) {
        adjList[roomId] = list<string>();
        rooms[roomId] = Room(roomId, roomType, hasEquipment);
    }
    
    void connectRooms(string r1, string r2) {
        adjList[r1].push_back(r2);
        adjList[r2].push_back(r1);
    }
    
    string findOptimalRoom(string startLocation, const Patient& patient) {
        unordered_map<string, bool> visited;
        queue<pair<string, int>> q; // room, distance
        q.push({startLocation, 0});
        visited[startLocation] = true;
        
        string bestRoom = "";
        int minDistance = INT_MAX;
        
        while (!q.empty()) {
            string currentRoom = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            // Check if room is available and suitable
            if (rooms.find(currentRoom) != rooms.end() && 
                !rooms[currentRoom].isOccupied) {
                
                // Priority for emergency patients to get equipped rooms
                if (patient.isEmergency && rooms[currentRoom].hasSpecialEquipment) {
                    return currentRoom; // Best match for emergency
                }
                
                // Otherwise, find closest available room
                if (distance < minDistance) {
                    minDistance = distance;
                    bestRoom = currentRoom;
                }
            }
            
            // Explore neighboring rooms
            for (const string& neighbor : adjList[currentRoom]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, distance + 1});
                }
            }
        }
        
        return bestRoom;
    }
    
    bool assignRoom(string roomId, const Patient& patient) {
        if (rooms.find(roomId) != rooms.end() && !rooms[roomId].isOccupied) {
            rooms[roomId].isOccupied = true;
            rooms[roomId].currentPatient = patient.name;
            return true;
        }
        return false;
    }
    
    void releaseRoom(string roomId) {
        if (rooms.find(roomId) != rooms.end()) {
            rooms[roomId].isOccupied = false;
            rooms[roomId].currentPatient = "";
        }
    }
    
    void displayHospitalStatus() {
        cout << "\n[HOSPITAL STATUS]" << endl;
        cout << "=================" << endl;
        for (const auto& pair : rooms) {
            const Room& room = pair.second;
            cout << room.roomId << " (" << room.roomType << ") - ";
            if (room.isOccupied) {
                cout << "OCCUPIED by " << room.currentPatient;
            } else {
                cout << "AVAILABLE";
            }
            if (room.hasSpecialEquipment) {
                cout << " [EQUIPPED]";
            }
            cout << endl;
        }
        cout << "=================" << endl;
    }
    
    vector<string> getAvailableRooms() {
        vector<string> available;
        for (const auto& pair : rooms) {
            if (!pair.second.isOccupied) {
                available.push_back(pair.first);
            }
        }
        return available;
    }
};

// Simulation and demonstration functions
void demonstrateTriageSystem() {
    cout << "========================================" << endl;
    cout << "  SMART ER TRIAGE SYSTEM DEMONSTRATION" << endl;
    cout << "========================================" << endl;
    
    TriageSystem triage;
    Hospital hospital;
    
    // Setup hospital layout
    cout << "\n[SETUP] Initializing hospital layout..." << endl;
    hospital.addRoom("ER1", "Emergency", true);
    hospital.addRoom("ER2", "Emergency", true);
    hospital.addRoom("ER3", "Emergency", false);
    hospital.addRoom("TRAUMA1", "Trauma", true);
    hospital.addRoom("OBS1", "Observation", false);
    hospital.addRoom("OBS2", "Observation", false);
    
    // Connect rooms (hospital layout)
    hospital.connectRooms("ER1", "ER2");
    hospital.connectRooms("ER2", "ER3");
    hospital.connectRooms("ER1", "TRAUMA1");
    hospital.connectRooms("ER3", "OBS1");
    hospital.connectRooms("OBS1", "OBS2");
    
    hospital.displayHospitalStatus();
    
    // Add patients with varying conditions
    cout << "\n[SIMULATION] Adding patients to triage queue..." << endl;
    
    triage.addPatient(Patient("Alice Johnson", "P001", 45, 8.5, 10, 
                             "Chest pain, shortness of breath", 
                             "BP: 160/95, HR: 105, O2: 92%", false));
    
    triage.addPatient(Patient("Bob Smith", "P002", 32, 6.0, 15, 
                             "Broken arm from fall", 
                             "BP: 120/80, HR: 85, Pain: 7/10", false));
    
    triage.addPatient(Patient("Charlie Brown", "P003", 67, 9.2, 20, 
                             "Severe abdominal pain", 
                             "BP: 90/60, HR: 120, Temp: 102°F", true));
    
    triage.addPatient(Patient("Diana Prince", "P004", 29, 7.8, 25, 
                             "Allergic reaction", 
                             "BP: 110/70, HR: 95, Rash spreading", false));
    
    triage.addPatient(Patient("Eve Wilson", "P005", 55, 9.8, 30, 
                             "Car accident victim", 
                             "BP: 80/50, HR: 130, Multiple injuries", true));
    
    triage.displayQueueStatus();
    
    // Process patients
    cout << "\n[PROCESSING] Treating patients in priority order..." << endl;
    
    for (int i = 0; i < 3; i++) {
        if (triage.getQueueSize() > 0) {
            Patient patient = triage.getNextPatient();
            
            // Find optimal room
            string assignedRoom = hospital.findOptimalRoom("ER1", patient);
            if (!assignedRoom.empty()) {
                if (hospital.assignRoom(assignedRoom, patient)) {
                    cout << "\n[ASSIGNMENT] Room " << assignedRoom 
                         << " assigned to " << patient.name << endl;
                } else {
                    cout << "\n[ERROR] Failed to assign room " << assignedRoom << endl;
                }
            } else {
                cout << "\n[WARNING] No available rooms for " << patient.name << endl;
            }
            
            hospital.displayHospitalStatus();
            triage.displayQueueStatus();
        }
    }
    
    // Simulate condition update
    cout << "\n[SCENARIO] Simulating patient condition deterioration..." << endl;
    triage.updatePatientCondition("P002", 8.5, "BP: 140/90, HR: 110, Pain: 9/10");
    
    // Advance time and show effects
    cout << "\n[TIME] Advancing simulation by 90 minutes..." << endl;
    triage.advanceTime(90);
    triage.displayQueueStatus();
    
    // Continue processing
    cout << "\n[PROCESSING] Continuing with remaining patients..." << endl;
    while (triage.getQueueSize() > 0) {
        Patient patient = triage.getNextPatient();
        
        // Release a room for demonstration
        hospital.releaseRoom("ER1");
        
        string assignedRoom = hospital.findOptimalRoom("ER1", patient);
        if (!assignedRoom.empty()) {
            hospital.assignRoom(assignedRoom, patient);
            cout << "\n[ASSIGNMENT] Room " << assignedRoom 
                 << " assigned to " << patient.name << endl;
        }
    }
    
    cout << "\n[COMPLETE] All patients have been processed!" << endl;
    hospital.displayHospitalStatus();
}

// Performance analysis function
void performanceAnalysis() {
    cout << "\n========================================" << endl;
    cout << "         PERFORMANCE ANALYSIS" << endl;
    cout << "========================================" << endl;
    
    TriageSystem triage;
    auto start = clock();
    
    // Add many patients to test performance
    for (int i = 0; i < 1000; i++) {
        double severity = 1.0 + (rand() % 90) / 10.0; // Random severity 1.0-9.9
        triage.addPatient(Patient("Patient" + to_string(i), "P" + to_string(i), 
                                 20 + rand() % 60, severity, i, 
                                 "Random symptoms", "Random vitals", 
                                 severity > 8.5));
    }
    
    auto end = clock();
    double addTime = double(end - start) / CLOCKS_PER_SEC;
    
    start = clock();
    
    // Process all patients
    int processed = 0;
    while (triage.getQueueSize() > 0) {
        triage.getNextPatient();
        processed++;
    }
    
    end = clock();
    double processTime = double(end - start) / CLOCKS_PER_SEC;
    
    cout << "\nPerformance Results:" << endl;
    cout << "- Added 1000 patients in: " << addTime << " seconds" << endl;
    cout << "- Processed " << processed << " patients in: " << processTime << " seconds" << endl;
    cout << "- Average processing time per patient: " 
         << (processTime / processed) * 1000 << " milliseconds" << endl;
}

int main() {
    srand(time(nullptr)); // For random patient generation
    
    // Main demonstration
    demonstrateTriageSystem();
    
    // Performance analysis
    performanceAnalysis();
    
    cout << "\n========================================" << endl;
    cout << "    SMART ER TRIAGE SYSTEM COMPLETE" << endl;
    cout << "========================================" << endl;
    
    return 0;
}