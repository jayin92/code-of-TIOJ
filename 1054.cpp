#include <iostream>

using namespace std;

int main(){
    string today;
    int n;
    int day;
    string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cin >> today;
    cin >> n;

    for(int i=0;i<7;i++){
        if(week[i] == today){
           day = i;
        }
    }

    day += n;
    day %= 7;

    cout << week[day] << endl;
}
