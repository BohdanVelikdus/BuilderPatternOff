#pragma once 
#include <vector>
#include <string>
#include <bitset>
#include <type_traits>

#include "DonnerKebabBuilder.hpp"

class Kebab
{
public:
    virtual Kebab* Clone() = 0;
    virtual ~Kebab() = default;
};

template<typename T>
class KebabCRTP : public Kebab
{
public:
    KebabCRTP() = default;
    void printOutInfo() const; 
    virtual Kebab* Clone() override
    {
        return new T(*static_cast<T*>(this));
    }
    ~KebabCRTP() = default;    
protected:
    BreadType mBreadType = BreadType::Lavash;
    std::bitset<4> mMeat;
    std::bitset<7> mSauces;    
    std::vector<ExtraIngridients> m_Extras;
};

class DonnerKebab : public KebabCRTP<DonnerKebab>
{
private:
    template <typename DonnerKebab>
    friend class DonnerKebabBuilder;
};

class ShishKebab : public KebabCRTP<ShishKebab> 
{
private:
    template <typename ShishKebab>
    friend class DonnerKebabBuilder;
};

class VegeterianKebab : public KebabCRTP<VegeterianKebab>
{
private:
    template <typename VegeterianKebab>
    friend class DonnerKebabBuilder;
};  

template<typename T>
void KebabCRTP<T>::printOutInfo() const
{
    std::string kebabType;
    if(std::is_same<T, DonnerKebab>::value)
    {
        kebabType = "DonnerKebab";
    }else if(std::is_same<T, ShishKebab>::value)
    {
        kebabType = "ShishKebab";
    }
    else
    {
        kebabType = "VegeterianKebab";
    }
    std::string breadType;
    if(this->mBreadType == BreadType::Flatbread)
    {
        breadType = "Flatbread";
    }
    else if(this->mBreadType == BreadType::Pita)
    {
        breadType = "Pita";
    }
    else
    {
        breadType = "Lavash";
    }
    
    std::string meatType = "";
    if(mMeat.test(MeatType::Chicken))
        meatType+="Chicken ";
    if(mMeat.test(MeatType::Beef))
        meatType+="Beef ";
    if(mMeat.test(MeatType::Lamb))
        meatType+="Lamb ";
    if(mMeat.test(MeatType::Vegetarian))
        meatType+="Vegeterian ";
    
    std::string sauceTypes = "";
    if(mSauces.test(SauceType::Barbeq))
        sauceTypes+="Barbeq ";
    if(mSauces.test(SauceType::Chili))
        sauceTypes+="Chili ";
    if(mSauces.test(SauceType::Curry))
        sauceTypes+="Curry ";
    if(mSauces.test(SauceType::Garlic))
        sauceTypes+="Garlic ";
    if(mSauces.test(SauceType::Tahihi))
        sauceTypes+="Tahihi ";
    if(mSauces.test(SauceType::Tomato))
        sauceTypes+="Tomato ";
    if(mSauces.test(SauceType::Yogurt))
        sauceTypes+="Yogurt ";

    std::string extras = "";
    for(int i = 0; i < m_Extras.size(); ++i)
    {
        if(m_Extras[i] == ExtraIngridients::Cabbage)
            extras+="Cabbage ";
        else if(m_Extras[i] == ExtraIngridients::Cheese)
            extras+="Cheese ";
        else if(m_Extras[i] == ExtraIngridients::Ketchup)
            extras+="Ketchup ";
        else if(m_Extras[i] == ExtraIngridients::Mayo)
            extras+="Mayo ";
        else if(m_Extras[i] == ExtraIngridients::Meat)
            extras+="Meat ";
        else if(m_Extras[i] == ExtraIngridients::Onions)
            extras+="Onions ";
        else if(m_Extras[i] == ExtraIngridients::Tomatoes)
            extras+="Tomatoes ";
    }

    std::cout << "The " + kebabType << ":\n"
              << "\tBread type: " + breadType << "\n"
              << "\tMeat type: " + meatType << "\n"
              << "\tSauces: " + sauceTypes << "\n"
              << "\tExtras: " + extras <<"\n";

}