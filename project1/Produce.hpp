/*
Richard Ngo 
Produce.cpp 
declaration of the Produce.cpp class
6/3/20
*/

//declaring the structure of the produce class along with the enums of ripeness and condition
#include <string>

#ifndef PRODUCE_
#define PRODUCE_

namespace produce_details
{
    enum ripeness
    {
        OVERRIPE = 0,
        UNDERRIPE = 1,
        RIPE = 2
    };
    enum conditions
    {
        DAMAGED = 0,
        UNDAMAGED = 1
    };
} // namespace produce_details

class Produce
{
    public:
    //produce public members
      Produce(const std::string& in_file);
      std::string getName();
      double getWeight();
      double getPricePerPound(); 
      bool getOrganic(); 
      bool getPrePackaged(); 
      int getRipeness(); 
      int getCondition(); 
      std::string getRipenessStr(); 
      std::string getConditionStr(); 

    private:
    //produce private members
      std::string name;
      double weight;
      double price_per_pound;
      bool is_organic;
      bool is_pre_packaged;
      int ripeness;
      int condition;
}; // end Produce
#endif