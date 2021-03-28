/*
Richard Ngo 
Vegetable.cpp 
declaration of the Vegetable.cpp class
6/3/20
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<vector>
using namespace std;

#include "Vegetable.hpp"
// including multiple libraries and vegetable hpp 

Vegetable::Vegetable(const std::string &in_file):Produce(in_file){
  //vegie constructior defined after calling the produce constructor
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

    fL>>veggie_type;

    fL.close();
}
string Vegetable::getVeggieType(){
    if(veggie_type==0){
        return"root";
    }else if(veggie_type==1){
        return"cruciferous";
    }else if(veggie_type==2){
        return"edible stem";
    }else if(veggie_type==3){
        return"leafy green";
    }else if(veggie_type==4){
        return"legume";
    }else if(veggie_type==5){
        return"marrow";
    }else{
        return"allium";
    }
}
