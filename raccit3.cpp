#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

bool contain(int* arr,int n){
	for(int i=0;arr[i]<=n;i++){}
	if(arr[i]==n) return true;
	return false;
}
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
	char W = 'W' ;
	char E = 'E' ;
	char S = 'S' ;
	char F = 'F' ;
	char T = 'T' ;
	char C = 'C' ;
	char B = 'B' ;
	char N = 'N' ;
	for(int i=0;i<n;i++){
		cin>>name[i];
		for(int j=0;j<17;j++){
			scanf("	%c	%c", &max[i][j], &may[i][j]);
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
			if( tempy[j]== 'W' && tempx[j]!= 'W' ){
				temp1[j]=tempx[j];
			}
			if(tempy[j]=='T'){
				temp1[j]=tempx[j]+ 20;
			}
			if(tempy[j]=='B' && tempx[j]!='W'){
				temp1[j]=tempx[j]+40;
			}
			if(tempy[j]=='E'){
				temp1[j]=1000;
			}
			if(tempy[j]=='S'){
				temp1[j]=2000;
			}
			if(tempy[j]=='W'&&tempx[j]=='W'){
				temp1[j]=3000;
			}
			if(tempy[j]=='N'){
				temp1[j]=4000;
			}
			if(tempy[j]=='C'){
				temp1[j]=5000;
			}
			if(tempy[j]=='F'){
				temp1[j]=6000;
			}
			if(tempy[j]=='B'&&tempx[j]=='W'){
				temp1[j]=7000;
			}
		}
		sort (temp1,temp1+17);
		for(int j=0;j<15;j++){
			if(temp1[j]>999 && tempi[j]==temp1[j+1]==temp1[j+2]){
				temp1[j]=temp1[j+1]=temp1[j+2]=0;
				j+=2;
			}
		}
		for(int j=0;j<17;j++){
			if(temp1[j]>999){
				a=a+1;
			}
		}
		sort (temp1,temp1+17);
		if(a==0){
			
		}
		if(a==2&&temp1[15]==temp1[16]){
			for(int j=0;j<15;j++){
				if(temp1[j]>0&&temp1[j]==temp1[j+1]&&temp1[j+1]==temp1[j+2])
					temp1[j]=temp1[j+1]=temp1[j+2]=0;
					j+=2;
			}
			sort (temp1,temp1+17);
			for(int j=0;j<15;j++){
				if(temp1[j]>0&&temp1[j]+1==temp1[j+1]&&temp1[j+1]+1==temp1[j+2]){
					temp1[j]=temp1[j+1]=temp1[j+2]=0;
					j+=2;
				}
			}
			for(int j=0;j<12;j++){
				if(temp1[j]>0&&temp1[j]==temp1[j+1]&&temp1[j+1]+1==temp1[j+2]&&temp1[j+2]==temp1[j+3]&&temp1[j+3]+1==temp1[j+4]&&temp1[j+4]==temp1[j+5]){
					temp1[j]=temp1[j+1]=temp1[j+2]=temp1[j+3]=temp1[j+4]=temp1[j+5]=0;
					j=j+5;
				}
			}
		}
	}
		
	
}
