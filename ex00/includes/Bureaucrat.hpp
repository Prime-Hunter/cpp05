#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator =(const Bureaucrat &src);

        const std::string getName()const;
        int getGrade()const;
        void incGrade();
        void decGrade();
        void setGrade(int grade);

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
};

#endif