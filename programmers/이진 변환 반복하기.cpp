#include <string>
#include <vector>

using namespace std;

struct my_data
{
    int count;
    string str;
};

string to_binary(int i)
{
    string s= "";
    while(i > 0)
    {
        if (i % 2 == 1)
            s = "1" + s;
        else
            s = "0" + s;
        i >>= 1;
    }
    return s;
}

auto solve(string s)
{
    my_data d;
    d.count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == '0')
        {
            d.count++;
        }
    }
    
    d.str = to_binary(s.size() - d.count);
    
    return d;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int sum = 0;
    my_data d;
    d.count = 0;
    d.str = s;
    answer.push_back(0);
    answer.push_back(0);
    while (1)
    {
        if (d.str == "1")
            break;
        count++;
        d = solve(d.str);
        sum += d.count;
    }
    answer[0] = count;
    answer[1] = sum;
    return answer;
}