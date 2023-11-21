#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator& s)
{
    (void)s;
    return ;
}

TargetGenerator& TargetGenerator::operator = (const TargetGenerator& s)
{
    (void)s;
    return *this;
}

TargetGenerator::TargetGenerator()
{
    return ;
}
TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget*>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
        delete it->second;
    map.clear();
    return ;
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if(target)
    {
        if(map.find(target->getType()) == map.end())
            map[target->getType()] = target->clone();
    }

}

void TargetGenerator::forgetTargetType(std::string const &name)
{
    std::map<std::string, ATarget*>::iterator it = map.find(name);

    if(it != map.end())
    {
        delete it->second;
        map.erase(name);
    }
}

ATarget* TargetGenerator::createTarget(std::string const &name)
{
    ATarget*tmp;
    if(map.find(name) != map.end())
    {
        tmp = map[name]->clone();
        return tmp;
    }
    return NULL;
}
