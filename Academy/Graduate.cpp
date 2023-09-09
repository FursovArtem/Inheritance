#include "Graduate.h"

const std::string& Graduate::get_subject()const
{
	return subject;
}
void Graduate::set_subject(const std::string& subject)
{
	this->subject = subject;
}

// Constructors:
Graduate::Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject)
	:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
{
	set_subject(subject);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}

// Methods:
void Graduate::print()const
{
	Student::print();
	cout << subject << endl;
}