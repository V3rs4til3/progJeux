#pragma once
#include <map>
#include <iostream>
#include "observable.hpp"
#include <string>

using namespace std;

template <typename t>
/// @brief 
/// @tparam t 
class Dispatcher{
private:
    map<string,Observable<string>*> incidents;
public:
    void addIncIndent(string nom){
        incidents[nom] = new Observable<string>();
    }

    void removeIncident(string nom){
        delete incidents[nom];
        incidents.erase(nom);
    }

    void avaible(string accident, Observer<string>* responder){
        incidents[accident]->subscribe(responder);
    }

    void unavaible(string accident, Observer<string>* responder){
        incidents[accident]->unsubscribe(responder);
    }

    void notify(string accident, string adresse){
        incidents[accident]->notify(adresse);
    }
};