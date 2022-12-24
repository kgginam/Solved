#include <vector>

int solution(vector<int> &A) {
    int answer = 0;
    if (A.empty())
        return 0;
    if (A.size() == 1)
        return 0;
    int index = 0;
    while (index < A.size()) {
        for (int i = index + 1; i < A.size(); i++) {
            if (A[index] > A[i]) {
                index = i;
                if (i == A.size() - 1) {
                    index = A.size();
                }
                break;
            } else {
                if (A[i] - A[index] > answer)
                    answer = A[i] - A[index];
            }

            if (i == A.size() - 1) {
                index = A.size();
            }
        }
    }

    return answer;
}