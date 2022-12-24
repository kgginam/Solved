#include <string>
#include <vector>

using namespace std;

vector<int> r;

void solve(vector<vector<int>>& dungeons, vector<bool> visited, int index ,int count, int k)
{
    int max = 0;
    int c = 0;
    visited[index] = true;
    if (k >= dungeons[index][0])
        k -= dungeons[index][1];
    else
    {
        r.push_back(count - 1);
        return;
    }
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
            c++;
    }
    if (c == visited.size())
    {
        r.push_back(count);
    }
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i])
        {
            solve(dungeons, visited, i, count + 1, k);
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visited;
    int max = 0;
    for (int i = 0; i < dungeons.size(); i++)
    {
        visited.push_back(false);
    }
    
    for (int i = 0; i < dungeons.size(); i++)
    {
        solve(dungeons, visited, i, 1, k);
    }
    
    for (int i = 0; i < r.size(); i++)
    {
        if (max < r[i])
            max = r[i];
    }
    answer = max;
    return answer;
}