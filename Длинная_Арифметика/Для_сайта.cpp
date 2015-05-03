//#include <iostream>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//class BigInt
//{
//public:
//	BigInt() {}
//	BigInt(const BigInt & big) : number(big.number) {}
//	BigInt(const BigInt & big, size_t size);
//	BigInt(size_t len) : number(len) {}
//	~BigInt() {}
//
//	BigInt operator+(const BigInt & big) const;
//	BigInt operator-(const BigInt & big) const;
//	BigInt operator*(const BigInt & big) const;
//	BigInt operator/(const BigInt & big) const;
//	BigInt operator+=(const BigInt & big);
//	BigInt operator=(const BigInt & big);
//
//	BigInt operator*(const char& c) const;
//
//	friend istream & operator>>(istream & fin, BigInt& big);
//	friend ostream & operator<<(ostream & fout, const BigInt & big);
//
//	int operator[](size_t index) const;
//
//	bool operator<(const BigInt & big) const;
//	bool operator==(const BigInt & big) const;
//	bool operator<=(const BigInt & big) const;
//
//	int size() const;
//	int charToInt(size_t i);
//	char set(size_t index) const;
//
//private:
//
//	void insert(const char c);
//	void push_back(const char c);
//	void plusNullEnd(size_t i);
//	void plusNullBeg(size_t i);
//	void erase();
//
//	vector <char> number;
//};
//
//BigInt::BigInt(const BigInt & big, size_t size)
//{
//	for (size_t i = 0; i < size; ++i)
//	{
//		number.push_back(big.number.at(i));
//	}
//}
//
//void BigInt::erase() //этот метод удаляет лишние нули
//{
//	size_t len = number.size();
//	vector <char>::iterator it = number.begin();
//	if (*it == '-')
//	{
//		++it;
//		--len;
//	}
//	while (it != number.end())
//	{
//		if (*it == '0')
//		{
//			it = number.erase(it); /*т.к возвращает указатель на след. элемент*/
//			--len;
//			continue;
//		}
//
//		if (*it != '0')
//		{
//			break;
//		}
//	}
//	if (len == 0)
//	{
//		number.push_back('0');
//	}
//}
//
//bool BigInt::operator<=(const BigInt & big) const
//{
//	if (((*this) < big) || (big == (*this)))
//	{
//		return true;
//	}
//	return false;
//}
//
//bool BigInt::operator==(const BigInt & big) const
//{
//	if (number.size() != big.number.size())
//	{
//		return false;
//	}
//	else
//	{
//		int size = number.size();
//		for (int i = 0; i < size; ++i)
//		{
//			if (number.at(i) != big.number.at(i))
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//bool BigInt::operator<(const BigInt& big) const
//{
//
//	if ((number.at(0) == '-') && (big.number.at(0) != '-'))
//	{
//		return true;
//	}
//	if ((number.at(0) != '-') && (big.number.at(0) == '-'))
//	{
//		return false;
//	}
//	if (number.size() < big.number.size())
//	{
//		return true;
//	}
//	else
//	{
//		if (number.size() > big.number.size())
//		{
//			return false;
//		}
//		else
//		{
//			int len = big.number.size();
//			int i;
//			for (i = 0; i < len; ++i)
//			{
//				if (number.at(i) < big.number.at(i))
//				{
//					return true;
//				}
//				if (number.at(i) > big.number.at(i))
//				{
//					return false;
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//void BigInt::push_back(const char c)
//{
//	number.push_back(c);
//}
//
//void BigInt::insert(const char c)
//{
//	number.insert(number.begin(), c);
//}
//
//int BigInt::size() const
//{
//	return number.size();
//}
//
//void BigInt::plusNullEnd(size_t i)
//{
//	for (; i > 0; --i)
//	{
//		number.push_back('0');
//	}
//}
//
//char BigInt::set(size_t index) const
//{
//	return number[index];
//}
//
//void BigInt::plusNullBeg(size_t i)
//{
//	for (; i > 0; --i)
//	{
//		number.insert(number.begin(), '0');
//	}
//}
//
//int BigInt::operator[](size_t index) const
//{
//	return number.at(index) - '0';
//}
//
//BigInt BigInt::operator=(const BigInt & big)
//{
//	number = big.number;
//	return (*this);
//}
//
//BigInt BigInt::operator/(const BigInt & big) const
//{
//	BigInt quot;
//	BigInt left(*this);
//	BigInt right(big);
//
//	size_t l_len = left.size();
//
//	if ((left < right) || (left.set(0) == '0'))
//	{
//		quot.push_back('0');
//		return quot;
//	}
//
//	if (right.set(0) == '0')
//	{
//		ofstream fout;
//		fout.open("output.txt");
//		fout << "Error";
//		fout.close();
//		return quot;
//	}
//
//	else
//	{
//		BigInt between;
//		between.push_back(left.set(0));
//
//		int i = 1;
//		while (between < right)
//		{
//			between.push_back(left.set(i));
//			++i;
//		}
//		--i;
//
//		BigInt mod;
//
//		char div;
//
//		while (i != l_len)
//		{
//			for (div = '0'; div <= '9'; ++div)
//			{
//				BigInt buf = right * div;
//				mod = between - buf;
//
//				if ((mod.set(0) != '-') && (mod < right))
//				{
//					quot.push_back(div);
//					between = mod;
//					between.push_back(left.set(i));
//					between.erase();
//					++i;
//					break;
//				}
//			}
//		}
//	}
//	return quot;
//}
//
//BigInt BigInt::operator*(const char &c) const
//{
//	BigInt multi;
//
//	if ((number.at(0) == '0') || (c == '0'))
//	{
//		multi.number.push_back('0');
//		return multi;
//	}
//
//	int i = number.size() - 1;
//	int div = 0, buf;
//	int m = c - '0';
//
//	for (; i >= 0; --i)
//	{
//		buf = number.at(i) - '0';
//		buf = buf * m + div;
//		if (buf > 9)
//		{
//			div = buf / 10;
//			buf %= 10;
//		}
//		else
//		{
//			div = 0;
//		}
//		if (multi.size() > 0)
//		{
//			multi.insert(buf + '0');
//		}
//		else
//		{
//			multi.push_back(buf + '0');
//		}
//	}
//
//	if (div != 0)
//	{
//		multi.insert(div + '0');
//	}
//
//	return multi;
//}
//
//BigInt BigInt::operator-(const BigInt &big) const
//{
//	BigInt min;
//	bool sign = 0;
//
//	if (*this == big)
//	{
//		min.number.push_back('0');
//		return min;
//	}
//
//	BigInt left, right;
//
//	left = (*this);
//	right = big;
//
//	int i = left.number.size() - 1;
//	int j = right.number.size() - 1;
//	int buf = 0, div = 0;
//
//	if (right < left)
//	{
//		right.plusNullBeg(i - j);
//	}
//	else
//	{
//		BigInt tmp = left;
//		left = right;
//		right = tmp;
//		sign = 1;
//
//		right.plusNullBeg(j - i);
//		i = j;
//	}
//
//	for (; i >= 0; i--)
//	{
//
//		if (left[i] < right[i] + div)
//		{
//			buf = left[i] + 10;
//			buf -= right[i] + div;
//			div = 1;
//		}
//		else
//		{
//			buf = left[i] - right[i] - div;
//			div = 0;
//		}
//		if (min.size() == 0)
//		{
//			min.push_back(buf + '0');
//		}
//		else
//		{
//			min.insert(buf + '0');
//		}
//	}
//
//	if (sign)
//	{
//		min.insert('-');
//	}
//
//	min.erase();
//
//	return min;
//}
//
//BigInt BigInt::operator+(const BigInt& big) const
//{
//	BigInt sum;
//	BigInt left, right;
//
//	left.number = (*this).number;
//	right.number = big.number;
//
//	int i = left.size() - 1;
//	int j = right.size() - 1;
//	int div = 0;
//
//	if (i < j)
//	{
//		left.plusNullBeg(j - i);
//		i = j;
//	}
//	else
//	{
//		right.plusNullBeg(i - j);
//		j = i;
//	}
//
//	for (; i >= 0; --i)
//	{
//		int buf = (left.number.at(i) - '0') + (right.number.at(i) - '0') + div;
//		if (buf > 9)
//		{
//			div = buf / 10;
//			buf %= 10;
//			if (sum.size() > 0)
//			{
//				sum.insert(buf + '0');
//			}
//			else
//			{
//				sum.push_back(buf + '0');
//			}
//
//		}
//		else
//		{
//			div = 0;
//			if (sum.size() > 0)
//			{
//				sum.insert(buf + '0');
//			}
//			else
//			{
//				sum.push_back(buf + '0');
//			}
//		}
//	}
//
//	if (div != 0)
//	{
//		sum.number.insert(sum.number.begin(), div + '0');
//	}
//	return sum;
//
//}
//
//BigInt BigInt::operator+=(const BigInt & big)
//{
//	(*this) = (*this) + big;
//	return (*this);
//}
//
//BigInt BigInt::operator*(const BigInt & big) const
//{
//	BigInt left((*this));
//	BigInt right(big);
//
//	int i = right.number.size() - 1;
//	int j = i;
//
//	BigInt multi;
//
//	if ((left.number.at(0) == '0') || (right.number.at(0) == '0'))
//	{
//		multi.push_back('0');
//		return multi;
//	}
//
//	BigInt between;
//	multi.push_back('0');
//
//	for (; i >= 0; --i)
//	{
//		between = left * right.number.at(i);
//		between.plusNullEnd(j - i);
//		multi += between;
//	}
//	return multi;
//}
//
//ostream & operator<<(ostream & out, const BigInt & big)
//{
//	size_t len = big.number.size();
//	size_t i;
//	size_t k = 0;
//
//	for (i = 0; i < len; ++i)
//	{
//		out << big.number.at(i);
//	}
//
//	out << "\n";
//
//	return out;
//}
//
//istream & operator>>(istream & fin, BigInt& big)
//{
//	char c;
//
//	fin.get(c);
//	while ((c != '\n') && (!fin.eof()) && (c != ' '))
//	{
//		big.number.push_back(c);
//		if (c != '\n') fin.get(c);
//	}
//
//	return fin;
//}
//
//int main()
//{
//	BigInt a;
//	BigInt b;
//
//	ofstream fout;
//	fout.open("output.txt");
//
//	ifstream fin;
//	fin.open("input.txt");
//
//	fin >> a;
//	//fout << a;
//
//	fin >> b;
//	//fout << b; 
//
//	BigInt c = a + b;
//	fout << c;
//
//	fout.close();
//	fin.close();
//	system("pause");
//	return 0;
//}