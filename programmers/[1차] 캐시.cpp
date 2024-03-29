#include <string>
#include <vector>

using namespace std;

// 캐시에 저장된 데이터가 있을 경우 refresh
void refresh_vector(vector<string> &cache, int index) {
    string tmp = cache[index];
    cache.erase(cache.begin() + index);
    cache.push_back(tmp);
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    // 캐시될 데이터를 소문자로 변경
    for (auto &str : cities) {
        for (auto &ch : str) {
            ch = tolower(ch);
        }
    }
    
    int c = 0;
    bool isRefreshed = false;
    int indexr;
    // 초기 캐시 사이즈 채울 동안 loop
    for (int i = 0;; i++) {
        if (c >= cities.size()) {
            break;
        }
        if (cache.size() >= cacheSize) {
            break;
        }
        isRefreshed = false;
        // 캐시를 순회하며 저장되었는지 확인
        for (int j = 0; j < cache.size(); j++) {
            if (cities[c] == cache[j]) {
                indexr = j;
                isRefreshed = true;
                break;
            } 
        }
        // 저장되지 않은 경우 새로 추가
        if (!isRefreshed) {
            cache.push_back(cities[c]);
            answer += 5;
        } else {    // 저장된 경우 캐시 refresh
            refresh_vector(cache, indexr);
            answer += 1;
        }
        c++;
    }
    
    // 캐시 사이즈 채운 후 loop
    for (int i = c; i < cities.size(); i++) {
        isRefreshed = false;
        // 캐시를 순회하며 저장되었는지 확인
        for (int j = 0; j < cache.size(); j++) {
            if (cities[i] == cache[j]) {
                indexr = j;
                isRefreshed = true;
                break;
            } 
        }
        // 저장되지 않은 경우 가장 오래된 데이터 삭제 후 추가
        if (!isRefreshed) {
            cache.erase(cache.begin());
            cache.push_back(cities[i]);
            answer += 5;
        } else {    // 저장된 경우 캐시 refresh
            refresh_vector(cache, indexr);
            answer += 1;
        }
    }
    
    return answer;