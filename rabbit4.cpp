#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int a,b,c,d,e,f,g;
	a=b=c=d=e=f=g=0;
	cin>>n;
	bool flag= false;
	string name[n];
	string max[n][17];
	string may[n][17];
	int temp[17];
	for(int i=0;i<n;i++){
		cin>>name[i];
		for(int j=0;j<17;j++){
			scanf("%c%c",&max[n][j],&may[n][j]);
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<17;j++){
			if(may[n][j]=="W"&&max[n][j]!="W"){
				temp[n]=max[n][j];
			}
			if(may[n][j]=="T"){
				temp[n]=max[n][j]+10;
			}
			if(may[n][j]=="B"&&max[n][j]!="W"){
				temp[n]=max[n][j]+20;
			}
			if(may[n][j]=="E"){
				temp[n]=100;
			}
			if(may[n][j]=="S"){
				temp[n]=200;
			}
			if(may[n][j]=="W"&&max[n][j]=="W"){
				temp[n]=300;
			}
			if(may[n][j]=="N"){
				temp[n]=400;
			}
			if(may[n][j]=="C"){
				temp[n]=500;
			}
			if(may[n][j]=="F"){
				temp[n]=600;
			}
			if(may[n][j]=="B"&&max[n][j]=="W"){
				temp[n]=700;
			}
		}
		sort(temp, temp+17);
		
	}
}
