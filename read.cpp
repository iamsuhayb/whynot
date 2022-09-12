#include <iostream>
#include <fstream>
using namespace std;

struct Inven
{
	char des[30];
	int qty;
	double price;
};

int main(){

	Inven a;

	fstream file;
	string filename;
	cout<<"Enter the name of the file\n";
	cin>>filename;

	file.open(filename, ios::in|ios::binary);
	int i=0;

	while(!file.eof())
	{
		file.read(reinterpret_cast<char*>(&a), sizeof(a));
		cout<<"Record "<< (i+1)<<endl;
		cout<<"Description : "<<a.des<<endl;
		cout<<"Quantity : "<<a.qty<<endl;
		cout<<"Price : "<<a.price<<endl;
		cout<<"**************************\n";
		i++;
	}

	file.close();


	return 0;

}