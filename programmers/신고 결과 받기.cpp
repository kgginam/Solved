#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

pair<string, string> getPairString(string s) {
    pair<string, string> result;
    int index;
    
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') {
            index = i;
            break;
        }
    }
    
    result.first = s.substr(0, index);
    result.second = s.substr(index+1);
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> tmps;
    map<string, vector<string>> m;
    map<string, int> mm;
    set<string> s;
    for (int i = 0; i < id_list.size(); i++) {
        m.insert({id_list[i], vector<string>()});
        mm.insert({id_list[i], 0});
    }
    
    for (int i = 0; i < report.size(); i++) {
        s.insert(report[i]);
    }
    
    for (auto tmp : s) {
        
        auto p = getPairString(tmp);
        
        m[p.second].push_back(p.first);
    }
    
    for (auto tmp : m) {
        if (tmp.second.size() >= k) {
            for (int i = 0; i < tmp.second.size(); i++) {
                mm[tmp.second[i]]++;
            }
        }
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(mm[id_list[i]]);
    }
    return answer;
}