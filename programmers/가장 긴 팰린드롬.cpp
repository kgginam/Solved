#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer = 0;
    int max = 0;
    int c = 0;
    int x;
    int len = s.length();
    
    for (int i = 1; i < len - 1; i++) {
        c = 0;
        x = 0;
        for (;;) {
            c++;
            if (i - c < 0 || i + c >= len) {
                break;
            }
            if (s.at(i - c) == s.at(i + c)) {
                x++;
            } else {
                break;
            }
        }
        if (answer < (x * 2) + 1) {
            answer = (x * 2) + 1;
        }
        
        c = 0;
        x = 0;
        for (;;) {
            c++;
            if (i - c + 1 < 0 || i + c >= len) {
                break;
            }
            if (s.at(i - c + 1) == s.at(i + c)) {
                x++;
            } else {
                break;
            }
        }
        if (answer < x * 2) {
            answer = x * 2;
        }
    }

    if (answer == 0) {
        answer = 1;
    }
    if (answer > len) {
        answer = len;
    }
    return answer;
}