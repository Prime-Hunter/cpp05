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
        Form();
		Form(const std::string name);
        Form(int signGrade, int execGrade);
		Form(const std::string name, int signGrade, int execGrade);
        virtual ~Form();
        Form(const Form &copy);
        Form &operator =(const Form &src);

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

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif