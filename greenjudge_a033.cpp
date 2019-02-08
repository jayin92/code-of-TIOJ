#include <iostream>

using namespace std;

int main(){
	string a;
	string b="";
	cin >> a;
	
	cout << "|";
	int j = 3;
	if(a.size()>4){
		for(int i=a.size()-4;i<=a.size()-1;i++){
			b += a[i];
		}
	} else {
		 b = a;
	}
	for(int i=0;i<8-b.size();i++){
		cout << "_";
	}
	cout << b << "|";
	
}
