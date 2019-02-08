#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    string name[n];
    string majong[n][17];
    string pair;
    string temp;
    vector <string> majong_sort;
    vector<int> W;
    vector<int> B;
    vector<int> T;
    int ee, ss, ww, nn, rc, gf, wb = 0;
    for (int i = 0; i < n; i++) {
        cin >> name[i];
        for (int j = 0; j < 17; j++) {
            cin >> majong[i][j];
        }
    }
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
        for(int j=0;j<W.size();j++){
        	temp[0] = W[j];
        	temp[1] = 'W';
        	majong_sort.push_back(temp); 
		}
		for(int j=0;j<B.size();j++){
        	temp[0] = B[j];
        	temp[1] = 'B';
        	majong_sort.push_back(temp);
		} 
		for(int j=0;j<T.size();j++){
        	temp[0] = T[j];
        	temp[1] = 'T';
        	majong_sort.push_back(temp);
		}
		for(int j=0;j<nn;j++){
			majong_sort.push_back("NN");
		}
		for(int j=0;j<ss;j++){
			majong_sort.push_back("SS");
		}
		for(int j=0;j<ww;j++){
			majong_sort.push_back("WW");
		}
		for(int j=0;j<ee;j++){
			majong_sort.push_back("EE");
		}
		for(int j=0;j<rc;j++){
			majong_sort.push_back("RC");
		}
		for(int j=0;j<gf;j++){
			majong_sort.push_back("GF");
		}
		for(int j=0;j<wb;j++){
			majong_sort.push_back("WB");
		}
		for(int j=0;j<17;j++){
			cout << majong_sort[j] << " ";
		}
    }
}
