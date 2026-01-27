#include "../includes/Form.hpp"

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_signed = src.isSigned();
    this->_signGrade = src.getSignGrade();
    this->_execGrade = src.getExecGrade();
	return *this;
}

Form::Form(): _name("standard"), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "The " this->getName() << " form has been created. Signing grade: ", this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
}

Form::Form(const std::string name): _name(name), _signed(false), _signGrade(150), _execGrade(150)
{
    std::cout << "The " this->getName() << " form has been created. Signing grade: ", this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
}

Form::Form(int signGrade, int execGrade): _name("standard"), _signed(false)
{
    try
    {
        this->setSignGrade(signGrade);
        this->setExecGrade(execGrade);
        std::cout << "The " this->getName() << " form has been created. Signing grade: ", this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << " form failed: " << e.what() << std::endl;
        std::cerr << "Setting both grades to default 150" << std::endl;
        this->setSignGrade(150);
        this->setExecGrade(150);
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << " form failed: " << e.what() << std::endl;
        std::cerr << "Setting both grades to default 1" << std::endl;
        this->setSignGrade(1);
        this->setExecGrade(1);
    }
}

Form::Form(const std::string name, int signGrade, int execGrade): _name(name), _signed(false)
{
    try
    {
        this->setSignGrade(signGrade);
        this->setExecGrade(execGrade);
        std::cout << "The " this->getName() << " form has been created. Signing grade: ", this->getSignGrade() << ", executing grade: " << this->getExecGrade() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << " form failed: " << e.what() << std::endl;
        std::cerr << "Setting both grades to default 150" << std::endl;
        this->setSignGrade(150);
        this->setExecGrade(150);
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << " form failed: " << e.what() << std::endl;
        std::cerr << "Setting both grades to default 1" << std::endl;
        this->setSignGrade(1);
        this->setExecGrade(1);
    }
}

Form::~Form()
{
    std::cout << "Deconstructor for " << this->getName() << " form called" << std::endl;
}

Form::Form(const Form &copy): _name(copy.getName() + "_copy")
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
            throw(Bureaucrat::GradeTooLowException)
        }
        else
        {
            this->_signed = true;
            std::cout << this->getName() << " form was signed by " << signer.getName() << std::endl;
	    }
    }
}

void Form::setSignGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_signGrade = grade;
}

void Form::setExecGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_execGrade = grade;
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
	o << "Form " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() << "\n\texec-grade:\t" << a->getExecGrade() << "\n\tis signed:\t" << a->getIsSigned() << std::endl;
	return (o);
}