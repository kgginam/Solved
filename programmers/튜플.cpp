#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = "";
    vector<vector<int>> tuple;
    vector<int> v;
    string num = "";
    set<int> co;
    // 집합 추출
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '{') {
            continue;
        }
        // }인 경우 현재까지 추가한 집합을 배열에 추가
        else if (s.at(i) == '}') {
            // }}인 경우 미처리
            if(s.at(i-1) == '}') {
                continue;
            }
            v.push_back(stoi(num));
            num = "";
            tuple.push_back(v);
            v.clear();
        }
        // ,인 경우 집합에 수 추가
        else if (s.at(i) ==',') {
            // },인 경우 미처리
            if (s.at(i-1) == '}') {
                continue;
            }
            v.push_back(stoi(num));
            num = "";
        } else {
            num = num + s.at(i);
        }
    }
    
    // 집합의 크기가 작은순으로 정렬
    sort(tuple.begin(),
         tuple.end(), 
         [](const vector<int> &first, const vector<int> &second) -> bool {
            if (first.size() >= second.size()) {
                return false;
            } else {
                return true;
            }
    });
    
    // 집합들을 순회하며 set에 값을 삽입해보고 삽입이 될 경우 튜플에 추가
    for (int i = 0; i < tuple.size(); i++) {
        for (int j = 0; j < tuple[i].size(); j++) {
            if (co.insert(tuple[i][j]).second == true) {
                answer.push_back(tuple[i][j]);
                break;
            }
        }
    }
    
    return answer;
}