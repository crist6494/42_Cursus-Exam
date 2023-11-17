#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
    private:
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
};

#endif