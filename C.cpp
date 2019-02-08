#include <iostream>

using namespace std;

int main(){
	int n;
	int h = 0;
	cin >> n;
	int arr[n][2];
	int temp[2];
	for(int i = 0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	
	for(int i = 0;i<n;i++){
		h = 0;
		for(int j=0;j<2;j++){
			temp[j] = arr[i][j];
		}
		if(temp[1] % 2 == 1){
			temp[1]++;
			h++;
		}
		if((2*temp[0]+temp[1])%4==0){
			cout<< h+0.5*temp[0]+0.75*temp[1] << endl;
		}else{
			cout<<h+0.5*temp[0]+0.75*(temp[1])+3.5 << endl;
		}
	}
	return 0;
} 
