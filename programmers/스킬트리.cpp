#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool b;
    int now;
    map<string, int> m;
    
    for (int i = 0; i < skill.size(); i++) {
        m.insert({skill.substr(i, 1), i + 1});
    }
    
    for (int i = 0; i < skill_trees.size(); i++) {
        now = 1;
        b = false;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            if (now > skill.size()) {
                break;
            }
            auto tmp = m.find(skill_trees[i].substr(j,1));
            if (tmp != m.end()) {
                if (now != tmp->second) {
                    b = true;
                    break;
                }
                now++;
            }
        }
        if (!b) {
            answer++;
        }
    }
    
    
    return answer;
}