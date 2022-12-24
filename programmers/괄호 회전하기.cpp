#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int count = 0;
    int ss = 0;
    int b = 0;
    int m = 0;
    bool isBreak = false;
    bool isComplete = true;
    vector<int> brackets;
    
    for (int i = 0; i < s.size(); i++)
    {
        ss = 0;
        b = 0;
        m = 0;
        brackets.clear();
        for (int j = 0; j < s.size(); j++)
        {
            switch (s.at((j+count) % s.size()))
            {
                case '{':
                    brackets.push_back(2);
                    m++;
                    break;
                case '(':
                    brackets.push_back(1);
                    ss++;
                    break;
                case '[':
                    brackets.push_back(3);
                    b++;
                    break;
                case '}':
                    if (m <= 0)
                    {
                        isBreak = true;
                        isComplete = false;
                    }
                    else
                    {
                        if (*(brackets.end() - 1) != 2)
                        {
                            isComplete = false;
                            isBreak = true;
                            break;
                        }
                        brackets.erase(brackets.end() - 1);
                        m--;
                    }
                    break;
                case ')':
                    if (ss <= 0)
                    {
                        isBreak = true;
                        isComplete = false;
                    }
                    else
                    {
                        if (*(brackets.end() - 1) != 1)
                        {
                            isComplete = false;
                            isBreak = true;
                            break;
                        }
                        brackets.erase(brackets.end() - 1);
                        ss--;
                    }
                    break;
                case ']':
                    if (b <= 0)
                    {
                        isBreak = true;
                        isComplete = false;
                    }
                    else
                    {
                        if (*(brackets.end() - 1) != 3)
                        {
                            isComplete = false;
                            isBreak = true;
                            break;
                        }
                        brackets.erase(brackets.end() - 1);
                        b--;
                    }
                    break;
            }
            if (isBreak)
            {
                isBreak = false;
                break;   
            }
        }
        
        if (isComplete)
        {
            if (ss == 0 && b == 0 && m == 0)
                answer++;
        }
        else
        {
            isComplete = true;
        }
        count++;
        
        }
    
    return answer;
}