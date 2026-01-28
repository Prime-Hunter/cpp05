#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm target constructor called. Target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy): Form("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called to copy " << copy.getName() << " to " << this->getName() << std::endl;

	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor called for " << this->getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

std::string ShrubberyCreationForm::getTarget()const
{
    return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if (this->getExecGrade() < executor.getGrade())
    {
		throw (Bureaucrat::GradeTooLowException());
    }
	else if (this->isSigned() == false)
    {
		throw (Form::FormNotSignedException());
    }
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

        int i = 0;
		while (i < 3)
		{
			outfile <<
			"         v\n" <<
			"        >X<\n" <<
			"         A\n" <<
			"        d$b\n" <<
			"      .d\\$$b.\n" <<
			"    .d$i$$\\$$b.\n" <<
			"       d$$@b\n" <<
			"      d\\$$$ib\n" <<
			"    .d$$$\\$$$b\n" <<
			"  .d$$@$$$$\\$$ib.\n" <<
			"      d$$i$$b\n" <<
			"     d\\$$$$@$b\n" <<
			"  .d$@$$\\$$$$$@b.\n" <<
			".d$$$$i$$$\\$$$$$$b.\n" <<
			"        ###\n" <<
			"        ###\n" <<
			"        ###\n" <<
		    std::endl;
            i++;
		}
		outfile.close();
	}
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() << ":\n\tsign-grade:\t" << a->getSignGrade() << "\n\texec-grade:\t" << a->getExecGrade() << "\n\tis signed:\t" << a->isSigned() << std::endl;
    return (o);
}