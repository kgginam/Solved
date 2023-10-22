#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> vp;
    vector<int> v(N+1, 0);

    sort(stages.begin(), stages.end());
    // 스테이지 별 도달한 사람 수 계산
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] >= N+1) {
            break;
        }
        v[stages[i]] += 1;
    }

    // 스테이지 별 실패율 계산
    int sum = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == 0) {
            vp.push_back(make_pair(i, 0));
        } else {
            vp.push_back(make_pair(i, (double)v[i] / (stages.size() - sum)));
            sum += v[i];
        }
    }

    // 실패율을 내림차 순으로 정렬
    sort(vp.begin(), vp.end(), [](auto& first, auto& second) -> bool {
        if (first.second < second.second) {
            return false;
        }
        if (first.second == second.second) {
            if (first.first > second.first) {
                return false;
            }
        }
        return true;
    });

    for (int i = 0; i < vp.size(); i++) {
        answer.push_back(vp[i].first);
    }

    return answer;
}