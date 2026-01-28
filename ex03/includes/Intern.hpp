#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
        ~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &src);

		AForm *makeForm(const std::string form, const std::string target);

};

#endif