#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	int self[t][9][4];
	int enemy[t][9][4];
	int fight[t][300][3];
	int n[t];
	int m[t];
	int q[t];
	int self_pos[t][10][3] = {-1};
	int enemy_pos[t][10][3] = {-1};
	int self_death[t] = {0};
	int enemy_death[t] = {0};
	int damage;
	bool self_attack = 1;
	bool combo = 0;
	bool flag = 0;
	char temp;
	// begin of input
	for(int i=0;i<t;i++){
		cin >> n[i] >> m[i] >> q[i];
		for(int j=0;j<n[i];j++){
			cin >> self[i][j][0] >> self[i][j][1] >> self[i][j][2] >> self[i][j][3];
		}
		for(int j=0;j<m[i];j++){
			cin >> enemy[i][j][0] >> enemy[i][j][1] >> enemy[i][j][2] >> enemy[i][j][3];
		}
		for(int j=0;j<q[i]*3;j+=3){
			for(int k=0;k<3;k++){
				scanf("%d %d %c", &fight[i][j+k][0], &fight[i][j+k][1], &temp);
				fight[i][j+k][2] = (int)temp;
			}			
		}
	}
	// let data turn into sort by position
	for(int i=0;i<t;i++){
		for(int j=0;j<n[i];j++){
			int pos = self[i][j][0];
			self_pos[i][pos][0] = self[i][j][0];
			self_pos[i][pos][1] = self[i][j][1];
			self_pos[i][pos][2] = self[i][j][2];
			self_pos[i][pos][3] = self[i][j][3];
		}
		for(int j=0;j<m[i];j++){
			int pos = enemy[i][j][0];
			enemy_pos[i][pos][0] = enemy[i][j][0];
			enemy_pos[i][pos][1] = enemy[i][j][1];
			enemy_pos[i][pos][2] = enemy[i][j][2];
			enemy_pos[i][pos][3] = enemy[i][j][3];		
		}
	}
	// begin of main program
	for(int i=0;i<t;i++){
		for(int j=0;j<q[i]*3;j+=3){
			flag = 1;
			combo = 0;
			if(self_attack){
				self_attack = 0;
				combo = 0;
				if(fight[i][j][1]==fight[i][j+1][1] && fight[i][j+1][1] == fight[i][j+2][1]){
					combo = 1;
				}
				for(int k=0;k<3;k++){					
					if(self_pos[i][fight[i][j+k][0]][0] == -1 || self_pos[i][fight[i][j+k][0]][1] == 0){
						cout << "WHAT!?" << endl;
						k = 3;
						j = q[i]*3;
						flag = 0;
						continue;
					}
					int atk = self_pos[i][fight[i][j+k][0]][2];
					int def = enemy_pos[i][fight[i][j+k][1]][3];
					int health = enemy_pos[i][fight[i][j+k][0]][1];
					if(fight[i][j+k][2] == 'A'){
						if(combo){
							damage = max(floor(floor(atk-def/3)*1.2), (double)0);
							cout <<"damage :"<< damage << endl;
							
						} else {
							damage = max(floor(floor(atk-def/3)), (double)0);						
						}
						if(health > damage){
							enemy_pos[i][fight[i][j+k][0]][1] -= damage;
						} else if(health <= damage && health > 0){
							enemy_pos[i][fight[i][j+k][0]][1] = 0;
							enemy_death[i] ++;
						}	
					} else {
						int col;
						if(1 <= fight[i][j+k][1] && fight[i][j+k][1] <= 3){
							col = 1;
						} else if(4 <= fight[i][j+k][1] && fight[i][j+k][1] <= 6){
							col = 2;
						} else {
							col = 3;
						}
						if(combo){
							combo = 0;
							switch(col){
								case 1:
									for(int l=1;l<4;l++){
										health = enemy_pos[i][l][1];
										def = enemy_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8*1.2), (double)0);
										if(health > damage){
											enemy_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											enemy_pos[i][l][1] = 0;
											enemy_death[i]++;
										}
									}
									break;
								case 2:
									for(int l=4;l<7;l++){
										health = enemy_pos[i][l][1];
										def = enemy_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8*1.2), (double)0);
										if(health > damage){
											enemy_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											enemy_pos[i][l][1] = 0;
											enemy_death[i]++;
										}
									}
									break;
								case 3:
									for(int l=7;l<10;l++){
										health = enemy_pos[i][l][1];
										def = enemy_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8*1.2), (double)0);
										if(health > damage){
											enemy_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											enemy_pos[i][l][1] = 0;
											enemy_death[i]++;
										}
									}
									break;								
							}
						} else {
							switch(col){
								case 1:
									for(int l=1;l<4;l++){
										health = enemy_pos[i][l][1];
										def = enemy_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8), (double)0);
										if(health > damage){
											enemy_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											enemy_pos[i][l][1] = 0;
											enemy_death[i]++;
										}
									}
									break;
								case 2:
									for(int l=4;l<7;l++){
										health = enemy_pos[i][l][1];
										def = enemy_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8), (double)0);
										if(health > damage){
											enemy_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											enemy_pos[i][l][1] = 0;
											enemy_death[i]++;
										}
									}
									break;
								case 3:
									for(int l=7;l<10;l++){
										health = enemy_pos[i][l][1];
										def = enemy_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8), (double)0);
										if(health > damage){
											enemy_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											enemy_pos[i][l][1] = 0;
											enemy_death[i]++;
										}
									}
									break;
								
							}
						}
					}
					
				}
				
			} else {
				self_attack = 1;
				combo = 0;
				if(fight[i][j][1]==fight[i][j+1][1] && fight[i][j+1][1] == fight[i][j+2][1]){
					combo = 1;
				}
				for(int k=0;k<3;k++){
					if(enemy_pos[i][fight[i][j+k][0]][0] == -1 || enemy_pos[i][fight[i][j+k][0]][1] == 0){
						cout << "WHAT!?" << endl;
						cout << j << " " << k << endl; 
						j = q[i]*3;
						k=3;
						flag = 0;
						continue;
					}
					int atk = enemy_pos[i][fight[i][j+k][0]][2];
					int def = self_pos[i][fight[i][j+k][1]][3];
					int health = self_pos[i][fight[i][j+k][0]][1];
					if(fight[i][j+k][2] == 'A'){
						if(combo){
							damage = max(floor(floor(atk-def/3)*1.2), (double)0);
							
						} else {
							damage = max(floor(floor(atk-def/3)), (double)0);						
						}
						if(health > damage){
							self_pos[i][fight[i][j+k][0]][1] -= damage;
						} else if(health <= damage && health > 0){
							self_pos[i][fight[i][j+k][0]][1] = 0;
							self_death[i] ++;
						}	
					} else {
						int col;
						if(1 <= fight[i][j+k][1] && fight[i][j+k][1] <= 3){
							col = 1;
						} else if(4 <= fight[i][j+k][1] && fight[i][j+k][1] <= 6){
							col = 2;
						} else {
							col = 3;
						}
						if(combo){
							combo = 0;
							switch(col){
								case 1:
									for(int l=1;l<4;l++){
										health = self_pos[i][l][1];
										def = self_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8*1.2), (double)0);
										if(health > damage){
											self_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											self_pos[i][l][1] = 0;
											self_death[i]++;
										}
									}
									break;
								case 2:
									for(int l=4;l<7;l++){
										health = self_pos[i][l][1];
										def = self_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8*1.2), (double)0);
										if(health > damage){
											self_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											self_pos[i][l][1] = 0;
											self_death[i]++;
										}
									}
									break;
								case 3:
									for(int l=7;l<10;l++){
										health = self_pos[i][l][1];
										def = self_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8*1.2), (double)0);
										if(health > damage){
											self_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											self_pos[i][l][1] = 0;
											self_death[i]++;
										}
									}
									break;
								
							}
						} else {
							switch(col){
								case 1:
									for(int l=1;l<4;l++){
										health = self_pos[i][l][1];
										def = self_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8), (double)0);
										if(health > damage){
											self_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											self_pos[i][l][1] = 0;
											self_death[i]++;
										}
									}
									break;
								case 2:
									for(int l=4;l<7;l++){
										health = self_pos[i][l][1];
										def = self_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8), (double)0);
										if(health > damage){
											self_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											self_pos[i][l][1] = 0;
											self_death[i]++;
										}
									}
									break;
								case 3:
									for(int l=7;l<10;l++){
										health = self_pos[i][l][1];
										def = self_pos[i][l][3];
										if(def == -1){
											continue;
										}
										damage = max(floor(floor(atk-def/3)*0.8), (double)0);
										if(health > damage){
											self_pos[i][l][1] -= damage;
										} else if(health <= damage && health > 0){
											self_pos[i][l][1] = 0;
											self_death[i]++;
										}
									}
									break;
								
							}
						}
					}
					
				}
			}
		}

		if(flag){
			if(n[i] - self_death[i] > m[i] - enemy_death[i]){
				cout << "Win!" << endl;
			}
			else if(n[i] - self_death[i] == m[i] - enemy_death[i]){
				cout << "Draw!" << endl;
			}
			else{
				cout << "Lose!" << endl;
			}
		}
			
	}
	return 0;
}
