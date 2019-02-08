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
	int tempx[17];
	int tempy[17];
	int temp1[17];
	for(int i=0;i<n;i++){
		cin>>name[i];
		for(int j=0;j<17;j++){
			scanf("%c%c", &max[i][j], &may[i][j]);
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<17;j++){
			tempx[j]= int (max[i][j]);	
			tempy[j]= int (may[i][j]);	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<17;j++){
			if(tempx[j] == "W" && temp[i][j] != "W"){
				temp1[j]=tempx[j];
			}
			if(tempy[j]=="T"){
				temp1[j]=tempx[j]+ 10;
			}
			if(tempy[j]=="B" && tempx[j]!="W"){
				temp1[j]=tempx[j]+20;
			}
			if(tempy[j]=="E"){
				temp1[j]=100;
			}
			if(tempy[j]=="S"){
				temp1[j]=200;
			}
			if(tempy[j]=="W"&&tempx[j]=="W"){
				temp1[j]=300;
			}
			if(tempy[j]=="N"){
				temp1[j]=400;
			}
			if(tempy[j]=="C"){
				temp1[j]=500;
			}
			if(tempy[j]=="F"){
				temp1[j]=600;
			}
			if(tempy[j]=="B"&&tempx[j]=="W"){
				temp1[j]=700;
			}
		}
	}
			
}
