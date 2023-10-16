#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int size = elements.size();
    for (int i = 0; i < size; i++) {
        elements.push_back(elements[i]);
        s.insert(elements[i]);
    }
    
    for (int count = 1; count <= size; count++) {
        for (int i = 0; i < size; i++) {
            int sum = 0;
            for (int j = i; j < i+count; j++) {
                sum += elements[j];
            }
            s.insert(sum);
        }
    }
    answer = s.size();
    return answer;
}