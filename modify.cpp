#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

struct Inven{
	char des[30];
	int qty;
	double price;
};

int main(){
	fstream file;
	Inven a;
	string filename;
	char ch;

	cout<<"Enter filename \n";
	cin>>filename;

	file.open(filename, ios::in | ios::out |ios::binary);

	if(!file)
	{
		cout<<"File Error\n";
		return -1;
	}

	long recordNum;
	do
	{

		cout<<"Enter the record number you would like to modify\n";
		cin>>recordNum;

		file.seekg(recordNum * sizeof(a), ios::beg);
		file.read(reinterpret_cast<char*>(&a), sizeof(a));

		cout<<"Enter description : \n";
		cin.ignore();
		cin.getline(a.des,30);
		cout<<"Enter quantity\n";
		cin>>a.qty;
		cout<<"Enter price \n";
		cin>>a.price;


		file.seekp(recordNum*sizeof(a),ios::beg);
		file.write(reinterpret_cast<char*>(&a), sizeof(a));
		cout<<"Do you want to modify another record\n";
		cin.ignore();
		cin.get(ch);
	}while(toupper(ch) == 'Y');


	file.close();

	return 0;
}