#include <string>
#include <set>
#include <iostream>
using namespace std;

#define minDir -5
#define maxDir 5

int solution(string dirs) {
    int answer = 0;
    set<pair<pair<int,int>,pair<int,int>>> s; // 현재 좌표와 이전 좌표를 저장
    int x = 0;      // 현재 좌표
    int y = 0;      // ``
    int beforeX;    // 이전 좌표
    int beforeY;    // ``
    for (char direction : dirs) {
        // 이동 전의 값
        beforeX = x;
        beforeY = y;
        // 좌표평면을 벗어나지 않고, 각 방향으로 이동
        if (direction == 'U') {
            if (y < maxDir) {
                y += 1;
            }
        }
        if (direction == 'D') {
            if (y > minDir) {
                y -= 1;
            }
        }
        if (direction == 'L') {
            if (x > minDir) {
                x -= 1;
            }
        }
        if (direction == 'R') {
            if (x < maxDir) {
                x += 1;
            }
        }
        // 좌표평면 내에서 이동했을 경우
        if (beforeX != x || beforeY != y) {
            // 이동 경로가 처음일 경우 현재 좌표와 이전 좌표 저장
            // (1,2)에서 (1,1)로 가는 경우와 (1,1)에서 (1,2)로 가는 경우 같은 이동으로 처리
            if (s.find(make_pair(make_pair(x, y), make_pair(beforeX, beforeY))) == s.end() &&
                s.find(make_pair(make_pair(beforeX, beforeY), make_pair(x, y))) == s.end()
               ) {
                s.insert(make_pair(make_pair(x, y), make_pair(beforeX, beforeY)));
            }
        }
    }
    
    answer = s.size();
    return answer;
}