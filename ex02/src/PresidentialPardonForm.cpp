#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm target constructor called. Target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): Form("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called to copy " << copy.getName() << " to " << this->getName() << std::endl;

	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor called for " << this->getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

std::string PresidentialPardonForm::getTarget()const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
    if (this->getExecGrade() < executor.getGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw (Form::FormNotSignedException());
    else
	    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "Form " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() << "\n\texec-grade:\t" << a->getExecGrade() << "\n\tis signed:\t" << a->isSigned() << std::endl;
    return (o);
}