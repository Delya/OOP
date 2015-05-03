#include "Арифмерика.h"

void test_ar()
{
	BigInt a;
	BigInt b;

	ofstream fout;
	fout.open("output.txt");

	ifstream fin;
	fin.open("input.txt");

	fin >> a;
	//fout << a;

	fin >> b;
	//fout << b; 

	BigInt c = a + b;
	fout << c;

	fout.close();
	fin.close();  
}

int main()
{
	test_ar();
	system("pause");
	return 0;
}