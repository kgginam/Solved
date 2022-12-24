#include <vector>

using namespace std;

int solution(vector<int> &A) {

    if (A.size() < 3)
        return 0;
        
    vector<int> peaks;
    int t = 0;
    int tt = 0;
    int count = 0;
    int index;

    for (int i = 1; i < A.size() - 1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) 
            peaks.emplace_back(i);
    }

    if (peaks.size() == 0)
        return 0;

    for (count = peaks.size(); count >= 2; count--) {
        index = A.size() / count;
        if (A.size() % count != 0)
            continue;
        t = 0;
        tt = 0;
        for (int i = 0; i < peaks.size(); i++) {
            if (peaks[i] >= t && peaks[i] < t + index) {
                tt++;
                t+=index;
            }
            
            if (tt == count) {
                return count;
            }
        }
    }

    return 1;
}