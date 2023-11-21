#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
        std::string type;
    public:
        ATarget();
        ATarget(const ATarget& c);
        ATarget& operator=(const ATarget& c);
        
        ATarget(const std::string& type);
        virtual ~ATarget();

        const std::string& getType() const;
        virtual ATarget* clone() const = 0;

        void getHitBySpell(const ASpell& spell) const;
};

#endif