#include <string>
#include <vector>
#include <climits>

using namespace std;

const int DIA = 1000;
const int IRON = 2000;
const int STONE = 3000;

int minv = INT_MAX;

int getCost(int pick, string mineral) {
    if (pick == DIA) {
        return 1;
    }
    if (pick == IRON) {
        if (mineral == "diamond") {
            return 5;
        } else {
            return 1;
        }
    }
    if (pick == STONE) {
        if (mineral == "diamond") {
            return 25;
        } else if (mineral == "iron") {
            return 5;
        } else {
            return 1;
        }
    }
    
    return -1;
}

void solve(int dia, int iron, int stone, vector<string> &minerals, int index, int nowPick, int cost) {
    int m = (index + 5 > minerals.size() ? minerals.size() : index + 5);
    if (index >= minerals.size()) {
        if (cost < minv) {
            minv = cost;
            return;
        }
    }
    for (int i = index; i < m; i++) {
        if (i >= minerals.size()) {
            if (cost < minv) {
                minv = cost;
                return;
            }
    }
        cost += getCost(nowPick, minerals[i]);
    }
    if (dia > 0) {
        solve(dia-1, iron, stone, minerals, m, DIA, cost);
    }
    if (iron > 0) {
        solve(dia, iron-1, stone, minerals, m, IRON, cost);
    }
    if (stone > 0) {
        solve(dia, iron, stone-1, minerals, m, STONE, cost);
    }
    if (dia == 0 && iron == 0 && stone == 0) {
        if (cost < minv) {
            minv = cost;
        }
        return;
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    if (picks[0] > 0) {
        solve(picks[0]-1, picks[1], picks[2], minerals, 0, DIA, 0);
    }
    if (picks[1] > 0) {
        solve(picks[0], picks[1]-1, picks[2], minerals, 0, IRON, 0);
    }
    if (picks[2] > 0) {
        solve(picks[0], picks[1], picks[2]-1, minerals, 0, STONE, 0);
    }
    if (minv == INT_MAX) {
        answer = 0;
    } else {
        answer = minv;
    }
    return answer;
}