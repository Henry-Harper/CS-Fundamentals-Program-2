//
// Created by hhmas on 11/1/2022.
//

#ifndef CS_FUNDAMENTALS_PROGRAM_2_DEFINITIONS_H
#define CS_FUNDAMENTALS_PROGRAM_2_DEFINITIONS_H
#endif //CS_FUNDAMENTALS_PROGRAM_2_DEFINITIONS_H
#include <cmath>

// struct to hold data for each simulation
struct simulation{
    float avgTurnaroundTime;    // = Num Processes (Total) / Arrival Rate (Total)
    float totalThroughput;      // = Num Processes (Total) / Time passed
    float avgCPU_Utilization;   // = avg Arrival Rate (experimental) * Avg Service Time (experimental)
    float avgNumProcesses;      // = avgCPU utilization / (1 - avgCPU utilization)

    float totalArrivalTime = 0;
    float totalServiceTime = 0;

    float ExpAvgArrivalTime;    // experimental average arrival time
    float expAvgServiceTime;    // experimental average service time

    float serviceTime[10000];   // stores service Time for each process
    float arrivalTime[10000];   // stores arrival Time for each process
};

struct event{
    int type;
    float time;
    event *next;
};

class eventQueue{

};

/* To generate a random number 'x' that follows EXPONENTIAL DISTRIBUTION:
 * and the (expected) average is 't'
 * 1. generate a real (float) number 'z' uniformly from [0,1]
 * 2. get 'x' by:
 *      x = -t * ln(z)
 */
// generates random service time simulating exponential distribution given average rate = 0.04;
float findServiceTime(float avgServiceTime){
    float randNum = float(rand())/float((RAND_MAX)); // generate random num

    float generatedServiceTime = -1*(avgServiceTime) * log(randNum); // simulate exponential distribution
    return generatedServiceTime;
}

/* To generate 'k' arrivals following POISSON DISTRIBUTION: (given avg rate)
 * We need to generate inter-arrival times that follows Exp. distribution
 * 1. generate z1, z2, z3... (uniform distribution between 0 and 1)
 * 2. generate inter-arrival times x1, x2, x3... xk by:
 *      x = (-1 / (avg arrival rate)) * ln(z)
 * 3. Obtain arrival times
 *    t1 = x1, t2 = x1 + x2, t3 = x1 + x2 + x3
 */
// generates random arrival time simulating poisson distribution when given avg arrivalRate
float findArrivalTime(float avgArrivalRate){
    float randNum = float(rand())/float((RAND_MAX)); // generate random number (uniform)

    float arrivalTime = (-1*avgArrivalRate) * log(randNum); // generate inter-arrival times
    return arrivalTime;
}