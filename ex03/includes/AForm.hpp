#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        AForm();
		AForm(const std::string name);
        AForm(int signGrade, int execGrade);
		AForm(const std::string name, int signGrade, int execGrade);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm &operator =(const AForm &src);

        const std::string getName()const;
        bool isSigned()const;
        int getSignGrade()const;
        int getExecGrade()const;

        void beSigned(Bureaucrat &signer);
        virtual void execute(Bureaucrat const &executor)const = 0;

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif