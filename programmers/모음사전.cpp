#include <string>
#include <vector>

using namespace std;

bool isComp(const vector<long long>& ll, const vector<long long>& wordll) {
    for (int i = 0; i < 5; i++) {
        if (ll[i] != wordll[i]) {
            return false;
        }
    }
    return true;
}

void llplus(vector <long long> &ll) {
    bool isAdded = false;
    for (int i = 0; i < 5; i++) {
        if (ll[i] == 0) {
            ll[i]+=1;
            isAdded = true;
            break;
        }
    }
    if (!isAdded) {
        ll[4] +=1;
    }
    if (ll[4] > 5) {
        ll[4] = 0;
        ll[3] += 1;
    }
    if (ll[3] > 5) {
        ll[3] = 0;
        ll[2] += 1;
    }
    if (ll[2] > 5) {
        ll[2] = 0;
        ll[1] += 1;
    }
    if (ll[1] > 5) {
        ll[1] = 0;
        ll[0] += 1;
    }
}

int solution(string word) {
    int answer = 0;
    vector<long long> ll;
    vector<long long> wordll;
    for (int i = 0; i < 5; i++) {
        ll.push_back(0);
        wordll.push_back(0);
    }
    
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'A') {
            wordll[i] = 1;
        }
        if (word[i] == 'E') {
            wordll[i] = 2;
        }
        if (word[i] == 'I') {
            wordll[i] = 3;
        }
        if (word[i] == 'O') {
            wordll[i] = 4;
        }
        if (word[i] == 'U') {
            wordll[i] = 5;
        }
    }
    
    
    for (;;) {
        answer++;
        llplus(ll);
        if (isComp(ll, wordll)) {
            break;
        }
    }
    
    return answer;
}