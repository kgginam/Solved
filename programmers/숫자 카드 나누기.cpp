#include <string>
#include <vector>

using namespace std;

bool isModable(vector<int>& array, int c)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] % c != 0)
            return false;
    }
    
    return true;
}

int getMax(vector<int>& array)
{
    int max = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (max < array[i])
            max = array[i];
    }
    
    return max;
}

bool isNotModable(vector<int>& array, int c)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] % c == 0)
            return false;
    }
    
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int maxA;
    int maxB;
    
    maxA = getMax(arrayA);
    maxB = getMax(arrayB);
    
    for (int i = 2; i <= maxA; i++)
    {
        if (isModable(arrayA, i) && isNotModable(arrayB, i))
            answer = i;
    }
    
    int tmp = 0;
    
    for (int i = 2; i <= maxB; i++)
    {
        if (isModable(arrayB, i) && isNotModable(arrayA, i))
            tmp = i;
    }
    
    
    return answer > tmp ? answer : tmp;
}