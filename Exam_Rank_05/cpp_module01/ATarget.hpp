#ifndef ATARGET_HPP
# define ATARGET_HPP

#include"ASpell.hpp"
# include <iostream>

class ASpell;

class ATarget
{
    private:
        std::string type;
    public:
        ATarget();
        ATarget(const ATarget& cpy);
        ATarget& operator=(const ATarget& src);

        ATarget(std::string type);
        virtual ~ATarget();

        const std::string& getType() const;
        virtual ATarget* clone() = 0;
        void getHitBySpell(const ASpell& ASpell) const;
};

#endif