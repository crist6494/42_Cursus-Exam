#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Fwoosh.hpp"
# include "Dummy.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        Warlock();
        Warlock(const Warlock& c);
        Warlock& operator=(const Warlock& c);
        std::map<std::string, ASpell*>map;
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