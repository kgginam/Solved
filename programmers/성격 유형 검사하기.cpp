#include <string>
#include <vector>

using namespace std;

int getScore(int c)
{
    int score = 0;
    switch (c)
    {
        case 1:
            score = -3;
            break;
        case 2:
            score = -2;
            break;
        case 3:
            score = -1;
            break;
        case 4:
            score = 0;
            break;
        case 5:
            score = 1;
            break;
        case 6:
            score = 2;
            break;
        case 7:
            score = 3;
            break;
    }
    return score;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int i = -1;
    int rt = 0;
    int cf = 0;
    int jm = 0;
    int an = 0;
    
    for (auto s : survey)
    {
        i++;
        if (s == "RT")
        {
            rt += getScore(choices.at(i));
        }
        else if (s == "TR")
        {
            rt -= getScore(choices.at(i));
        }
        else if (s == "FC")
        {
            cf -= getScore(choices.at(i));
        }
        else if (s == "CF")
        {
            cf += getScore(choices.at(i));
        }
        else if (s == "MJ")
        {
            jm -= getScore(choices.at(i));
        }
        else if (s == "JM")
        {
            jm += getScore(choices.at(i));
        }
        else if (s == "AN")
        {
            an += getScore(choices.at(i));
        }
        else if (s == "NA")
        {
            an -= getScore(choices.at(i));
        }
    }
    
    if (rt <= 0)
    {
        answer += "R";
    }
    else
    {
        answer += "T";
    }
    if (cf <= 0)
    {
        answer += "C";
    }
    else
    {
        answer += "F";
    }
    if (jm <= 0)
    {
        answer += "J";
    }
    else
    {
        answer += "M";
    }
    if (an <= 0)
    {
        answer += "A";
    }
    else
    {
        answer += "N";
    }
    return answer;
}