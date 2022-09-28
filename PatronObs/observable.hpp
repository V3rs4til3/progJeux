#pragma once
#include <list>
#include <iostream>
#include "observer.hpp"

using namespace std;

template <typename T>

/// @brief Observable class
/// @details Intervention
class Observable {
private:
    list<Observer<T>*> observers;
public:
    void subscribe(Observer<string>* observer) {
        observers.push_back(observer);
    }

    void unsubscribe(Observer<string>* observer) {
        observers.remove(observer);
    }

    void notify(T data) {
       for(auto it : observers){
           it->notification(data);
       }
    }
};