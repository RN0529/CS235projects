/*
Richard Ngo 
Vegetable.hpp
declaration of the Fruit.hpp class
6/3/20
*/

//declaring the structure of the vegetable class and the enum vegetable categories
#include <string>

#ifndef VEGETABLE_
#define VEGETABLE_
#include "Produce.hpp"
using namespace std;

namespace categories
{
 enum veggie_categories{
    ALLIUM = 0,
    CRUCIFEROUS = 1,
    EDIBLE_STEM = 2,
    LEAFY_GREEN = 3,
    LEGUME = 4,
    MARROW = 5,
    ROOT = 6
 };
}//namespace categories

class Vegetable :public Produce
{
    public:
        Vegetable(const std::string &in_file);
        string getVeggieType();
    private:
        int veggie_type;
}; // end vegetable 
#endif