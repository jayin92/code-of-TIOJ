#include <iostream>
#include <string>

using namespace std;
// ASCII a=97 z=122
void brust(string temp, int len, int holenum) {
    bool haveg, confirm = 0;
    char hole[7] = {'a', 'b', 'd', 'e', 'o', 'p', 'q'};
    int time;
    while (1) {
        temp[len - 1]++;
        time = 0;
        confirm = 0;
        haveg = 0;
        for (int j = len - 1; j >= 0; j--) {
            if (temp[j] > 122) {
                if (j > 0) {
                    temp[j] = 'a';
                    temp[j - 1]++;
                } else {
                    confirm = 1;
                }
            }
        }
        for (int h = 0; h < len; h++) {
            for (int k = 0; k < 7; k++) {
                if (temp[h] == 'g') {
                    haveg = 1;
                    h = len;
                    k = 8;
                }
                if (time > holenum) {
                    h = len;
                    k = 8;
                } else if (temp[h] == hole[k]) {
                    time++;
                }
            }
        }
        if (confirm) {
            cout << "-1" << endl;
            break;
        } else if (time == holenum && haveg == 0) {
            cout << temp << endl;
            break;
        }
    }
}

int main() {
    cin.tie(NULL);
    char hole[7] = {'a', 'b', 'd', 'e', 'o', 'p', 'q'};
    int n, len, holenum;
    cin >> n;
    string str[n];
    string temp;
    char lastdi;
    int time = 0;
    int data[n][2];
    bool confirm, haveg, flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1];
        cin >> str[i];
    }
    for (int i = 0; i < n; i++) {
        temp = str[i];
        len = data[i][0];
        holenum = data[i][1];
        lastdi = temp[len - 1];
        flag = 0;
        for (int j = 0; j < 7; j++) {
            if (lastdi == hole[j]) {
                if (lastdi != 'q') {
                    temp[len - 1] = hole[j + 1];
                    j = 7;
                    cout << temp << endl;
                    flag = 1;
                } else {
                    brust(temp, len, holenum);
                    flag = 1;
                }
            }
        }
        if (flag) {
            continue;
        }
        if (temp[len - 1] != 'z') {
            while (1) {
                temp[len - 1]++;
                for (int j = 0; j < 7; j++) {
                    if (temp[len - 1] == hole[j]) {
                        flag = 1;
                    }
                }
                if (flag == 0 && temp[len - 1] != 'g') {
                    cout << temp << endl;
                    break;
                }
                flag = 0;
            }
        } else {
            brust(temp, len, holenum);
            continue;
        }
    }
}
