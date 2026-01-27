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

