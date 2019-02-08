#include <iostream>
#include <vector>
#define MAX 50
using namespace std;


void add(string a, string b){
    int c[MAX], d[MAX], rst[MAX];

    int j = 0;
    for(int i=a.size()-1;i>-1;i--){
        c[j] = atoi(a[i]);
        j++;
    }
    j = 0;
    for(int i=b.size()-1;i>-1;i--){
        d[j] = atoi(b[i]);
        j++;
    }
    int carry = 0;
    for(int i=0;i<MAX;i++){
        rst[i] = c[i] + b[i] + carry;
        carry = rst[i] / 10;
        rst[i] %= 10;
    }

    for(int i=50;i>-1;i++){
        cout << rst[i];
    }

}
int main(){
    string a, b;
    string result = "";
    cin >> a;
    cin >> b;

    add(a, b);


}
