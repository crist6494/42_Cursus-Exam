#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;
        ASpell();
    public:
        ASpell(std::string name, std::string effects);
        ASpell(const ASpell& cpy);
        ASpell& operator=(const ASpell& src);

        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;
        virtual ASpell* clone() = 0;
        void launch(const ATarget& ATarget) const;
};

#endif