#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

int getBonus(char c) {
    if (c == 'S')
        return 1;
    if (c == 'D')
        return 2;
    return 3;
}

int getOption(char c) {
    if (c == '*')
        return 2;
    else 
        return -1;
}

int solution(string dartResult) {
    int answer = 0;
    
    int i = 0;
    
    int firstS = stoi(dartResult.substr(i++, 1));
    if (isdigit(dartResult.at(i))) {
        firstS = 10;
        i++;
    }
    int firstB = getBonus(dartResult.at(i++));
    int firstO = 1;
    if (!isdigit(dartResult.at(i))) {
        firstO = getOption(dartResult.at(i++));
    }
    int secondS = stoi(dartResult.substr(i++, 1));
    if (isdigit(dartResult.at(i))) {
        secondS = 10;
        i++;
    }
    int secondB = getBonus(dartResult.at(i++));
    int secondO = 1;
    if (!isdigit(dartResult.at(i))) {
        secondO = getOption(dartResult.at(i++));
        if (secondO == 2) {
            firstO *= 2;
        }
    }
    int thirdS = stoi(dartResult.substr(i++, 1));
    if (isdigit(dartResult.at(i))) {
        thirdS = 10;
        i++;
    }
    int thirdB = getBonus(dartResult.at(i++));
    int thirdO = 1;
    if (i < dartResult.size()) {
        thirdO = getOption(dartResult.at(i));
        if (thirdO == 2) {
            secondO *= 2;
        }
    }
    int tmp = firstS;
    for (int i = 1; i < firstB; i++) {
        tmp *= firstS;
    }
    tmp *= firstO;
    answer += tmp;
    tmp = secondS;
    for (int i = 1; i < secondB; i++) {
        tmp *= secondS;
    }
    tmp *= secondO;
    answer += tmp;
    
    tmp = thirdS;
    for (int i = 1; i < thirdB; i++) {
        tmp *= thirdS;
    }
    tmp *= thirdO;
    answer += tmp;
    
    return answer;
}