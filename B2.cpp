#include <iostream>

using namespace std;
//ASCII a=97 z=122

int main(){
	char hole[7] = {'a','b','d','e','o','p','q'};
	int n;
	cin >> n;
	string str[n];
	string temp;
	int time = 0;
	int data[n][2];
	int len, holenum;
	bool confirm, haveg = 0;
	cin.tie(NULL);
	for(int i=0;i<n;i++){
		cin >> data[i][0] >> data[i][1];
		cin >> str[i];
	}
	for(int i=0;i<n;i++){
		temp = str[i];
		time = 0;
		confirm = 0;
		len = data[i][0];
		holenum = data[i][1];
		while(1){
			temp[len-1]++;
			haveg = 0;
			for(int j=len-1;j>=0;j--){
				if(temp[j]>122){
					if(j > 0){
						temp[j] = 'a';
						temp[j-1]++;
					}
					else{
						confirm = 1;						
					}
				}
			}
			for(int h=0;h<len;h++){
				for(int k=0;k<7;k++){
					if(temp[h] == 'g'){
						haveg = 1;
						h = len;
						k = 8;
					}
				    if(time > holenum){
						h = len;
						k = 8; 
					}
					else if(temp[h] == hole[k]){
						time++;						
					}					
				}
			}
			if(confirm){
				cout << "-1" << endl;
				break;				
			}
			else if(time == holenum && haveg == 0){
				cout << temp << endl;
				break;
			}			
			time = 0;
		}
	}
	
	return 0;
}
