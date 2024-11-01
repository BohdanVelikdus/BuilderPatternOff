#include <iostream>
#include <memory>

#include "DonnerKebabBuilder.hpp"
#include "Kebab.hpp"

int main()
{
    std::unique_ptr<VegeterianKebab> vg(DonnerKebabBuilder<VegeterianKebab>::Construct().setBreadType(BreadType::Pita).setMeatType(MeatType::Beef, MeatType::Chicken).setSauce(SauceType::Barbeq, SauceType::Garlic).addExtra(ExtraIngridients::Cheese).build());
    vg->printOutInfo();
    return 0;
}