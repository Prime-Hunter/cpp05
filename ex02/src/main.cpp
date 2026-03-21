#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		std::cout << "------------- Initializing -------------" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm("default");
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--------------- Deleting ---------------" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;

		std::cout << "------------- Initializing -------------" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		std::cout << std::endl;

		try
		{
			c->execute(*b);
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cerr << a->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign the AForm " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to sign the AForm " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->execute(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << b->getName() << " was not able to execute the AForm " << c->getName() << ": " << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "--------------- Deleting ---------------" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;

		std::cout << "------------- Initializing -------------" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << "------------- Simple Test --------------" << std::endl;
		b->beSigned(*a);
		a->signForm(*c);
		b->execute(*a);
		a->executeForm(*c);
		std::cout << std::endl;

		std::cout << "--------------- Deleting ---------------" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;

		std::cout << "------------- Initializing -------------" << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << "------------- Simple Test --------------" << std::endl;
		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		c->execute(*a);
		std::cout << std::endl;

		std::cout << "--------------- Deleting ---------------" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}