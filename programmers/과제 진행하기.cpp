#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calcTime(string time) {
    int n = 0;
    
    n = stoi(time.substr(0,2)) * 60;
    n += stoi(time.substr(3));
    
    return n;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string,pair<int,int>>> q;
    
    sort(plans.begin(), plans.end(), [](vector<string> first, vector<string> second) -> bool {
        int ft = calcTime(first[1]);
        int st = calcTime(second[1]);
        if (ft > st) {
            return false;
        }
        return true;
    });
    
    pair<string, pair<int, int>> now;
    
    now.first = plans[0][0];
    now.second.first = calcTime(plans[0][1]);
    now.second.second = stoi(plans[0][2]);
    int t;
    
    for (int i = 1; i < plans.size(); i++) {
        t = calcTime(plans[i][1]) ;
        if (now.second.first + now.second.second == t) {
            answer.push_back(now.first);
        } else if (now.second.first + now.second.second < t) {
            answer.push_back(now.first);
            if (!q.empty()) {
                for (;;) {
                    if (q.empty())
                        break;
                    int j = q.size()-1;
                    now.first = q[j].first;
                    now.second.first = now.second.first + now.second.second;
                    now.second.second = q[j].second.second;
                    q.erase(q.begin() + j);
                    
                    if (now.second.first + now.second.second == t) {
                        answer.push_back(now.first);
                    } else if (now.second.first + now.second.second < t) {
                        answer.push_back(now.first);
                        continue;
                    } else {
                        q.push_back(make_pair(now.first, make_pair(now.second.first, now.second.second - (t - now.second.first))));
                        break;
                    }
                }
            }
        } else {
            q.push_back(make_pair(now.first, make_pair(now.second.first, now.second.second - (t - now.second.first))));
        }
        now.first = plans[i][0];
        now.second.first = t;
        now.second.second = stoi(plans[i][2]);
    }
    
    answer.push_back(now.first);
    
    for (int i = q.size() - 1; i >= 0; i--) {
        answer.push_back(q[i].first);
    }
    
    return answer;
}