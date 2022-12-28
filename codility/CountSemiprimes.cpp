#include <vector>
#include <cmath>

using namespace std;
//O(N * log(log(N)) + M)
vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<int> result(P.size(), 0);
    int count = 0;
    bool b;

    vector<int> map(N + 1, 0);
    vector<bool> mapb(N + 1, false);
    vector<int> mm(N + 1, false);
    vector<int> primes;

    for (int i = 2; i <= N; i++) {
        b = false;
        if (mapb[i])
            continue;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                b = true;
        }

        if (!b) {
            primes.push_back(i);
        }
        for (int j = 2; j * i <= N; j++) {
            mapb[i] = true;
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        for (int j = 0; j < primes.size(); j++) {
            if (primes[i] * primes[j] > N)
                break;
            mm[primes[i] * primes[j]] = true;
        }
    }

    for (int i = 0; i < mm.size(); i++) {
        if (mm[i]) {
            count++;
        }
        
        map[i] = count;
    }

    for (int i = 0; i < result.size(); i++) {
        result[i] = map[Q[i]] - map[P[i] - 1];
    }

    return result;
}