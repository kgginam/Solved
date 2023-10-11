#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    set<int> s;
    set<int> losts;
    for (int i = 0; i < reserve.size(); i++) {
        s.insert(reserve[i]);
    }
    for (int i = 0; i < lost.size(); i++) {
        if (s.find(lost[i]) != s.end()) {
            s.erase(lost[i]);
        } else {
            losts.insert(lost[i]);
        }
    }
    
    answer += n;
    answer -= losts.size();
    for (auto ls : losts) {
        auto it = s.find(ls-1);
        if (it != s.end()) {
            s.erase(*it);
            answer++;
        } else {
            it = s.find(ls+1);
            if (it != s.end()) {
                s.erase(*it);
                answer++;
            }
        }
    }
    
    if (answer > n) {
        answer = n;
    }
    return answer;
}