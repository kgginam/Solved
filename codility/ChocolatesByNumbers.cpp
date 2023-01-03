/* 75%
#include <vector>

using namespace std;

int solution(int N, int M) {
    int result = 1;
    int ate = M % N;
    vector<bool> eat(N, false);
    while (ate != 0) {
        if (!eat[ate]) {
            result++;
            eat[ate] = true;
        }
        
        ate = (ate + M) % N;

    }

    return result;
}
*/

int gcd(int n, int m) {
    if (m == 0)
        return n;
    
    return gcd(m, n%m);
}

int solution(int N, int M) {
    int tmp = gcd(N, M);
    int result = N / tmp;

    return result;
}