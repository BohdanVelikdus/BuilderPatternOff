#pragma once

#include <memory>
#include <vector>
#include <bitset>
#include <tuple>
#include <utility>

enum ExtraIngridients
{
    Onions = 0, Tomatoes, Cheese, Mayo, Ketchup, Meat, Cabbage
};

enum BreadType
{
    Flatbread = 0, Pita, Lavash 
}; 

enum SauceType
{
    Garlic = 0, Tahihi, Yogurt, Chili, Tomato, Curry, Barbeq
};

enum MeatType
{
    Chicken = 0, Beef, Lamb, Vegetarian
};


template <typename T>
class DonnerKebabBuilder
{
public:
    static DonnerKebabBuilder<T> Construct();
    DonnerKebabBuilder<T>& addExtra(const ExtraIngridients extra);
    T* build();

    DonnerKebabBuilder& setBreadType(BreadType breadType);

    template <typename... Args>
    DonnerKebabBuilder<T>& setMeatType(Args... meatTypes);

    template <typename... Args>
    DonnerKebabBuilder<T>& setSauce(Args... sauceTypes);
    
private:
    DonnerKebabBuilder<T>()
    {
        mp_Kebab = std::make_unique<T>();
    }
    std::unique_ptr<T> mp_Kebab;
};


template <typename T>
template <typename... Args>
DonnerKebabBuilder<T>& DonnerKebabBuilder<T>::setMeatType(Args... meatTypes)
{
    auto meats = std::make_tuple(meatTypes...);
    std::apply(
        [this](auto&&... Flags)
        {
            //mp_Kebab->mMeat.set(Flags...);
            ((mp_Kebab->mMeat.set(Flags)), ...); 
        }, meats);    
    return *this;
    
}

template <typename T>
template <typename... Args>
DonnerKebabBuilder<T> &DonnerKebabBuilder<T>::setSauce(Args... sauceTypes)
{
    auto sauces = std::make_tuple(sauceTypes...);
    std::apply(
        [this](auto&&... Flags)
        {
            (mp_Kebab->mSauces.set(Flags), ...);
        }, sauces);
    return *this;
}

template <typename T>
DonnerKebabBuilder<T> DonnerKebabBuilder<T>::Construct()
{
    return DonnerKebabBuilder<T>();
}

template <typename T>
T* DonnerKebabBuilder<T>::build()
{
    T* obj = mp_Kebab.release();
    return obj;
}

template <typename T>
inline DonnerKebabBuilder<T>& DonnerKebabBuilder<T>::setBreadType(BreadType breadType)
{
    mp_Kebab->mBreadType = breadType;
    return *this;
}


template <typename T>
DonnerKebabBuilder<T>& DonnerKebabBuilder<T>::addExtra(const ExtraIngridients extra){
    mp_Kebab->m_Extras.push_back(extra);
    return *this;
}
