#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;             // 문자열을 압축한 후의 사전 색인 번호 배열
    map<string, long long> dict;    // 단어 사전
    stringstream ss;                // 스트링버퍼
    long long counter = 0;          // 색인번호 카운터
    
    // 길이가 1인 모든 단어를 포함하도록 사전 초기화
    for (char i = 'A'; i <='Z'; i++) {
        ss << i;
        dict.insert(make_pair(ss.str(), ++counter));
        ss.str("");
    }
    int right = 0;
    int left = 0;
    int num = 0;
    // 문자열 압축
    for (;;) {
        // 시작 인덱스가 문자열 범위를 벗어난경우
        if (left > msg.size()) {
            ss.str("");
            ss << msg[msg.size()-1];
            auto tt = dict.find(ss.str());
            if (tt == dict.end()) {
                answer.push_back(++counter);
            } else {
                answer.push_back(tt->second);
            }
            break;
        }
        // 마지막 문자인 경우
        if (right > msg.size() - 1) {
            ss.str("");
            ss.str(msg.substr(left, msg.size() - left));
            auto tt = dict.find(ss.str());
            if (tt == dict.end()) {
                answer.push_back(++counter);
            } else {
                answer.push_back(tt->second);
            }
            break;
        }
        
        ss << msg.at(right);
        auto found = dict.find(ss.str());
        if (found != dict.end()) {
            // 사전에 이미 추가된 경우
            right++;
            num = found->second;
        } else {
            // 사전에 없는 경우
            // 이전에 검색된 단어의 색인번호 저장
            answer.push_back(num);
            left = right;
            dict.insert({ss.str(), ++counter});
            num = 0;
            ss.str("");
        }
    }
    
    return answer;
}