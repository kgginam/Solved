#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++) {
        long long x = i / n;
        long long y = i % n;
        int tmp = max(y, x) + 1;
        answer.push_back(tmp);
    }
    
    return answer;
}