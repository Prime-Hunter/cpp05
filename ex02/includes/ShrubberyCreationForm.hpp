#ifndef SC_FORM_HPP
#define SC_FORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator =(const ShrubberyCreationForm &src);

        std::string getTarget(void)const;
        void execute(Bureaucrat const &executor)const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif