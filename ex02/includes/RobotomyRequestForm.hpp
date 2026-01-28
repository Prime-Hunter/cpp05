#ifndef RR_FORM_HPP
#define RR_FORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
    private:
        const std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator =(const RobotomyRequestForm &src);

        std::string getTarget(void)const;
        void execute(Bureaucrat const &executor)const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif