/*
Richard Ngo 
Produce.cpp 
declaration of the Produce.cpp class
6/3/20
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<vector>
using namespace std;

#include "Produce.hpp"

using namespace std;
Produce::Produce(const std::string& in_file){
    ifstream fL;
    //ifstream for the input file
    fL.open(in_file);
    if (fL.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string test;
    getline(fL, test);
    //importing all the elements of txt file into respected private variables
    fL>>name>>weight>>price_per_pound>>is_organic>>is_pre_packaged>>ripeness>>condition;

    fL.close();

}

string Produce::getName(){
    return name;
}
double Produce::getWeight(){
    return weight;

}
double Produce::getPricePerPound(){
    return price_per_pound;

}
bool Produce::getOrganic(){
    return is_organic;
}
bool Produce::getPrePackaged(){
    return is_pre_packaged;

}
int Produce::getRipeness(){
    return ripeness;
}
int Produce::getCondition(){
    return condition;
}
string Produce::getRipenessStr(){
    if(ripeness==0){
        return "overripe";
    }else if(ripeness==1){
        return "underripe";
    }else{
        return "ripe";
    }
}

string Produce::getConditionStr(){
    if(condition==0){
        return "damaged";
    }else{
        return "undamaged";
    }
}
