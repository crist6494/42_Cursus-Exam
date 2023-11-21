#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook& s)
{
    (void)s;
    return ;
}

SpellBook& SpellBook::operator = (const SpellBook& s)
{
    (void)s;
    return *this;
}

SpellBook::SpellBook()
{
    return ;
}
SpellBook::~SpellBook()
{
    std::map<std::string, ASpell*>::iterator it;
    for(it = map.begin(); it != map.end(); it++)
        delete it->second;
    map.clear();
    return ;
}

void SpellBook::learnSpell(ASpell* spell)
{
    if(spell)
    {
        if(map.find(spell->getName()) == map.end())
            map[spell->getName()] = spell->clone();
    }

}

void SpellBook::forgetSpell(std::string const &name)
{
    std::map<std::string, ASpell*>::iterator it = map.find(name);

    if(it != map.end())
    {
        delete it->second;
        map.erase(name);
    }
}

ASpell* SpellBook::createSpell(std::string const &name)
{
    ASpell*tmp;
    if(map.find(name) != map.end())
    {
        tmp = map[name]->clone();
        return tmp;
    }
    return NULL;
}

