#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int c = 0;
    int r = 0;
    
    while (n >= a)
    {
        r = n % a;
        c = n / a;
        answer += (c * b);
        n = (n / a) * b;
        n = n + r;
    }
    
    return answer;
}