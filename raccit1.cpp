#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main(){
	int n;
	int a,b,c,d,e,f,g;
	a=b=c=d=e=f=g=0;
	cin>>n;
	bool flag= false;
	string name[n];
	char max[n][17];
	char may[n][17];
	int temp[n][17];
	int temp1[17];
	for(int i=0;i<n;i++){
		cin>>name[i];
		for(int j=0;j<17;j++){
			scanf("%c%c", &max[i][j], &may[i][j]);
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<17;j++){
			int temp[i][j] = max[i][j];	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<17;j++){
			if(temp[i][j] == "W" && max[i][j] != "W"){
				temp1[j] = x;
			}
			if(temp[i][j]=="T"){
				temp1[j]= x + 10;
			}
			if(temp[i][j]=="B" && temp[i][j]!="W"){
				temp1[j]=max[i][j]+20;
			}
			if(temp[i][j]=="E"){
				temp1[j]=100;
			}
			if(temp[i][j]=="S"){
				temp1[j]=200;
			}
			if(temp[i][j]=="W"&&temp[i][j]=="W"){
				temp1[j]=300;
			}
			if(temp[i][j]=="N"){
				temp1[j]=400;
			}
			if(temp[i][j]=="C"){
				temp1[j]=500;
			}
			if(temp[i][j]=="F"){
				temp1[j]=600;
			}
			if(temp[i][j]=="B"&&temp[i][j]=="W"){
				temp1[j]=700;
			}
		}
	}
	sort (temp1,temp1+17);
}
