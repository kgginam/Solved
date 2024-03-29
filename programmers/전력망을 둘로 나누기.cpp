#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void solve(map<int,pair<bool,vector<int>>>& m, int next) {
    // 이미 방문한 송전탑일 경우
    if (m[next].first) {
        return;
    }
    m[next].first = true;
    // 연결된 송전탑 방문
    for (int i = 0; i < m[next].second.size(); i++) {
        solve(m, m[next].second[i]);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    for (int i = 0; i < wires.size(); i++) {
        // 끊을 전선을 제거한 후 "key: 송전탑 번호, value: 방문여부, 연결된 송전탑의 번호 리스트" 형식의 key-value 값으로 저장
        vector<vector<int>> cut(wires);
        cut.erase(cut.begin() + i);
        map<int,pair<bool,vector<int>>> m;
        vector<int> v;
        for (auto& c : cut) {
            v.clear();
            v.push_back(c[1]);
            if(m.insert(make_pair(c[0],make_pair(false, v))).second == false) {
                m[c[0]].second.push_back(c[1]);
            }
            v[0] = c[0];
            if (m.insert(make_pair(c[1],make_pair(false, v))).second == false) {
                m[c[1]].second.push_back(c[0]);
            }
        }
        
        // 1번 송전탑부터 연결된 송전탑 방문
        solve(m, 1);
        
        // solve 함수에서 방문한 송전탑의 개수 구하기
        int count = 0;
        for (auto mm : m) {
            if (mm.second.first) {
                count++;
            }
        }
        int uncount = n - count;
        int tt = abs(count - uncount);
        if (tt < answer) {
            answer = tt;
        }
    }
    if (answer == INT_MAX) {
        answer = 0;
    }
    
    return answer;
}