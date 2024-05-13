//59415983
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

struct Patient {
    char specialty;
    int processingTime;
};

int main()
{
    queue<Patient> woundQueue;
    queue<Patient> adultQueue;
    queue<Patient> childrenQueue;
    ifstream inFile("c:\\data\\dataclient.txt");

    if (!inFile) {
        cerr << "Error: Unable to open file dataclient.txt" << endl;
        return 1;
    }

    string line;
    int timeCount = 0;

    while (getline(inFile, line)) {
        int arrivalTime;
        char specialty;
        int processingTime;
        char tmp;

        stringstream ssin(line);

        if(ssin.good()) {
           ssin >>  arrivalTime >> tmp >> specialty >> tmp >> processingTime;
        }
        while (timeCount < arrivalTime) {
            timeCount++;
        }

        Patient patient = {specialty, processingTime};

        switch (specialty) {
            case 'W':
                woundQueue.push(patient);
                break;
            case 'A':
                adultQueue.push(patient);
                break;
            case 'C':
                childrenQueue.push(patient);
                break;
            default:
                cerr << "Error: Invalid specialty" << endl;
                break;
        }
    }
    inFile.close();
    return 0;
}
