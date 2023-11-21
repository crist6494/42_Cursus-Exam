#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        std::string name;
        std::string effects;
    public:
        ASpell();
        ASpell(const ASpell& c);
        ASpell& operator=(const ASpell& c);

        ASpell(const std::string& name, const std::string& effects);
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;

        virtual ASpell* clone() const = 0;

        void launch(const ATarget& target) const;
};

#endif