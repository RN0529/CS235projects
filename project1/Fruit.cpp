/*
Richard Ngo 
Fruit.cpp 
declaration of the Fruit.cpp class
6/3/20
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<vector>


using namespace std;


#include "Fruit.hpp"
//including the libraries and fruit.hpp and produce classes

Fruit::Fruit(const std::string &in_file):Produce(in_file){
    //fruit constructor that calls the produce constructor before importing the remaining variables.
  
    ifstream fL;
    //ifstream for the input file
    fL.open(in_file);
    if (fL.fail()) {
        cerr << "File cannot be opened for reading. umu" << endl;
        exit(1); // exit if failed to open the file
    }
    string test;
    getline(fL, test);
    //importing all the elements of txt file into respected private variables

    fL>>is_pitted>>has_peelable_skin>>has_rind>>has_edible_seed;

    fL.close();
}
bool Fruit::getPitted(){
    return is_pitted;

}
bool Fruit::getPeelableSkin(){
    return has_peelable_skin;

}
bool Fruit::getRind(){
    return has_rind;

}
bool Fruit::getEdibleSeeds(){
    return has_edible_seed;

}




