#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    multiset<int, greater<int>> ms;
    // 큰 수로 정렬되는 mulitset 초기화
    for (int i = 0; i < works.size(); i++) {
        ms.insert(works[i]);
    }
    
    // 야근까지의 남은 시간 동안
    while(n > 0) {
        auto tmp = ms.begin();  // 가장 큰 작업의 iterator 반환
        auto num = *tmp;        // 가장 큰 작업의 작업량
        // 현재 남은 작업량이 0보다 큰 경우
        // 작업량 - 1
        if (num > 0) {
            ms.erase(tmp);
            ms.insert(num-1);
        }
        n--;
    }
    
    // 야근 피로도 구하기
    for (auto it = ms.begin(); it != ms.end(); it++) {
        answer += (*it) * (*it);
    }
    
    return answer;
}