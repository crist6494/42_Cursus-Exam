#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Fwoosh.hpp"
# include "Dummy.hpp"
# include "SpellBook.hpp"
# include "Polymorph.hpp"
# include "Fireball.hpp"
# include "BrickWall.hpp"
# include "SpellBook.hpp"
# include "TargetGenerator.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock(const Warlock& c);
        Warlock& operator=(const Warlock& c);
        SpellBook book;
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();

        const std::string& getName() const;
        const std::string& getTitle() const;
        void setTitle(const std::string& newTitle);
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, const ATarget& target);
};

#endif