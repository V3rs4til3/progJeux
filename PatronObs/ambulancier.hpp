#pragma once
#include "observer.hpp"
#include <iostream>

using namespace std;

class Ambulancier : public Observer<string>{
private:
    string nom;
public:
    Ambulancier(string nom){
        this->nom = nom;
    }
   void notification(string data){
        cout << nom << "se dirige vers" << data << endl;
    }
};