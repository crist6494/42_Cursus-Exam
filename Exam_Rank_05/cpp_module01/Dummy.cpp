# include "Dummy.hpp"

Dummy::Dummy()
    : ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy()
{
    return ;
}

ATarget* Dummy::clone()
{
    return new Dummy();
}
