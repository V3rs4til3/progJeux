#include "dispatcher.hpp"
#include "policier.hpp"
#include "pompier.hpp"
#include "ambulancier.hpp"
#include <iostream>

int main(){
    Dispatcher<string> central;
    central.addIncIndent("Feux");
    central.addIncIndent("Accident");
    central.addIncIndent("Hospitalisation");
    central.addIncIndent("Catastrophne");

    Policier* chase = new Policier("Chase");
    Pompier* marcus = new Pompier("Marcus");
    Ambulancier* zuma = new Ambulancier("Zuma");

    central.avaible("Feux", marcus);
    central.avaible("Accident", chase);
    central.avaible("Hospitalisation", zuma);
    central.avaible("Catastrophne", zuma);
    central.avaible("Catastrophne", chase);


    return 0;
}