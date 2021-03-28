/*
Richard Ngo 
Solution.cpp 
declaration of the Solution.cpp class 
    this cpp only contains one function that returns a string of if you should buy a certian produce given any produce
6/3/20
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<vector>
using namespace std;
#include "Produce.hpp"
#include "Fruit.hpp"
#include "Vegetable.hpp"

namespace solution{
  
  string shouldIBuyThis(Produce * product){
    int ripeness,condition;
    string productName,conditionName,ripenessName;

    ripeness = product->getRipeness();
    condition = product -> getCondition();
    productName = product->getName();
    ripenessName = product->getRipenessStr();
    conditionName = product->getConditionStr();
    if(condition==1 && (ripeness==1 || ripeness==2)){
      //if ripe or underripe and undamaged return
      return("Yes, you should buy this "+ productName +" because it is " + ripenessName+" and "+ conditionName+".");

    }else if( ripeness==0){
      //if overripe
      return("No, you should not buy this "+ productName +" because it is " + ripenessName+" and "+ conditionName+".");
    
    }else if( (ripeness==1 || ripeness==2) && condition ==0){
      //if ripe or underipe and damaged
      return("It is not the best idea to buy this "+ productName +" because it is " + ripenessName+" and "+ conditionName+".");

    }
    return "something went wrong";

  }

}//namespace solution