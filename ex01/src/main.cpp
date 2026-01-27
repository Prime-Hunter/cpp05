#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
    Bureaucrat bob("Bob", 150);
    Bureaucrat tom("Tom", 1);
    
    Form first;
    Form jop_app("Job application");
    Form easy_form(150, 150);
    try
    {
        Form unusual_form(0, 151);
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form hard_form("Nuclear launch codes", 1, 1);
    Form first_cpy(first);

    bob.signForm(easy_form);
    tom.signForm(easy_form);
    bob.signForm(hard_form);
    tom.signForm(hard_form);
}