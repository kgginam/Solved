#include <string>
#include <algorithm>
#include <cctype>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> s;
    multiset<string> s2;
    int u = 0, n = 0;
    
    // 모든 알파벳을 소문자로 변경
    std::transform(str1.begin(), str1.end(), str1.begin(),
    [](unsigned char c){ return std::tolower(c); });
    
    std::transform(str2.begin(), str2.end(), str2.begin(),
    [](unsigned char c){ return std::tolower(c); });
    
    // 각각의 집합에 문자쌍 추가, 집합의 전체 크기 계산
    for (int i = 0; i < str1.size() - 1; i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z'
           && str1[i+1] >= 'a' && str1[i+1] <= 'z') {
            s.insert(str1.substr(i,2));
            u++;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z'
           && str2[i+1] >= 'a' && str2[i+1] <= 'z') {
            s2.insert(str2.substr(i,2));
            u++;
        }
    }
    // 교집합 제거
    for (auto tmp : s2) {
        auto it = s.find(tmp);
        if (it != s.end()) {
            n++;
            u--;
            s.erase(it);
        }
    }

    double d;
    if (u != n) {
       d = (double)n / u;
    } else {
        d = 1;
    }
    d *= 65536;
    
    answer = d;
    return answer;
}