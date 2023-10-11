#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 몸무게가 낮은 순으로 정렬
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;
    for(;;) {
        if (start > end) {
            break;
        }
        // 몸무게가 높은 사람부터 배에 태운다
        // 몸무게가 낮은 사람이 같이 탈 수 있으면 같이 처리
        if (people[end] + people[start] <= limit) {
            answer++;
            start++;
            end--;
        } else {
            answer++;
            end--;
        }
    }
    
    
    return answer;
}