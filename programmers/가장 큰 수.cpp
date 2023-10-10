#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    stringstream sss;
    
    sort(numbers.begin(), numbers.end(), [](const int& first, const int& second){
        string f = to_string(first);
        string s = to_string(second);
        
        if (stoll(f+s) > stoll(s+f)) {
            return true;
        }
        return false;
    });
        
    for (int i = 0; i < numbers.size(); i++) {
        sss << numbers[i];
    }
    
    answer = sss.str();
    int count = 0;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '0') {
            count++;
        } else {
            break;
        }
    }
    if (count == answer.size()) {
        answer = "0";
    } else {
        answer = answer.substr(count,answer.size());
    }
    return answer;
}