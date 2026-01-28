#include "../includes/AForm.hpp"

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

AForm::AForm(): _name("standard"), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "The " << this->getName() << " AForm has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
}

AForm::AForm(const std::string name): _name(name), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "The " << this->getName() << " AForm has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
}

AForm::AForm(int signGrade, int execGrade): _name("standard"), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "The " << this->getName() << " AForm has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
    if (signGrade < 1 || execGrade < 1)
    {
        throw(AForm::GradeTooHighException());
    }
    else if (signGrade > 150 || execGrade > 150)
    {
        throw(AForm::GradeTooLowException());
    }
}

AForm::AForm(const std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "The " << this->getName() << " AForm has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
    if (signGrade < 1 || execGrade < 1)
    {
        throw(AForm::GradeTooHighException());
    }
    else if (signGrade > 150 || execGrade > 150)
    {
        throw(AForm::GradeTooLowException());
    }   
}

AForm::~AForm()
{
    std::cout << "Deconstructor for " << this->getName() << " AForm called" << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy.getName() + "_copy"), _signed(false), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "AForm Copy Constructor called to copy " << copy.getName() << " to " << this->getName() << std::endl;
	*this = copy;
}

const std::string AForm::getName()const
{
    return (this->_name);
}

bool AForm::isSigned()const
{
    return (this->_signed);
}

int AForm::getSignGrade()const
{
    return (this->_signGrade);
}

int AForm::getExecGrade()const
{
    return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat &signer)
{
    if (this->_signed == true)
    {
        std::cout << this->getName() << " AForm is already signed" << std::endl;
    }
    else
    {
        if (signer.getGrade() > this->getSignGrade())
        {
            throw(Bureaucrat::GradeTooLowException());
        }
        else
        {
            this->_signed = true;
            std::cout << this->getName() << " AForm was signed by " << signer.getName() << std::endl;
	    }
    }
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm's grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm's grade too high");
};

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm's signature is required before executing");
};

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "AForm " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() << "\n\texec-grade:\t" << a->getExecGrade() << "\n\tis signed:\t" << a->isSigned() << std::endl;
	return (o);
}