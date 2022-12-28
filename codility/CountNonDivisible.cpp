/*first solve #77%#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> &A) {
    map<int, int> m;
    vector<int> answer;
    int count;
    for (int i = 0; i < A.size(); i++) {
        count = 0;

        auto it = m.find(A[i]);
        if (it != m.end()) {
            answer.emplace_back(it->second);
            continue;
        }
        for (int j = 0; j < A.size(); j++) {
            if (i == j)
                continue;
            
            if (A[i] % A[j] != 0)
                count++;
        }

        m.insert({A[i], count});
        answer.push_back(count);
    }

    return answer;
}
*/

//second solve
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> &A) {
    int N = A.size();
    map<int, int> count;
    vector<int> answer(N, N);

    for (int i = 0; i < N; i++) {
        if (count.find(A[i]) == count.end()) {
            count[A[i]] = 1;
        } else {
            count[A[i]]++;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 1; j * j <= A[i]; j++) {
            if (A[i] % j == 0) {
                answer[i] -= count[j];  
                if (A[i] / j != j) {
                    answer[i] -= count[A[i] / j];   
                } 
            }
        }
    }
    
    return answer;
}
