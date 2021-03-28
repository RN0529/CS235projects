#include <string>

#ifndef FRUIT_
#define FRUIT_
#include "Produce.hpp"


class Fruit :public Produce
{
    public:
      Fruit(const std::string &in_file);
      bool getPitted();
      bool getPeelableSkin();
      bool getRind();
      bool getEdibleSeeds();
    private:
      bool is_pitted;
      bool has_peelable_skin;
      bool has_rind;
      bool has_edible_seed;


}; // end Fruit
#endif