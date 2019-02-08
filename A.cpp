#include <iostream>

using namespace std;

int f(int arr[], int ptr, int time){
	if(ptr == 0){
		if(arr[ptr] == -1){
			time++;
		}
		return time;
	}
	if(arr[ptr] == 1){
		return f(arr, ptr-1, time);
	}
	else{
		time++;
		for(int i=0;i<ptr;i++){
			if((ptr+1)%(i+1) == 0){
				arr[i] = -1*(arr[i]);
		}
	}
		return f(arr,ptr-1, time);
	}
}

int main(){
	int n, a;
	cin >> n;
	int state[n];
	for(int i=0;i<n;i++){
		scanf("%d", &a);
		if(a == 0){
			a = -1;
		}
		state[i] = a;
	} 

	cout << f(state, n-1, 0) << endl;
	
}
