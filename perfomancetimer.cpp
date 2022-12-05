#include "perfomancetimer.h"
#include <chrono>
#include <iostream>

PerfomanceTimer::PerfomanceTimer(std::string a_name): start(std::chrono::high_resolution_clock::now()), name(a_name)
{
}

PerfomanceTimer::PerfomanceTimer(): start(std::chrono::high_resolution_clock::now()), name("Timer")
{
}
PerfomanceTimer::~PerfomanceTimer()
{
    double time=getTimeNS();
    std::cout << std::endl << std::endl << name << " abgelaufen: " << time/1000 << " ms[" << time << " ns]\n\n";
}

double PerfomanceTimer::getTimeNS()
{
    end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> zeit= end-start;
    return zeit.count()*1000000 ;
}
