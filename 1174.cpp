#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n, m, min;
	cin >> n >> m;
	int a[n], b[m];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<m;i++){
		cin >> b[i];
	}
	min = abs(a[0]-b[0]);
	for(int i=0;i<n;i++){
		for(int j=i;j<m;j++){
			if(abs(a[i]-b[j]) < min){
				min = abs(a[i]-b[j]);
			}
		}
	}
	
	cout << min << endl;
}
