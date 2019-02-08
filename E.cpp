#include <iostream>
#include <cmath>
using namespace std;
int find(int pos, int arr[], int n){
	int index;
	for(int i=0;i<n;i++){
		if(arr[i][0] == pos){
			index = i;
		}
	}
	return index;
}
int main(){
	int t, p, h, a, d;
	cin >> t;
	int self[t][9][4];
	int enemy[t][9][4];
	int fight[t][300000][3];
	int n[t];
	int m[t];
	int q[t];
	int self_death[t] = 0;
	int enemy_death[t] = 0;
	bool combo = 0;
	for(int i=0;i<t;i++){
		cin >> n[i] >> m[i] >> q[i];
		for(int j=0;j<n[i];j++){
			cin >> self[i][j][0] >> self[i][j][1] >> self[i][j][2] >> self[i][j][3];
		}
		for(int j=0;j<m[i];j++){
			cin >> enemy[i][j][0] >> enemy[i][j][1] >> enemy[i][j][2] >> enemy[i][j][3];
		}
		for(int j=0;j<q[i]*3;j++){
			cin >> fight[i][j][0] >> fight[i][j][1] >> fight[i][j][2];
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<q[i]*3;j+=3){
			combo = 0;
			if(self_attack){
				if(fight[i][j][1]==fight[i][j+1][1] && fight[i][j+1][1] == fight[i][j+2][1]){
					combo = 1;
				}
				for(int k=0;k<2;k++){
					int attacker_index = find(fight[i][j+k][0], self[i], n[i]);
					int defense_index = find(fight[i][j+k][1], enemy[i], m[i]);
					int atk = self[i][attacker_index][2];
					int def = enemy[i][defense_index][3];
					int defense_health = enemy[i][defense_index][1];
					if(fight[i][j+k][2] == 'A'){
						if(combo){
							int damage = max(floor(floor(atk-def/3)*1.2)), 0)
							if(defense_health > damage){
								enemy[i][defense_index][1] -= damage;
							} else if(defense_health == damage){
								enemy[i][defense_index][1] = 0;
								enemy_death[i] ++; 
							} else {
								cout << "WHAT!?" << endl;
								k = 3;
								q = q[i]*3;
							}
						} else {
							int damage = max(floor(floor(atk-def/3))), 0)
							if(defense_health > damage){
								enemy[i][defense_index][1] -= damage;
							} else if(defense_health == damage){
								enemy[i][defense_index][1] = 0;
								enemy_death[i] ++; 
							} else {
								cout << "WHAT!?" << endl;
								k = 3;
								q = q[i]*3;
							}
						}
					} else {
						if(combo){
							int damage = max(floor(floor(atk-def/3)*1.2*0.8)), 0);
							if(1 <= fight[i][j+k][1] && fight[i][j+k][1] <= 3){
								for(int i=1;i<3;i++){
									int pos = find()
								}
							}
						} else {
							
						}
						
					}
				}
				self_attack = 0;
			} else {
				
			}
		}
	}
}
