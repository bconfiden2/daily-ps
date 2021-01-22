#include <iostream>
#include <queue>

using namespace std;

int N, temp, start, endd;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> lectures;
priority_queue<int, vector<int>, greater<int>> rooms;

int main(void)
{
    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> temp >> start >> endd;
        lectures.push({start, endd});
    }

    // 첫 강의를 강의실에 하나 추가해놓고 시작
    rooms.push(lectures.top().second);
    lectures.pop();

    // 모든 강의를 배정하는데, 강의는 시작시간이 빠른 순으로 확인
    while(lectures.size())
    {
        // 기존 강의실 중에서 가장 빨리 끝나는 강의실에 새로운 강의 배정
        if(rooms.top() <= lectures.top().first)
        {
            rooms.push(lectures.top().second);
            rooms.pop();
        }
        // 가장 빨리 끝나는 강의실도 이번 강의와 시간이 맞지 않으면, 새로운 강의실 추가
        else
        {
            rooms.push(lectures.top().second);
        }
        lectures.pop();
    }

    cout << rooms.size() << endl;
}