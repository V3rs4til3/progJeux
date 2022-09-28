#pragma once
#include "observer.hpp"
#include <iostream>

using namespace std;

class Pompier : public Observer<string> {
private:
    string nom;
public:

    Pompier(string nom){
        this->nom = nom;
    }
    void notification(string data){
       cout << nom << "se dirige vers" << data << endl;
    }
};