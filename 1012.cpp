#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int m, n, temp;
    queue<int> train;
    stack<int> station;
    stack<int> repairment;
    cin >> n >> m;
    queue<int> result;

    for(int i=0;i<n;i++){
        cin >> temp;
        result.push(temp);
    }

    for(int i=0;i<n;i++){
        queue.pop(i+1);
    }

    while(1){
        while(result.front() != train.front() && !train.empty()){
            if(repairment.top() == result.front()){
                repairment.pop();
                result.pop();
                break;
            }

            station.push(train.front());
            train.pop();
        }
        result.pop();
        station.pop();
        if(result.size() == 0){
            cout << "yes" << endl;
            break;
        }
        else if(train.size == 0){
            cout << "no" << endl;
        }
    }

}
