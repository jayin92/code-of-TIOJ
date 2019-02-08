#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <typeinfo>
#define MAX 50;
using namespace std;

vector<int> string_to_arr(string a){

    int len = a.size();
	
    vector<int> rst;
    rst.clear();
    for(int i=len-1;i>=0;i--){
        rst.push_back(a[i]-48);
    }
    for(int i=0;i<len;i++){
    	cout << rst[i] << " ";
	}
	return rst;
}

void add(string a, string b){
    int carry = 0;
    int temp;
    int len_a = a.size();
    int len_b = b.size();
    vector<int> int_a;
    vector<int> int_b;
    int_a.clear();
    int_b.clear();
    int_a = string_to_arr(a);
    int_b = string_to_arr(b);
    int len_rst = max(len_a, len_b);
    
    vector<int> rst;  
	cout << endl;  
    for(int i=0;i<len_rst+1;i++){
       int temp = int_a[i] + int_b[i] + carry;
       int carry = temp / 10;
       temp %= 10;
       rst.push_back(temp);
    }

    reverse(rst.begin(), rst.end());

    for(int i=0;i<rst.size();i++){
        cout << rst[i];
    }


}

void minus(string a, string b){

}

void multiply(string a, string b){

}

void substract(string a, string b){

}

int main(){
    string a = "10";
    string b = "99";

    add(a, b);

    return 0;
}
