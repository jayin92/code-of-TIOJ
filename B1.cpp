#include <iostream>
#include <string>
using namespace std;

//ASCII a=97 z=122

int main(){
	char hole[7] = {'a','b','d','e','o','p','q'};
	int n;
	cin >> n;
	string str[n];
	int temp = 0;
	int data[n][2];
	bool flag = 1;
	for(int i=0;i<n;i++){
		cin >> data[i][0] >> data[i][1];
		cin >> str[i];
	}
	
	for(int i=0;i<n;i++){
		int last_digit = str[i][data[i][0]-1];
		for(int j=data[i][0]-1;j>=0;j--){
			for(int k=97;k<123;k++){
				if(flag && k != 67){
					str[i][j] = k;
	//				cout << *str << endl;
					for(int h=0;h<data[i][0];h++){
						for(int t=0;t<7;t++){
							if(str[i][h]==hole[t]){
								temp++;
	//							cout << temp << endl;					
							}
						}
						
					}
					if(temp == data[i][1] && last_digit < str[i][data[i][0]-1]){
						cout << str[i] << endl;
						flag = 0;										
					}
					temp = 0;
				}
			}
			str[i][j] = 'a';
		}
		if(flag == 1){
			cout << "-1" << endl;
		}
		flag = 1;
	}
	return 0;
	
}
