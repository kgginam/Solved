#include<vector>
using namespace std;

static const int up = 1;
static const int down = 2;
static const int left = 3;
static const int right = 4;

void solve(vector<vector<int>> maps, int direction, int index1, int index2, int count, int *answer)
{
    count++;
    if (*answer != -1)
    {
        if (count >= *answer)
            return;
    }
    if (count > maps.size() * maps[0].size())
        return;
    if (direction == up)
    {
        --index1;
    }
    else if (direction == down)
    {
        ++index1;
    }
    else if (direction == left)
    {
        --index2;
    }
    else
    {
        ++index2;
    }
    if (index1 < 0 || index1 >= maps.size())
        return;
    if (index2 < 0 || index2 >= maps[0].size())
        return;
    if (maps[index1][index2] == 0)
        return;
    
    if (index1 >= maps.size() - 1 && index2 >= maps[0].size() - 1 && maps[index1][index2] == 1)
    {
        if (*answer == -1)
        {
            *answer = count;
            return;
        }
        if (*answer > count)
        {
            *answer = count;
            return;
        }
        return;
    }
    
    maps[index1][index2] = 0;
    if (direction == up)
    {
        solve(maps, up, index1, index2, count, answer);
        solve(maps, left, index1, index2, count, answer);
        solve(maps, right, index1, index2, count, answer);
    }
    else if (direction == down)
    {
        solve(maps, down, index1, index2, count, answer);
        solve(maps, left, index1, index2, count, answer);
        solve(maps, right, index1, index2, count, answer);
    }
    else if (direction == left)
    {
        solve(maps, up, index1, index2, count, answer);
        solve(maps, down, index1, index2, count, answer);
        solve(maps, left, index1, index2, count, answer);
    }
    else if (direction == right)
    {
        solve(maps, up, index1, index2, count, answer);
        solve(maps, down, index1, index2, count, answer);
        solve(maps, right, index1, index2, count, answer);
    }   
}

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    
    if (maps[maps.size()-1][maps[0].size() - 2] == 0 && maps[maps.size()-2][maps[0].size() - 1] == 0)
    {
        return -1;
    }
    
    solve(maps, down, 0, 0, 1, &answer);
    solve(maps, right, 0, 0, 1, &answer);
    return answer;
}
