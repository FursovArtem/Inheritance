#pragma once
#include "Student.h"

class Graduate :public Student
{
private:
	std::string subject;
public:
	const std::string& get_subject()const;
	void set_subject(const std::string& subject);

	// Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject);
	~Graduate();

	// Methods:
	void print()const;
};