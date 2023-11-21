# include "Dummy.hpp"

Dummy::Dummy()
    :ATarget("Target Practice Dummy")
{
    return;
}

Dummy::~Dummy()
{
    return ;
}

ATarget* Dummy::clone() const
{
    return new Dummy();
}