# include "Fwoosh.hpp"

Fwoosh::Fwoosh()
    :ASpell("Fwoosh", "fwooshed")
{
    return;
}

Fwoosh::~Fwoosh()
{
    return ;
}

ASpell* Fwoosh::clone() const
{
    return new Fwoosh();
}
