#include "Warlock.hpp"

Warlock::Warlock()
{
    return ;
}

Warlock::Warlock(const Warlock& c)
{
    (void)c;
    return ;
}

Warlock& Warlock::operator=(const Warlock& c)
{
    (void)c;
    return *this; 
}

Warlock::Warlock(const std::string& name, const std::string& title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!" << std::endl;
}


const std::string& Warlock::getName() const
{
    return this->name;
}

const std::string& Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(const std::string& newTitle)
{
    this->title = newTitle;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    if(spell)
    {
        if(map.find(spell->getName()) == map.end())
            map[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell*>::iterator it = map.find(name);

    if(it != map.end())
    {
        delete it->second;
        map.erase(name);
    }
}

void Warlock::launchSpell(std::string name, const ATarget& target)
{
    if(map.find(name) != map.end())
        map[name]->launch(target);
}




