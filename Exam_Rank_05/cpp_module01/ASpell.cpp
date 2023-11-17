#include "ASpell.hpp"

ASpell::ASpell()
{
    return;
}

ASpell::~ASpell()
{
    return;
}

ASpell::ASpell(const ASpell& cpy)
{
    (void)cpy;
}

ASpell& ASpell::operator=(const ASpell& src)
{
    (void)src;
    return *this;
}

ASpell::ASpell(std::string name, std::string effects)
{
    this->name = name;
    this->effects = effects;
}


std::string ASpell::getName() const
{
    return this->name;
}

std::string ASpell::getEffects() const
{
    return this->effects;
}

void ASpell::launch(const ATarget& ATarget) const
{
    ATarget.getHitBySpell(*this);
}
