#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
private:
	static const int last_name_width = 15;
	static const int first_name_width = 15;
	static const int age_width = 3;
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	// Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	Human() :last_name(""), first_name(""), age(0) {};
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods:
	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y/o";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(last_name_width);
		ofs << std::left;
		ofs << last_name;
		ofs.width(first_name_width);
		ofs << std::left;
		ofs << first_name;
		ofs.width(age_width);
		ofs << std::left;
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student :public Human
{
private:
	static const int speciality_width = 25;
	static const int group_width = 8;
	static const int rating_width = 8;
	static const int attendance_width = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	// Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student() :speciality(""), group(""), rating(0), attendance(0) {};
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	// Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{

		Human::print(ofs);
		ofs.width(speciality_width);
		ofs << speciality;
		ofs.width(group_width);
		ofs << group;
		ofs.width(rating_width);
		ofs << rating;
		ofs.width(attendance_width);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		char sz_buffer[speciality_width + 1]{};
		ifs.read(sz_buffer, speciality_width);
		for (int i = speciality_width - 1; sz_buffer[i] == ' '; i--) sz_buffer[i] = 0;
		while (sz_buffer[0] == 0) for (int i = 0; sz_buffer[i]; i++) sz_buffer[i] = sz_buffer[i + 1];
		this->speciality = sz_buffer;
		ifs >> group;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Teacher :public Human
{
private:
	static const int speciality_width = 25;
	static const int experience_width = 3;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	// Constructors:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	Teacher() :speciality(""), experience(0) {};
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	// Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << speciality << " " << experience << " years";
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs);
		ofs.width(speciality_width);
		ofs << speciality;
		ofs.width(experience_width);
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		char sz_buffer[speciality_width + 1]{};
		ifs.read(sz_buffer, speciality_width);
		for (int i = speciality_width - 1; sz_buffer[i] == ' '; i--) sz_buffer[i] = 0;
		while (sz_buffer[0] == 0) for (int i = 0; sz_buffer[i]; i++) sz_buffer[i] = sz_buffer[i + 1];
		this->speciality = sz_buffer;
		ifs >> experience;
		return ifs;
	}
};

class Graduate :public Student
{
private:
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	// Constructors:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate() :subject("") {};
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	// Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Student::print(ofs) << " " << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

//#define INHERITANCE_CHECK
//#define POLYMORPHISM_CHECK

void print(Human* group[], const int n);
void save(Human* group[], const int n, const char sz_filename[]);
int count_lines(const char* filename);
Human* allocate_object(const std::string& classname);
Human** load(const char* sz_filename, int& n);

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human human("Montana", "Antonio", 25);
	human.print();

	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	teacher.print();

	Graduate graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenberg");
	graduate.print();
#endif // INHERITANCE CHECK

#ifdef POLYMORPHISM_CHECK
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 80, 70, "How to catch Heisenberg"),
		new Student("Vercetti", "Thomas", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 25)
	};
	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");


	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
}
#endif // POLYMORPHISM_CHECK

	int n = 0;
	Human** group = load("group.txt", n);
	print(group, n);
}

void print(Human* group[], const int n)
{
	cout << delimiter;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << *group[i];
		cout << delimiter;
	}
}
void save(Human* group[], const int n, const char sz_filename[])
{
	std::ofstream fout(sz_filename);
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	std::string command = "notepad ";
	command += sz_filename;
	system(command.c_str());
}
int count_lines(const char* filename)
{
	std::ifstream file(filename);
	if (!file) return -1;
	int count = 0;
	char array[1000];
	while (!file.eof())
	{
		count++;
		file.getline(array, 1000);
	}
	file.close();
	return --count;
}
Human* allocate_object(const std::string& classname)
{
	if (classname.find("class Human") != std::string::npos) return new Human();
	if (classname.find("class Student") != std::string::npos) return new Student();
	if (classname.find("class Teacher") != std::string::npos) return new Teacher();
	if (classname.find("class Graduate") != std::string::npos) return new Graduate();
	return nullptr;
}
Human** load(const char* sz_filename, int& n)
{
	n = 0;
	std::ifstream fin(sz_filename);
	Human** result = nullptr;
	std::string buffer;
	while (!fin.eof())
	{
		std::getline(fin, buffer);
		if (buffer.empty())continue;
		n++;
	}
	result = new Human * [n] {};
	fin.clear();
	fin.seekg(0);
	for (int i = 0; i < n; i++)
	{
		std::getline(fin, buffer, ':');
		result[i] = allocate_object(buffer);
		if (result[i])fin >> *result[i];
	}
	fin.close();
	return result;
}