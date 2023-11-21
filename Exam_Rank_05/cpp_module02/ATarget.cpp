#include "ATarget.hpp"

ATarget::ATarget()
{
    return;
}

ATarget::ATarget(const ATarget& c)
{
    (void)c;
    return;
}

ATarget& ATarget::operator=(const ATarget& c)
{
    (void)c;
    return *this;
}

        
ATarget::ATarget(const std::string& type)
{
    this->type = type;
}

ATarget::~ATarget()
{
    return ;
}


const std::string& ATarget::getType()const
{
    return this->type;
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}

