#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Form *b = new Form();
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

		std::cout << b;
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new Form("Rent Contract", 140, 100);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;
		std::cout << b;
		std::cout << c;

		try
		{
			a->signForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

		std::cout << c;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << c;

		b->signForm(*c);
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Form *a = NULL;

		try
		{
			a = new Form(160, 145);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}
		try
		{
			a = new Form(145, 160);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		try
		{
			a = new Form(-15, 145);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		try
		{
			a = new Form(145, -15);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << "\033[33mConstructing default failed: " <<
			e.what() << "\033[0m" << std::endl;
		}

		if (a != NULL)
		{
			std::cout << std::endl;
			std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
			delete a;
		}
		std::cout << std::endl;
	}
	return (0);
}