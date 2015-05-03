#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BigInt
{
public:
	BigInt() {}
	BigInt(const BigInt & big) : number(big.number) {}
	BigInt(const BigInt & big, size_t size);
	BigInt(size_t len) : number(len) {}
	~BigInt() {}

	BigInt operator+(const BigInt & big) const;
	BigInt operator-(const BigInt & big) const;
	BigInt operator*(const BigInt & big) const;
	BigInt operator/(const BigInt & big) const;
	BigInt operator+=(const BigInt & big);
	BigInt operator=(const BigInt & big);

	BigInt operator*(const char& c) const;

	friend istream & operator>>(istream & fin, BigInt& big);
	friend ostream & operator<<(ostream & fout, const BigInt & big);

	int operator[](size_t index) const;

	bool operator<(const BigInt & big) const;
	bool operator==(const BigInt & big) const;
	bool operator<=(const BigInt & big) const;

	int size() const;
	int charToInt(size_t i);
	char set(size_t index) const;

private:

	void insert(const char c);
	void push_back(const char c);
	void plusNullEnd(size_t i);
	void plusNullBeg(size_t i);
	void erase();

	vector <char> number;
};