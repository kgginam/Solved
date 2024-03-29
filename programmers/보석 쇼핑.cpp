#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int left = 0;
    int right = 0;
    set<string> s;
    map<string, int> m;
    
    answer.push_back(0);
    answer.push_back(gems.size()-1);

    // 보석의 종류 저장
    for (int i = 0; i < gems.size(); i++) {
        s.insert(gems[i]);
    }

    while (1) {
        if (left >= gems.size()) {
            break;
        }
        // right가 gems 크기보다 크고
        // 모든 종류의 보석을 구매할 수 있는 경우
        if (right >= gems.size()) {
            if (m.size() == s.size()) {
                right = gems.size() - 1;
                // 구매할 수 있는 최소 범위를 구한다.
                while (left <= right) {
                    auto it = m.find(gems[left]);
                    if (it->second > 1) {
                        it->second--;
                        left++;
                    } else {
                        if (right - left < answer[1] - answer[0]) {
                            answer[0] = left;
                            answer[1] = right;
                        }
                        break;
                    }
                }
            }
            break;
        }

        // 모든 종류의 보석을 구매할 수 없는 경우 다음 보석 추가
        if (m.size() < s.size()) {
            if (m.insert({gems[right], 1}).second == false) {
                m[gems[right]] += 1;
            }
            right++;
        } else if (m.size() == s.size()) {
            // 보석을 구매할 수 있는 경우
            // 앞부분의 보석을 제거할 수 있으면 제거
            if (right - left - 1 < answer[1] - answer[0]) {
                answer[0] = left;
                answer[1] = right - 1;
            }
            auto it = m.find(gems[left]);
            if (it->second > 1) {
                it->second--;
            } else {
                m.erase(it);
            }
            left++;
        }
    }
    
    answer[0]++;
    answer[1]++;
    
    return answer;
}