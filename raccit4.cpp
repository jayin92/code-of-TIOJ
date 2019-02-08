#include <iostream>
#include <algorithm>
#include <string>

int m;

using namespace std;
bool contain(int* arr,int n){
	for(int m=0;m<17;m++){
	if(arr[m]==n) return true;
	else if (arr[m]>n)return false;
	} 
}
int findd(int* arr,int n){
	for(int m=0;m<17;m++){
	if(arr[m]==n) return m;
	else if (arr[m]>n) return 18;
	} 
}
int sum(int *arr){
	int f;
	for(int i;i<17;i++)
	f=f+arr[i];
	return f;
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
			if(temp1[j]>999 && temp1[j]==temp1[j+1]==temp1[j+2]){
				temp1[j]=temp1[j+1]=temp1[j+2]=10000;
				j+=2;
				b=b+3;
			}
		}
		for(int j=0;j<17;j++){
			if(temp1[j]>999&&temp1[j]<10000){
				a=a+1;
			}
		}
		sort (temp1,temp1+17);
		if(a==0){
			for(int j=b;j<17;j++){
				if(contain(temp1,temp1[j]+1))}
			}
		}
		if(a==2&&temp1[15-b]==temp1[16-b]){
			while(sum(temp1)!=150000+temp1[15-b]+temp1[16-b]){
				for(int j=0;j<17-b;j++){
				if(contain(temp1,temp1[j]+1)&&contain(temp1,temp1[j]+2)&&temp1[j]==temp1[j+1]==temp1[j+2]){
					
				}else if(contain(temp1,temp1[j]+1)&&contain(temp1,temp1[j]+2)){
					temp1[j]=temp1[findd(temp,temp1[j]+1)]=temp1[findd(temp,temp1[j]+2)]=10000;
					b=b+3;
				}else if(temp1[j]==temp1[j+1]==temp1[j+2]){
					temp1[j]=temp1[j+1]=temp1[j+2]=10000;
					b=b+3;
				}
					
				}
			}	
		}
			
		
	}
		
	
}
