//Program demonstrating Array class

#include "Array.h"
#include <iostream>
using namespace std;

int main(){
	Array<int> a; //empty array
	for(int i=0;i<7;++i)
		a.push_back(i+1); //O(1)

	for(int i=0;i<7;++i)
		cout<<a[i]<<" "; //accessing time O(log(i))
	cout<<'\n';
	a.pop_back();	//O(1)
	cout<<a.back()<<"\n"; //O(1)

	a.push_back(8);  //O(1) or O(2*prev)

	for(int i=0;i<7;++i)
		cout<<a[i]<<" "; 
	Array<int> b(7);
	cout<<'\n';
	for(int i=0;i<7;++i){
		b[i] = 2*i+1;
	}
	for(int i=0;i<7;++i)
		cout<<b[i]<<" ";

}