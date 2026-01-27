#include "../includes/Form.hpp"

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

Form::Form(): _name("standard"), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "The " << this->getName() << " form has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
}

Form::Form(const std::string name): _name(name), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "The " << this->getName() << " form has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
}

Form::Form(int signGrade, int execGrade): _name("standard"), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "The " << this->getName() << " form has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
    if (signGrade < 1 || execGrade < 1)
    {
        throw(Form::GradeTooHighException());
    }
    else if (signGrade > 150 || execGrade > 150)
    {
        throw(Form::GradeTooLowException());
    }
}

Form::Form(const std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "The " << this->getName() << " form has been created. Signing grade: " << this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
    if (signGrade < 1 || execGrade < 1)
    {
        throw(Form::GradeTooHighException());
    }
    else if (signGrade > 150 || execGrade > 150)
    {
        throw(Form::GradeTooLowException());
    }   
}

Form::~Form()
{
    std::cout << "Deconstructor for " << this->getName() << " form called" << std::endl;
}

Form::Form(const Form &copy): _name(copy.getName() + "_copy"), _signed(false), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << copy.getName() << " to " << this->getName() << std::endl;
	*this = copy;
}

const std::string Form::getName()const
{
    return (this->_name);
}

bool Form::isSigned()const
{
    return (this->_signed);
}

int Form::getSignGrade()const
{
    return (this->_signGrade);
}

int Form::getExecGrade()const
{
    return (this->_execGrade);
}

void Form::beSigned(Bureaucrat &signer)
{
    if (this->_signed == true)
    {
        std::cout << this->getName() << " form is already signed" << std::endl;
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
            std::cout << this->getName() << " form was signed by " << signer.getName() << std::endl;
	    }
    }
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade too high");
};

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() << "\n\texec-grade:\t" << a->getExecGrade() << "\n\tis signed:\t" << a->isSigned() << std::endl;
	return (o);
}