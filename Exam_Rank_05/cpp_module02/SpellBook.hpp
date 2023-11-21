#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell*>map;
        SpellBook(const SpellBook& s);
        SpellBook& operator = (const SpellBook& s);
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell* spell);
        void forgetSpell(std::string const &name);
        ASpell* createSpell(std::string const &name);
};

#endif