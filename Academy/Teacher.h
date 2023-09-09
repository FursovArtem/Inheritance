#pragma once
#include "Human.h"

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience


class Teacher :public Human
{
private:
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const;
	int get_experience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(int experience);

	// Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS);
	~Teacher();

	// Methods:
	void print()const;
};