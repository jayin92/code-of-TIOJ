#include <iostream>
#include <cmath>


using namespace std;

int main(){
    string a,b;
    int c,d;
    cin >> a >> b;
    c = stoi(a);
    d = stoi(b);
    if(c>d){
        cout << a;
        return 0;
    } else if(c<d) {
        cout << b;
        return 0;
    } else {
        for(int i=0;;i++){
            if(a[i] > b[i]){
                cout << a;
                return 0;
            }
            if(a[i] < b[i]){
                cout << b;
                return 0;
            }
        }

    }
}

