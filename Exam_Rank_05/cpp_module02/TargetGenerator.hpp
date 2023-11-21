#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<std::string, ATarget*>map;
        TargetGenerator(const TargetGenerator& s);
        TargetGenerator& operator = (const TargetGenerator& s);
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* taget);
        void forgetTargetType(std::string const &name);
        ATarget* createTarget(std::string const &name);
};

#endif