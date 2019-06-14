#include<iostream>
using namespace std;
class test {
public:
	test() { cout << "def ctor \n"; }
	test(double a1) :a(a1) { cout << "par. ctor \n"; }

	inline test& operator++()
	{
		++this->a;
		return *this;
	}

	inline test& operator++(int)
	{
		test obj = *this;
		++obj.a;
		return *this;
	}

	inline test operator+(const test& other) { return this->a + other.a; }

	inline test operator-(const test& other) { return this->a - other.a; }

	inline test operator *(const test& other) { return a + other.a; }

	inline test operator /(const test& other) { return a / other.a; }



	inline test operator+=(const test& other) { a += other.a;	return *this; }

	inline test operator-=(const test& other) { a -= other.a;	return *this; }


	inline  bool operator<(const test& other) { return a < other.a; }
	inline bool operator>(const test& other) { return a > other.a; }
	inline bool operator==(const test& other) { return a == other.a; }
	inline bool operator!=(const test& other) { return a != other.a; }
	inline bool operator>=(const test& other) { return a >= other.a; }
	inline bool operator<=(const test& other) { return a <= other.a; }





private:
	//friend istream& operator>>(istream&, const test&);
	friend ostream& operator<<(ostream&, const test&);
	double a;
};

ostream& operator<<(ostream& cout, const  test& other)
{
	cout << other.a << endl;
	return cout;
}

/*istream &operator>>(istream&is, const test&other)
{
	is >> other.a;
	return is;
}*/


int main()
{
	test obj(1);
	cout << obj << endl;
	test obj1(12);
	cout << "+ operator= " << obj + obj1 << endl;
	cout << "- operator= " << obj - obj1 << endl;
	cout << "* operator= " << obj * obj1 << endl;
	cout << "/ operator= " << obj / obj1 << endl;
	if (obj == obj1) { cout << "true \n"; }
	else
	{
		cout << "operator =   \n";
	}

	if (obj < obj1) { cout << "< \n"; }
	else
		cout << "operator > \n";



	system("pause");
}