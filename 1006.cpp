#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compare(string a, string b){
    if(a.size() > b.size()){
        return "a";
    }
    if(a.size() < b.size()){
        return "b";
    }

    for(int i=a.size()-1;i>=0;i++){
        if(a[i] > b[i]){
            return "a";
        } else if(a[i]<b[i]){
            return "b";
        }

    }

    return "1";
}

void add(string a, string b){
    int MAX = max(a.size(), b.size())+1;
    
    int c[MAX] = {0};
    int d[MAX] = {0};
    int rst[MAX] = {0};

    int j = 0;
    for(int i=a.size()-1;i>-1;i--){
        c[j] += (int)a[i] - (int)'0';
        j++;
    }
    j = 0;
    for(int i=b.size()-1;i>-1;i--){
        d[j] += (int)b[i] - (int)'0';
        j++;
    }
    int carry = 0;
    for(int i=0;i<MAX;i++){
        rst[i] += c[i] + d[i] + carry;
        carry = rst[i] / 10;
        rst[i] %= 10;
    }
    if(rst[MAX-1] != 0){
        cout << rst[MAX-1];
    }
    for(int i=MAX-2;i>-1;i--){
        cout << rst[i];
    }
    cout << endl;
}

void minus1(string a, string b){
    string c, d;
    if(compare(a, b) == "1"){
        cout << "0" << endl;
    } else {
        if(compare(a, b) == "a"){
            c = a;
            d = b;
        } else {
            c = b;
            d = a;
        }
    }

    int MAX = c.size();
    int e[MAX] = {0};
    int f[MAX] = {0};
    int rst[MAX] = {0};
    int j = 0;
    for(int i=c.size()-1;i>=0;i--){
        e[j] += (int)c[i] - (int)'0';
        j++;
    }
    j = 0;
    for(int i=d.size()-1;i>=0;i--){
        f[j] += (int)d[i] - (int)'0';
        j++;
    }

    for(int i=0;i<MAX;i++){
        if(e[i] < f[i] && e[i+1] > 0){
            rst[i] += (10 + e[i] - f[i]);
            e[i+1] -= 1;
        } else if(e[i] < f[i] && e[i+1] == 0){
            for(int j=i+2;j<MAX;j++){
                if(e[j] > 0){
                    e[j] -= 1;
                    for(int k=i+1;k<=j-1;k++){
                        e[k] += 9;
                    }
                    break;
                }
            }
            rst[i] += (10 + e[i] - f[i]);
        } else {
            rst[i] += (e[i] - f[i]);
        }
    }
    bool flag = 0;
    for(int i=MAX-1;i>=0;i--){
        if(flag){
            cout << rst[i];
        }
        if(rst[i] != 0 && flag == 0){
            cout << rst[i];
            flag = 1;
        }       
    }
    cout << endl;

}


int main(){
    string a, b;
    string result = "";
    cin >> a;
    cin >> b;

    add(a, b);
    minus1(a, b);


}
