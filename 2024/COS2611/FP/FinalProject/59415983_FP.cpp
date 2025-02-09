// 59415983 Muzikayise Bonginhlanhla Mkize
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <stdexcept>

using namespace std;

struct TrafficData {
    string timestamp;
    string vehicleType;
    int speed;
};

bool isValidNumber(const string &str) {
    for (char const &c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

vector<TrafficData> readTrafficData(const string &filename) {
    vector<TrafficData> data;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string timestamp, vehicleType, speedStr;

        getline(ss, timestamp, ';');
        getline(ss, vehicleType, ';');
        getline(ss, speedStr, ';');

        if (isValidNumber(speedStr)) {
            int speed = stoi(speedStr);
            data.push_back({timestamp, vehicleType, speed});
        }
    }
    return data;
}

void generateTrafficSummaryReport(const vector<TrafficData>& data) {
    map<string, int> vehicleCount;
    int totalVehicles = 0;

    for (const auto& entry : data) {
        vehicleCount[entry.vehicleType]++;
        totalVehicles++;
    }

    cout << "Traffic Summary Report:" << endl;
    cout << "-----------------------" << endl;
    cout << "Total vehicles: " << totalVehicles << endl;

    cout << "Vehicle distribution:" << endl;
    for (const auto& pair : vehicleCount) {
        cout << "- " << pair.first << ": " << pair.second
             << " (" << fixed << setprecision(2)
             << (pair.second / static_cast<double>(totalVehicles)) * 100 << "%)" << endl;
    }
}

void generatePeakTrafficTimesReport(const vector<TrafficData>& data) {
    map<string, int> hourCount;

    for (const auto& entry : data) {
        string hour = entry.timestamp.substr(11, 2);
        hourCount[hour]++;
    }

    string peakHour;
    int maxTraffic = 0;
    for (const auto& pair : hourCount) {
        if (pair.second > maxTraffic) {
            peakHour = pair.first;
            maxTraffic = pair.second;
        }
    }

    cout << "Peak Traffic Times Report:" << endl;
    cout << "--------------------------" << endl;
    cout << "Peak traffic hour: " << peakHour << ":00 with " << maxTraffic << " vehicles." << endl;
}

void generateSpeedAnalysisReport(const vector<TrafficData>& data) {
    int totalSpeed = 0;
    int slow = 0, medium = 0, fast = 0;

    for (const auto& entry : data) {
        totalSpeed += entry.speed;
        if (entry.speed < 30) {
            slow++;
        } else if (entry.speed < 60) {
            medium++;
        } else {
            fast++;
        }
    }

    double averageSpeed = totalSpeed / static_cast<double>(data.size());

    cout << "Speed Analysis Report:" << endl;
    cout << "----------------------" << endl;
    cout << "Average speed: " << fixed << setprecision(1) << averageSpeed << " km/h" << endl;
    cout << "Speed distribution:" << endl;
    cout << "- Slow (0-30 km/h): " << slow << " vehicles" << endl;
    cout << "- Medium (30-60 km/h): " << medium << " vehicles" << endl;
    cout << "- Fast (60+ km/h): " << fast << " vehicles" << endl;
}

int main() {
    string filename = "C:\\data\\trafficdata.txt";
    vector<TrafficData> trafficData = readTrafficData(filename);

    generateTrafficSummaryReport(trafficData);   // Report 1: Traffic Summary
    generatePeakTrafficTimesReport(trafficData); // Report 2: Peak Traffic Times
    generateSpeedAnalysisReport(trafficData);    // Report 3: Speed Analysis

    return 0;
}
