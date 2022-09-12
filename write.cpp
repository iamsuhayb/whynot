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

	fstream file;
	Inven a = {"one",0,0.0};
	string filename;
	cout<<"Enter the name of the file\n";
	cin>>filename;

	file.open(filename, ios::out | ios:: binary);

	if(!file)
	{
		cout<<"File doesn't exist \n";
		return 0;
	}

	for(int i=0; i<5; i++)
	{
		cout<<"Record "<<i<<endl;
		file.write(reinterpret_cast<char*>(&a),sizeof(a));
	}


	file.close();


	return 0;


}