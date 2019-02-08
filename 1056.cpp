#include <iostream>
#include <cmath>
using namespace std;


char end(char table[3][3], int o_count, int x_count){
	int line = 0;
	char result;
	for(int i=0;i<3;i++){
		if((table[i][0] == table[i][1] && table[i][1] == table[i][2]) && table[i][2] != '.'){
			result = table[i][0];
			line ++;
		}
		if((table[0][i] == table[1][i] && table[1][i] == table[2][i]) && table[2][i] != '.'){
			result = table[0][i];
			line ++;
		}
	}	

	
	if(((table[2][0] == table[1][1] && table[1][1] == table[0][2]) || (table[0][0] == table[1][1] && table[1][1] == table[2][2])) && table[1][1] != '.'){
		result = table[2][0];
		line ++; 
	}
	if(line > 1 && o_count != 5){
		cout << "test" << endl;
		return 'v';
		
	} else if(line == 1 || (line == 2 && o_count % 2 == 1) ){
		return result;
	}
	return '.';
}

int main(){
    char table[3][3];
    int o_count = 0;
    int x_count = 0;

    

    scanf("%c%c%c\n%c%c%c\n%c%c%c", &table[0][0], &table[0][1], &table[0][2], &table[1][0], &table[1][1], &table[1][2], &table[2][0], &table[2][1], &table[2][2]);

    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            switch(table[i][j]){
                case 'O':
                    o_count ++;
                    break;
                case 'X':
                    x_count ++;
                    break;
                case '.':
                    break;
                default:
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
            }
        }
    }
    if(end(table, o_count, x_count) == 'v'){
    	cout << "IMPOSSIBLE" << endl;
    	return 0;
	}
    else if((x_count - o_count == 0 && end(table, o_count, x_count) == 'X') || (o_count - x_count == 1 && end(table, o_count, x_count) == 'O')){
    	cout << "POSSIBLE" << endl;
    	return 0;
	} else if(end(table, o_count, x_count) == '.' && (1>=o_count - x_count && o_count - x_count >= 0)){
		cout << "POSSIBLE" << endl;
    	return 0;
	}
    cout << "IMPOSSIBLE" << endl;
    return 0;

}
