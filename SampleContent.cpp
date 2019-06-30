#include <cstdint>
#include <vector>
#include <iostream>
#include <algorithm>

struct Process
{
    uint8_t processId;
    uint8_t burstTime;
    uint8_t arrivalTime;
    uint8_t priority;
};

enum class SchedulingAlgo
{
    FCFS,
    SJF,
    Priority
};

struct ProcessIdDurationPair
{
    uint8_t processId;
    uint8_t duration;
};

bool byPriority (const Process &L, const Process &R){
    return L.priority<R.priority;
}

bool byBT (const Process &L, const Process &R) {
    return L.burstTime<R.burstTime;
}

bool byId (const Process &L, const Process &R) {
    return L.processId<R.processId;
}

std::vector<ProcessIdDurationPair> schedule(SchedulingAlgo algorithm, std::vector<Process> processes){
    std::vector<ProcessIdDurationPair> sorted;
    if ((int)algorithm==0){
        std::cout<<"FCFS"<<std::endl;
        uint8_t x=0;    //arrivaltime
        uint8_t i=0;
        std::sort(processes.begin(),processes.end(),byId);
        while (sorted.size()<processes.size()){
            if (x==processes[i].arrivalTime){
                ProcessIdDurationPair temp;
                temp.processId=processes[i].processId;
                temp.duration=processes[i].burstTime;
                sorted.push_back(temp);
                //std::cout<<(int)temp.processId;
            }
            i++;
            if ((int)i==processes.size()){
                i=0;
                x++;
            }
        }
        return sorted;
        /*
        for (auto pro : processes) {
            if ()
            std::cout<<(int)pro.processId;
        }*/
    }
    else if ((int)algorithm==1){
        std::cout<<"SJF"<<std::endl;
        std::sort(processes.begin(),processes.end(),byBT);
        /*for (auto elem : processes){
            std::cout<<(int)elem.processId<<",";
        }*/
        uint8_t i=-1;
        uint8_t x=0;    //current AT
        int8_t maxi=processes.size();
        while (sorted.size()<maxi){
            i++;
            if (processes[i].arrivalTime<=x){
                ProcessIdDurationPair temp;
                temp.processId=processes[i].processId;
                temp.duration=processes[i].burstTime;
                sorted.push_back(temp);
                x=x+processes[i].burstTime;
                processes.erase(processes.begin()+i);
                i=-1;
                //std::cout<<(int)temp.processId;
            }
            if ((int)i==processes.size()){
                i=-1;
            }
        }
        return sorted;
    }
    else if ((int)algorithm==2){
        std::cout<<"Priority"<<std::endl;
        std::sort(processes.begin(),processes.end(),byPriority);
        /*for (auto elem : processes){
            std::cout<<(int)elem.processId<<",";
        }*/
        uint8_t i=-1;
        uint8_t x=0;    //current AT
        int8_t maxi=processes.size();
        while (sorted.size()<maxi){
            i++;
            if (processes[i].arrivalTime<=x){
                ProcessIdDurationPair temp;
                temp.processId=processes[i].processId;
                temp.duration=processes[i].burstTime;
                sorted.push_back(temp);
                x=x+processes[i].burstTime;
                processes.erase(processes.begin()+i);
                i=-1;
                //std::cout<<(int)temp.processId;
            }
            if ((int)i==processes.size()){
                i=-1;
            }
        }
        return sorted;
    }
    else {
        std::cout<<"wrong algo";
    }
};

int main() {
    // implementation here
    Process p4;
    p4.processId=4;
    p4.arrivalTime=0;
    p4.burstTime=8;
    p4.priority=7;

    Process p2;
    p2.processId=2;
    p2.arrivalTime=0;
    p2.burstTime=3;
    p2.priority=4;

    Process p1;
    p1.processId=1;
    p1.arrivalTime=5;
    p1.burstTime=2;
    p1.priority=6;

    Process p3;
    p3.processId=3;
    p3.arrivalTime=5;
    p3.burstTime=2;
    p3.priority=1;



    std::vector<ProcessIdDurationPair> FCFS = schedule(SchedulingAlgo::FCFS,{p2,p1,p3,p4});
    for (auto elem : FCFS){
        std::cout<<"<"<<(int)elem.processId<<", "<<(int)elem.duration<<">, ";
    }
    std::cout<<std::endl;
    std::vector<ProcessIdDurationPair> Prior = schedule(SchedulingAlgo::Priority,{p1,p2,p3,p4});
    for (auto elem : Prior){
        std::cout<<"<"<<(int)elem.processId<<", "<<(int)elem.duration<<">, ";
    }
    std::cout<<std::endl;
    std::vector<ProcessIdDurationPair> SJF = schedule(SchedulingAlgo::SJF,{p1,p2,p3,p4});
    for (auto elem : SJF){
        std::cout<<"<"<<(int)elem.processId<<", "<<(int)elem.duration<<">, ";
    }

    //return std::vector<ProcessIdDurationPair>{};
}

