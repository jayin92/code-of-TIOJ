/*
麻將牌包含了萬子 (W)、餅子 (B)、條子 (T) 及字牌等四種花色。
其中萬子中有一萬(1W)到九萬(9W)、餅子有一餅(1B) 到九餅(9B)、
條子有一條(1T) 到九條(9T)、而字牌則有東風(EE)、南風(SS)、西風(WW)、北風(NN)、紅中(RC)、青發(GF)、白板(WB)。
每種牌各有四張。
    台灣麻將胡牌的條件就是要將手中的牌湊成五組「順子」或「刻子」，再加上一對
「將」才能夠「胡牌」。「順子」是由三張連續數字的相同花色牌所組成，例如：一萬、 二萬、三萬，「刻子」則是由三張同樣的牌組成，
例如：一筒、一筒、一筒，而「將」 則是由兩張一樣的牌所組成，例如：紅中、紅中。特別注意字牌沒有數字，所以不能用字牌組成「順子」。
*/

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int *checkpair(vector<int> vec) {
    int n = 0;
    int pairs = 0;
    int zhan = 0;

    if (vec.size() == 0) {
        static int result[2] = {0, 0};
        return result;
    }
    while (n <= vec.size()) {
        if ((vec[n] == vec[n + 1] && vec[n + 1] == vec[n + 2]) || (vec[n] == vec[n + 1] - 1 && vec[n + 1] - 1 == vec[n + 2] - 2)) {
            pairs++;
            n += 3;
        } else if (vec[n] == vec[n + 1]) {
            zhan++;
            n += 2;
        } else {
            n++;
        }
    }
    static int result[2] = {pairs, zhan};
    return result;
}
int main() {
    int n;
    cin >> n;
    string name[n];
    string majong[n][17];
    string pair;
    vector<int> W;
    vector<int> B;
    vector<int> T;
    int ee, ss, ww, nn, rc, gf, wb = 0;
    int *w_pair, *b_pair, *t_pair;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        for (int j = 0; j < 17; j++) {
            cin >> majong[i][j];
        }
    }
    // end of input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 17; j++) {
            if (majong[i][j][0] < 59) {
                switch (majong[i][j][1]) {
                    case 'W':
                        W.push_back(majong[i][j][0]);
                        break;
                    case 'B':
                        B.push_back(majong[i][j][0]);
                        break;
                    case 'T':
                        T.push_back(majong[i][j][0]);
                        break;
                }
            } else if (majong[i][j][0] == majong[i][j][1]) {
                switch (majong[i][j][1]) {
                    case 'N':
                        nn++;
                        break;
                    case 'W':
                        ww++;
                        break;
                    case 'S':
                        ss++;
                        break;
                    case 'E':
                        ee++;
                        break;
                }
            } else {
                switch (majong[i][j][1]) {
                    case 'C':
                        rc++;
                        break;
                    case 'F':
                        gf++;
                        break;
                    case 'B':
                        wb++;
                        break;
                }
            }
        }
        sort(W.begin(), W.end());
        sort(B.begin(), B.end());
        sort(T.begin(), T.end());
        w_pair = checkpair(W);
        b_pair = checkpair(B);
        t_pair = checkpair(T);
        total_pair = *(w_pair) + *(t_pair) + *(b_pair);
		total_zhan = *(w_pair+1) + *(t_pair+1) + *(b_pair+1);
        cout << *(w_pair + 1) << endl;
        
        if (total_zhan > 1) {
            cout << "Nothing happened." << endl;
            continue;
        } else if(nn==0||ww==0||ss==0||ee==0||rc==0||gf==0||wb==0){
        	cout << "Nothing happened." << endl;
        	continue;
		} else if(total_pair + )
        
    }
}
