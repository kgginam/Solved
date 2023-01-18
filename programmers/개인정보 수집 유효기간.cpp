#include <string>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

struct Dates {
    int year;
    int month;
    int day;
};

struct Privacies {
    Dates d;
    string kind;
};

bool compareDate(Dates d1, Dates d2) {
    
    if (d1.year > d2.year)
        return true;
    if (d1.year < d2.year)
        return false;
    
    if (d1.month > d2.month)
        return true;
    if (d1.month < d2.month)
        return false;
    
    if (d1.day >= d2.day)
        return true;
    
    return false;   
}

pair<string, int> getTerms(string term) {
    
    pair<string, int> tmp;
    
    tmp.first = term.substr(0, 1);
    tmp.second = atoi(term.substr(2, term.size() - 2).c_str());
    return tmp;
}


Dates getDate(string date) {
    Dates result;
    
    result.year = atoi(date.substr(0, 4).c_str());
    result.month = atoi(date.substr(5, 2).c_str());
    result.day = atoi(date.substr(8).c_str());
    
    return result;
}

Privacies getPrivacies(string date) {
    Privacies result;
    
    result.d.year = atoi(date.substr(0, 4).c_str());
    result.d.month = atoi(date.substr(5, 2).c_str());
    result.d.day = atoi(date.substr(8, 2).c_str());
    result.kind = date.substr(11);
    
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> mterms;
    Dates now;
    now = getDate(today);
    
    for (int i = 0; i < terms.size(); i++) {
        auto tmp = getTerms(terms[i]);
        mterms.insert({tmp.first, tmp.second});
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        auto tmp = getPrivacies(privacies[i]);
        
        tmp.d.month += mterms[tmp.kind];
        if (tmp.d.month > 12) {
            tmp.d.year += tmp.d.month / 12;
            tmp.d.month %= 12;
            if (tmp.d.month == 0) {
                tmp.d.month = 12;
                tmp.d.year--;
            }
        }
        
        if (compareDate(now, tmp.d))
            answer.push_back(i + 1);
    }
    
    
    return answer;
}