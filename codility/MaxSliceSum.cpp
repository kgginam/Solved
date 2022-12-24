#include <vector>

int solution(vector<int> &A) {
    int answer = A[0];
    int count = A[0];
    for (int i = 1; i < A.size(); i++) {
        if (count + A[i] >= 0) {
            if (count + A[i] < A[i])
                count = A[i];
            else
                count += A[i];
        }
        else {
            count = A[i];
        }
        if (count > answer) {
            answer = count;
        }
    }

    return answer;
}
