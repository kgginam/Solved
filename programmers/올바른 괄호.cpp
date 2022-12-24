#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int push = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            push = push + 1;
        } else {
            if (push == 0) {
                return false;
            }
            push = push - 1;
        }
    }
    
    if (push != 0) {
        return false;
    }

    return answer;
}