#include <iostream>
#include <string>

using namespace std;

int converttoint(string str, int s, int e){
    int a = str[s];
    int b = str[e];

    return a*10+b;
}

int main(){
    string start, end;
    int start_h, start_m, start_s, end_h, end_m, end_s, result_h, result_m, result_s, start_sec, end_sec, result_sec;

    cin >> start;
    cin >> end;

    start_h = converttoint(start, 0, 1);
    start_m = converttoint(start, 3, 4);
    start_s = converttoint(start, 6, 7);

    end_h = converttoint(end, 0, 1);
    end_m = converttoint(end, 3, 4);
    end_s = converttoint(end, 6, 7);

    start_sec = start_s + start_m * 60 + start_h * 3600;
    end_sec = end_s + end_m * 60 + end_h * 3600;

    if(end_sec < start_sec){
        end_sec += 24*3600;
    }
    result_sec = end_sec - start_sec;
    result_h = result_sec / 3600;
    result_sec %= 3600;
    result_m = result_sec / 60;
    result_sec %= 60;
    result_s = result_sec;
    char buffer[20];
    sprintf(buffer, "%02d:%02d:%02d", result_h, result_m, result_s);
    puts(buffer);
    //cout << stringformat(result_h, result_m, result_s) << endl;
}


