#include <iostream>
//#define and &&
using namespace std;
class feetinches{
private:
	int feet;
	int inches;
	void simplify();
public:
	feetinches(int f=0,int i=0)
	{
		feet=f;
		inches=i;
		simplify();
	}

	//mutators
	void setfeet(int f)
	{
		feet=f;
	}
	void setinches(int i)
	{
		inches=i;
	}
	//accessors
	int getfeet()const
	{
		return feet;
	}

	int getinches()const
	{
		return inches;
	}

	feetinches operator+(const feetinches &);
	feetinches operator-(const feetinches &);

	feetinches operator++()
	{
		inches++;
		simplify();
		return *this;
	}

	const feetinches operator++(int)
	{
		feetinches temp(feet,inches);
		inches++;
		simplify();
		return temp;
	}

	bool operator>(const feetinches &);
	bool operator<(const feetinches &);
	bool operator==(const feetinches &);
};

bool feetinches::operator<(const feetinches&right)
{
	bool status;
	if(feet < right.feet)
		return true;
	else if(feet == right.feet && inches < right.inches)
		return true;
	else
		return false;
}
bool feetinches::operator==(const feetinches &right)
{
	if(feet == right.feet and inches == right.inches)
		return true;
	else
		return false;
}

bool feetinches::operator>(const feetinches &right)
{
	bool status;
	if(feet > right.feet)
		return true;
	else if (feet == right.feet && inches > right.inches )
		return true;
	else
		return false;
}

void feetinches::simplify()
{
	if(inches>=12)
	{
		feet+= (inches/12);
		inches = (inches%12);
	}
	else if(inches <0)
	{
		feet -= ((abs(inches)/12)+1);
		inches = 12 - (abs(inches)%12);
	}
}
feetinches feetinches::operator-(const feetinches & right)
{
	feetinches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();

	return temp;
}

feetinches feetinches::operator+(const feetinches & right)
{
	feetinches temp;
	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();

	return temp;
}

int main(){

	feetinches a;
	int f, i;
	cout<<"Enter feet and inches separated by space\n";
	cin>>f>>i;
	a.setfeet(f);
	a.setinches(i);

	cout<<"Feet : "<<a.getfeet()<<endl;
	cout<<"Inches : "<<a.getinches()<<endl;

	cout<<"*************************\n";
	cout<<"Contents of b\n";

	feetinches b;
	cout<<"Enter feet and inches separated by space\n";
	cin>>f>>i;
	b.setfeet(f);
	b.setinches(i);

	cout<<"Feet : "<<b.getfeet()<<endl;
	cout<<"Inches : "<<b.getinches()<<endl;

	cout<<"*****************************\n";
	feetinches c;
	if(a==b)
	{
		cout<<"a and b are equal \n";
		c = a-b;
	}
	else if(a>b)
	{
		cout<<"a is greater than b. therefore, we are  doing a - b \n";
		//feetinches c;
		c = a-b;
	}
	else
	{
		cout<<"b is greater than a. therefore, we are doing b - a \n";
		c =  b - a;
	}
	cout<<"Result ******************\n";

	cout<<"Feet : "<<c.getfeet()<<endl;
	cout<<"Inches : "<<c.getinches()<<endl;

	return 0;
}












