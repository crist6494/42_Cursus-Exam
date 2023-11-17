# include "Warlock.hpp"

Warlock::Warlock()
{
    return ;
}

Warlock::Warlock(const Warlock& cpy)
{
    (void)cpy;
}

Warlock& Warlock::operator=(const Warlock& src)
{
    (void)src;
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
    std::map<std::string, ASpell*>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
    {
        delete it->second;
    }
    map.clear();
} 

const std::string& Warlock::getName() const
{
    return this->name;
}

const std::string& Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(const std::string& title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* learn)
{
    if(learn)
    {
        if(map.find(learn->getName()) == map.end())
            map[learn->getName()] = learn;
    }
}

void Warlock::forgetSpell(std::string spellName)
{
    std::map<std::string, ASpell*>::iterator it = map.find(spellName);
    if(it != map.end())
        delete it->second;
    map.erase(map.find(spellName));
}

void Warlock::launchSpell(const std::string spellName, const ATarget& target)
{
    if(map.find(spellName) != map.end())
        map[spellName]->launch(target);
}
