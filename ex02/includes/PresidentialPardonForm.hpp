#ifndef PP_FORM_HPP
#define PP_FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator =(const PresidentialPardonForm &src);

        std::string getTarget(void)const;
        void execute(Bureaucrat const &executor)const;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif