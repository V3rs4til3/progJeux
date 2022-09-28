#pragma once
#include "observer.hpp"
#include <iostream>
#include <string>

using namespace std;

class Policier : public Observer<string>{
private:
    string nom;
public:
    Policier(string nom){
        this->nom = nom;
    }
    void notification(string data){
        cout << nom << "se dirige vers" << data << endl;
    }
};