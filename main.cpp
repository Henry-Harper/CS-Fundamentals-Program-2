/*  Henry Harper 10/27/2022
 *  Computing Systems Fundamentals Program 2
 *
 */

#include <iostream>
#include <cmath>
#include "definitions.h"

using namespace std;

// Function Prototypes
float findServiceTime(float);
float findArrivalTime(float);

int main(){
    simulation sim[21]; // Create array of 21 structs
    float avgArrivalRate = 10.0;
    float avgServiceTime = 0.04;
    float clock = 0;

    srand((unsigned int)time(nullptr)); // set seed to system time




    for(int i = 0; i < 21; i++){        // Run code for 21 simulations
        for(int j = 0; j < 10000; j++){ // For each simulation, there are 10k processes
            sim[i].arrivalTime[j] = findArrivalTime(avgArrivalRate);
            sim[i].serviceTime[j] = findServiceTime(avgServiceTime);

            sim[i].totalArrivalTime += sim[i].arrivalTime[j];
            sim[i].totalServiceTime += sim[i].serviceTime[j];
            clock += sim[i].arrivalTime[j] + sim[i].serviceTime[j];
        }
        sim[i].avgTurnaroundTime = 10000 / sim[i].totalArrivalTime;
        sim[i].totalThroughput = 10000 / clock;

        // print results
        cout << "Simulation " << i+1 << " results: " << endl;
        cout << "=================================================" << endl;
        cout << "Average Turnaround Time = " << sim[i].avgTurnaroundTime << " seconds" << endl;
        cout << "Total Throughput = " << sim[i].totalThroughput << endl;
        cout << "Average CPU Utilization = " << sim[i].avgCPU_Utilization << endl;
        cout << "Average Number of Processes in Ready Queue = " << sim[i].avgNumProcesses << "\n" << endl;

        avgArrivalRate++;               // Increment arrival rate for next simulation
    }
}