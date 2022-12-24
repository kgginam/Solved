#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    bool isProc = true;
    int before;
    answer = arr[0];
    while (isProc) {
        before = answer;
        for (int i = 0; i < arr.size(); i++) {
            if (answer % arr[i] != 0) {
                answer++;
                break;
            }
        }
        if (before == answer) {
            isProc = false;
        }
    }
    return answer;
}