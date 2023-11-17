#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Fwoosh.hpp"
# include "Dummy.hpp"
# include<map>

class Warlock
{
    private:
        std::map<std::string, ASpell*>map;
        std::string name;
        std::string title;
        Warlock();
        Warlock(const Warlock& cpy);
        Warlock& operator=(const Warlock& src);
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& newTitle);
        void introduce() const;

        void learnSpell(ASpell* learn);
        void forgetSpell(std::string spellName);
        void launchSpell(const std::string spellName, const ATarget& target);
};

#endif