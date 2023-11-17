#include "ATarget.hpp"

ATarget::ATarget()
{
    return;
}

ATarget::ATarget(const ATarget& cpy)
{
    (void)cpy;
}

ATarget& ATarget::operator=(const ATarget& src)
{
    (void)src;
    return *this;
}

ATarget::~ATarget()
{
return ;
}

ATarget::ATarget(std::string type)
{
    this->type = type;
}


const std::string& ATarget::getType() const
{
    return this->type;
}

void ATarget::getHitBySpell(const ASpell& ASpell) const
{
    std::cout << this->type << " has been " << ASpell.getEffects() << "!" << std::endl;
}
