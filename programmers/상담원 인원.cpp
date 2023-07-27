#include <string>
#include <vector>

using namespace std;

struct Request {
    int clock;
    int time;
    int type;
    Request() {
        this->clock = 0;
        this->time = 0;
        this->type = 0;
    }
    Request(int clock, int time, int type) {
        this->clock = clock;
        this->time = time;
        this->type = type;
    }
};

struct Time {
    int time;
    int waitTime;
    Time() {
        this->time = 0;
        this->waitTime = 0;
    }
    Time(int time, int waitTime) {
        this->time = time;
        this->waitTime = waitTime;
    }
};

struct C {
    int before;
    int after;
    C() {
        before = 0;
        after = 0;
    }
};

int subTime(int a, int b) {
    return (a - b) > 0 ? a - b : b - a;
}

int calc(vector<Request>& divReq, int man) {
    if (divReq.empty() || divReq.size() <= 1) {
        return 0;
    }
    
    int result = 0;
    vector<Time> mentos;
    Time t;
    int min = 100000;
    int index = 0;
    
    
    for (int i = 0; i < man; i++) {
        t.time = divReq[i].time + divReq[i].clock;
        t.waitTime = 0;
        mentos.push_back(t);
    }
    
    for (int i = man; i < divReq.size(); i++) {
        min = 100000;
        index = 0;
        for (int j = 0; j < mentos.size(); j++) {
            if (mentos[j].time < min) {
                min = mentos[j].time;
                index = j;
            }
        }
        if (min == 100000)
            continue;
        if (divReq[i].clock >= mentos[index].time) {
            mentos[index].time = divReq[i].clock + divReq[i].time;
        }
        else {
            mentos[index].waitTime = mentos[index].waitTime + (mentos[index].time - divReq[i].clock);
            mentos[index].time = mentos[index].time + divReq[i].time;
        }
        
    }
    
    for (int i = 0; i < mentos.size(); i++) {
        result += mentos[i].waitTime;
    }
    
    return result;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    
    vector<C> times;
    vector<int> cv;
    vector<vector<Request>> divReq;
    vector<Request> d;
    vector<int> lestTime;
    int leftn = n - k;
    Request tmp;
    C ctmp;
    
    for (int i = 0; i < k; i++) {
        divReq.push_back(d);
        times.push_back(ctmp);
    }
    // 상담 유형으로 데이터 분리
    for (int i = 0; i < reqs.size(); i++) {
        tmp.clock = reqs[i][0];
        tmp.time = reqs[i][1];
        tmp.type = reqs[i][2];
        divReq[tmp.type-1].push_back(tmp);
    }
    
    for (int i = 0; i < k; i++) {
        ctmp.before = calc(divReq[i], 1);
        ctmp.after = 0;
        times.push_back(ctmp);
        cv.push_back(1);
    }

    C result;
    int max;
    int index;
    while (leftn > 0) {
        max = 0;
        index = 0;
        for (int i = 0; i < k; i++) {
            times[i].before = calc(divReq[i], cv[i]);
            if (times[i].before == 0)
                continue;
            times[i].after = calc(divReq[i], cv[i] + 1);
            if (subTime(times[i].after, times[i].before) > max) {
                max = subTime(times[i].after, times[i].before);
                index = i;
            }
        }
        cv[index]++;
        times[index].before = times[index].after;
        leftn--;
    }
    
    for (int i = 0; i < cv.size(); i++) {
        answer += calc(divReq[i], cv[i]);
    }
    
    return answer;
}