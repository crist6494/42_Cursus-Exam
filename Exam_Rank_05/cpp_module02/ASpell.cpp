# include "ASpell.hpp"

ASpell::ASpell()
{
    return ;
}

ASpell::ASpell(const ASpell& c)
{
    (void)c;
    return ;
}

ASpell& ASpell::operator=(const ASpell& c)
{
    (void)c;
    return *this;
}


ASpell::ASpell(const std::string& name, const std::string& effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell::~ASpell()
{
    return ;
}

        
std::string ASpell::getName() const
{
    return this->name;
}

std::string ASpell::getEffects() const
{
    return this->effects;
}

void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}