#include <string>
#include <vector>
#include <map>

using namespace std;

bool solve(vector<string> &want, vector<int> &number, map<string ,int> &m) {
    for (int i = 0; i < want.size(); i++) {
        auto it = m.find(want[i]);
        if (it == m.end()) {
            return false;
        }
        if (it->second != number[i]) {
            return false;
        }
    }
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for (int i = 0; i < 10; i++) {
        if (m.insert({discount[i], 1}).second == false) {
            m[discount[i]]+=1;
        }
    }
    if (solve(want, number, m)) {
        answer++;
    }
    
    for (int i = 10; i < discount.size(); i++) {
        if (m.insert({discount[i], 1}).second == false) {
            m[discount[i]]+=1;
        }
        m[discount[i-10]]-=1;
        if (solve(want, number, m)) {
            answer++;
        }
    }
    
    return answer;
}