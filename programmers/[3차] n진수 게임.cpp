#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 숫자를 문자로 변환
string getStringNum(int f) {
    switch (f) {
        case 0: return "0";
        case 1: return "1";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "A";
        case 11: return "B";
        case 12: return "C";
        case 13: return "D";
        case 14: return "E";
        case 15: return "F";
    }
    return "0";
}

string splitnum(int num, int n, int &count, const int &m, const int &p) {
    string ss = "";
    // 몫과 나머지가 모두 0일때 까지 (주어진 숫자를 해당 진수로 변환 완료할때 까지)
    while (1) {
        int f = num % n;
        int s = num / n;
        if (f == 0 && s == 0) {
            break;
        }
        // 해당 진수의 0승 부터 차례로 구한다
        ss = getStringNum(f) + ss;
        num = s;
    }
    string rtmp = "";
    // 각 진수의 제곱으로 분류하여 말해야할 차례에 해당하는 문자 저장
    // 1 0 0 0 이고 첫 순서로 2번마다 말해야 하는 경우 1, 0 을 저장
    for (auto i = 0; i < ss.size(); i++) {
        ++count;
        // 인원 수와 말해야할 순서가 같은 경우
        // 예를 들어 2명일 때 2번, 또는 3명일 때 3번과 같은 경우
        if (m == p) {
            //  말해야 할 순서인 경우 저장
            if (count % m == 0) {
                rtmp += ss[i];
            }
        } else {
            if (count % m == p) {
                rtmp += ss[i];
            }
        }
    }
    return rtmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    ostringstream oss;
    int num = 0;
    int count = 0;
    
    // 말해야 할 숫자를 모두 채울때 까지
    while(1) {
        if (oss.str().size() >= t) {
            break;
        }
        // 숫자가 해당 진수 이상인 경우
        if (num >= n) {
            oss << splitnum(num, n, count, m, p);
        } else {
            ++count;
            if (m == p) {
                if (count % m == 0) {
                    oss << getStringNum(num);
                }
            } else {
                if (count % m == p) {
                    oss << getStringNum(num);
                }
            }
        }
        num++;
    }

    answer = oss.str();
    // 만약 위의 함수에서 데이터가 초과 저장된 경우
    if (answer.size() > t) {
        answer = answer.substr(0, t);
    }
    return answer;
}