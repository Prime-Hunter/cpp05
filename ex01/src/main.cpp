#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat bob("Bob", 150);
    Bureaucrat bob2("Bob");
    Bureaucrat bob3(150);
    Bureaucrat bob4;
    Bureaucrat bob_copy(bob);

    bob.incGrade();
    bob.decGrade();
    bob.decGrade();
    bob.setGrade(1);
    bob.incGrade();

    try
    {
        bob.setGrade(0);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Decrementation of " << bob.getName() << "'s grade failed: " << e.what() << std::endl;
    }

    try
    {
        bob.setGrade(151);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Decrementation of " << bob.getName() << "'s grade failed: " << e.what() << std::endl;
    }
}