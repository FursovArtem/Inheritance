#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	std::ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	fout << "Hello Files" << endl;
	fout << "Сам привет!\n";
	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		const int size = 10240;
		char sz_buffer[size]{};
		while (!fin.eof())
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, size);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else std::cerr << "Error: file not found" << endl;
#endif // READ_FROM_FILE

	// 1
	std::ifstream fin("201 RAW.txt");
	const int size = 24;
	std::string array[size];
	for (int i = 0; i < size; i++)
	{
		fin >> (i % 2 ? array[i - 1] : array[i + 1]);
	}
	fin.close();
	std::ofstream fout("201 ready.txt");
	for (int i = 0; i < size; i++)
	{
		fout << array[i] << "\t";
		if (i % 2)fout << endl;
	}
	fout.close();

	system("notepad 201 ready.txt");


	// 2
	fout.open("201.dhcpd");
	for (int i = 0, j = 0; i < size / 2; i++)
	{
		fout << "host 201-" << i + 1 << "\n{\n\thardware ethernet\t" << array[j++];
		fout << ";\n\tfixed-adress\t\t" << array[j++] << ";\n}\n" << endl;
	}
	fout.close();

	system("notepad 201.dhcpd");
}