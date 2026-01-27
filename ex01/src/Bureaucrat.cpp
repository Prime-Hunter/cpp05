#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
    std::cout << "A bureaucrat has been created. Grade: " << this->getGrade() << ", Name: " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("default")
{
    try
    {
        this->setGrade(grade);
        std::cout << "A bureaucrat has been created. Grade: " << this->getGrade() << ", Name: " << this->getName() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << "failed: " << e.what() << std::endl;
        std::cerr << "Setting grade to default 150" << std::endl;
        this->_grade = 150;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << "failed: " << e.what() << std::endl;
        std::cerr << "Setting grade to default 1" << std::endl;
        this->_grade = 1;
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
    std::cout << "A bureaucrat has been created. Grade: " << this->getGrade() << ", Name: " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    try
    {
        this->setGrade(grade);
        std::cout << "A bureaucrat has been created. Grade: " << this->getGrade() << ", Name: " << this->getName() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << "failed: " << e.what() << std::endl;
        std::cerr << "Setting grade to default 150" << std::endl;
        this->_grade = 150;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Instanstiation of " << this->getName() << "failed: " << e.what() << std::endl;
        std::cerr << "Setting grade to default 1" << std::endl;
        this->_grade = 1;
    }
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName() + "_copy")
{
	std::cout << "Bureaucrat Copy Constructor called to copy " << copy.getName() << " to " << this->getName() << std::endl;
	*this = copy;
}

const std::string Bureaucrat::getName(void)const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

void Bureaucrat::incGrade(void)
{
	try
	{
		std::cout << "Incrementing " << this->getName() << "'s grade" << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Incrementation of " << this->getName() << "'s grade failed: " << e.what() << std::endl;
	}
}

void Bureaucrat::decGrade(void)
{
	try
	{
		std::cout << "Decrementing " << this->getName() << "'s grade" << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Decrementation of " << this->getName() << "'s grade failed: " << e.what() << std::endl;
	}
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

void Form::signForm(Form &form)
{
    try
    {
	    form.beSigned(*this);
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << this->getName << " couldn't sign " << form;getName() << " form: " e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's grade too high");
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}