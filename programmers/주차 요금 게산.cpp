#include <string>
#include <vector>
#include <map>

using namespace std;

int subValue(int a, int b) {
    int tmp = a - b;
    return tmp >= 0 ? tmp : -tmp;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    string h,m;
    int times;
    string number;
    string action;
    string tmp;
    int ttp;
    int cost;
    map<string, int> notes;
    map<string, int> outputs;
    
    for (int i = 0; i < records.size(); i++) {
        tmp = records[i];
        times = stoi(tmp.substr(0, 2)) * 60;
        times += stoi(tmp.substr(3, 2));
        number = tmp.substr(6, 4);
        action = tmp.substr(11);
        
        if (action == "IN") {
            if (notes.find(number) == notes.end()) {
                notes.insert({number, times});
            } 
        } else {
            auto it = notes.find(number);
            ttp = subValue(it->second, times);
            if (ttp == 0) {
                if (outputs.find(number) == outputs.end())
                    outputs.insert({number, 0});
            } else {
                if (outputs.find(number) == outputs.end())
                    outputs.insert({number, ttp});
                else
                    outputs.find(number)->second += ttp; 
            }
            
            notes.erase(it);
        }
    }
    
    int endTime = 1439;
    for (auto t : notes) {
        ttp = subValue(t.second, endTime);
        if (outputs.find(t.first) == outputs.end())
            outputs.insert({t.first, ttp});
        else
            outputs.find(t.first)->second += ttp;
    }
    
    for (auto output : outputs) {
        auto tt = output.second -= fees[0];
        cost = fees[1];
        if (tt > 0) {
            cost += (tt / fees[2]) * fees[3];
            if (tt % fees[2] > 0)
                cost += fees[3];
        }
        answer.push_back(cost);
    }
    return answer;
}