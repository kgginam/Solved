#include <string>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &arr, vector<int> &answer, int start, int length, int rows) {
    
    int count0 = 0;
    int count1 = 0;
    int maxCount = length * length;
    for (int i = rows; i < rows + length; i++) {
        for (int j = start ; j < start + length; j++) {
            
            if (arr[i][j] == 0) {
                count0++;
            }
            
            if (arr[i][j] == 1) {
                count1++;
            }
        }
    }
    
    if (count0 == maxCount) {
        answer[0]++;
        return;
    }
    if (count1 == maxCount) {
        answer[1]++;
        return;
    }
    
    if (length <= 2) {
        answer[0] += count0;
        answer[1] += count1;
        return;
    }
    int len = length / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            solve(arr, answer, j * len + start, len, i * len + rows);
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    solve(arr, answer, 0, arr.size(), 0);
    return answer;
}