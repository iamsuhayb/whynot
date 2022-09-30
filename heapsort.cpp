#include <iostream>
//#define left(i) (i<<1)
//#define right(i) (i<<1)|1
//#define parent(i) i>>1
using namespace std;
const int size=11;

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}
void heapify(int a[], int i, int n)
{
	int left = 2*i; //left(i);
	int right = 2*i+1; //right(i);
	int largest=i;
	if(left < n && a[left] > a[largest])
		largest = left;
	if(right< n && a[right] > a[largest])
		largest=right;

	if(largest != i)
	{
		int temp = a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,largest,n);
	}

}


void max_heap(int b[])
{
	//cout<<" size is : "<<(size/2)<<endl;
	for(int i=(size/2);i>0; i--)
	{
		//cout<<"calling heapify with "<<i<<endl;
		heapify(b,i,size);
	}

}

void print(int x[])
{
	for(int i=0; i<size; i++)
		cout<<x[i]<<" ";

	cout<<endl;
}


void heap_sort(int c[])
{
	cout<<"In the head sort\n";
	max_heap(c);

	for(int i=(size-1); i>0; i--)
	{
		//cout<<"before moving \n";
		//print(c);

		int temp = c[1];
		cout<<i<<" ";
		c[1]=c[i];
		c[i]=temp;
		heapify(c,1,i);
		//cout<<"After moving\n";
	}
	cout<<endl;
}



int  main()
{
	int one[size]={0,1,4,2,10,11,15,8,6,7,9};
	cout<<"Before\n";
	for(int i : one)
		cout<<i<<" ";
	cout<<endl;
	heap_sort(one);

	cout<<"After\n";

	for(int i : one)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}
