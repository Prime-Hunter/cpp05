#include "../includes/RobotomyRequestForm.hpp"

static int fails = 0;

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 145, 137), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 145, 137), _target(target)
{
    std::cout << "RobotomyRequestForm target constructor called. Target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): Form("RobotomyRequestForm", 145, 137), _target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called to copy " << copy.getName() << " to " << this->getName() << std::endl;

	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor called for " << this->getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

std::string RobotomyRequestForm::getTarget()const
{
    return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	if (this->getExecGrade() < executor.getGrade())
    {
		throw (Bureaucrat::GradeTooLowException());
    }
	else if (this->isSigned() == false)
    {
		throw (Form::FormNotSignedException());
    }
	else if (fails++ % 2)
	{
        std::cout << this->getTarget() << " was robotomized" << std::endl;
    }
	else
    {
		std::cout << this->getTarget() << "'s robotomy failed" << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "Form " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() << "\n\texec-grade:\t" << a->getExecGrade() << "\n\tis signed:\t" << a->isSigned() << std::endl;
    return (o);
}