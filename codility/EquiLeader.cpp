#include <vector>
#include <map>
//leader => more than half of the element
//equi leader => 0 <= S < N - 1; 
//count of equi leader

int solution(vector<int> &A) {
    std::vector<std::pair<int,int>> v;
    std::map<int, int> m;
    int leader = -1000000001;
    int answer = 0;
    int count = 0;
    int leaderCount = 0;

    for (int i = 0; i < A.size(); i++) {
        if (!m.insert({m[i], i}).second) {
            m[A[i]] += 1;
        }
    }

    for (auto tmp : m) {
        if (tmp.second > A.size() / 2) {
            leader = tmp.first;
            break;
        }
    }
    if (leader == -1000000001)
        return 0;
    
    for (int i = 0; i < A.size(); i++) {
        count++;
        if (A[i] == leader)
            leaderCount++;
        v.push_back(std::make_pair(count, leaderCount));
    }

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].first / 2 < v[i].second && (v[v.size()-1].first - v[i].first) / 2  < v[v.size()-1].second - v[i].second)
            answer++;
    }
    return answer;
}
