#pragma once

#include <chrono>

using namespace std::chrono;

class Chrono{
    steady_clock::time_point timePoint;
    
    double duration(){
        return duration_cast<milliseconds>(steady_clock::now() - timePoint).count();
    }

    double start(){
        timePoint = steady_clock::now();
        return duration();
    }

    void reset(){
        timePoint = steady_clock::now();
    }
}