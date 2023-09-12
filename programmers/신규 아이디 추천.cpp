#include <string>
#include <vector>
#include <cctype>
#include <regex>

using namespace std;

string first(string s) {
    for (char &c : s) {
        if (isalpha(c) && isupper(c)) {
            c = tolower(c);
        }
    }
    
    return s;
}

string second(string s) {
    regex re("[^a-z0-9\-_.]");
    return regex_replace(s, re, "");
}

string third(string s) {
    regex re("\\.{2,}");
    return regex_replace(s, re, ".");
}

string fourth(string s) {
    regex re("^\\.?(.*?)\\.?$");
    return regex_replace(s, re, "$1");
}

string fifth(string s) {
    if (s.size() == 0) {
        s = "a";
    }
    return s;
}

string sixth(string s) {
    if (s.size() >= 16) {
        s = s.substr(0, 15);
        regex re("(.*?)\\.?$");
        s = regex_replace(s, re, "$1");
    }
    return s;
}

string seventh(string s) {
    if (s.size() <= 2) {
        auto tmp = s.substr(s.size()-1);
        while (s.size() < 3) {
            s += tmp;
        }
    }
    return s;
}

string solution(string new_id) {
    string answer = "";
    
    answer = first(new_id);
    answer = second(answer);
    answer = third(answer);
    answer = fourth(answer);
    answer = fifth(answer);
    answer = sixth(answer);
    answer = seventh(answer);
    
    return answer;
}