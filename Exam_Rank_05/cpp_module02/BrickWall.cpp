# include "BrickWall.hpp"

BrickWall::BrickWall()
    :ATarget("Inconspicuous Red-brick Wall")
{
    return;
}

BrickWall::~BrickWall()
{
    return ;
}

ATarget* BrickWall::clone() const
{
    return new BrickWall();
}