#include <string>
#include <vector>
#include <cmath>

using namespace std;

string reverseStr(string s) {
    string result = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        result += s[i];
    }
    return result;
}

bool isPrime(long long n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    int N = n;
    int K = k;
    
    string s = "";
    string tmp = "";
    
    while (N >= 1) {
        s += to_string(N % K);
        N /= K;
    }
    if (s.size() >= 2)
        s = reverseStr(s);
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            tmp += s[i];
            
            if (i == s.size() - 1) {
                if (tmp != "") {
                    if (isPrime(stol(tmp))) {
                        answer++;
                    }
                    break;
                }
            }
        } else {
            if (tmp != "") {
                if (isPrime(stol(tmp))) {
                    answer++;
                }
            }
            tmp = "";
        }
    }
    
    return answer;
}