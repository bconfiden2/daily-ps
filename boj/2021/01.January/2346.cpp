#include <iostream>
#include <deque>

using namespace std;

int n, temp;
deque<pair<int, int>> dq;

int main(void)
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp;
        dq.push_back({temp, i});        // 덱에 숫자와 인덱스를 같이 넣어준다
    }
    while(dq.size())                    // 풍선을 다 터트릴때까지
    {
        pair<int, int> cur = dq.front();    // 현재 풍선에 대한 정보를 가진 후
        dq.pop_front();                     // 풍선 터뜨림
        cout << cur.second + 1 << " ";      // 이번에 터뜨린 풍선에 해당하는 인덱스를 출력해줌
        if(cur.first > 0)                   // 양수일 경우
        {
            for(int i = 0 ; i < cur.first-1 ; i++)  // 하나를 터트렸으니 -1 해준 갯수만큼

            {
                dq.push_back(dq.front());           // 오른쪽 풍선들을 뒤로 옮겨줌
                dq.pop_front();
            }
        }
        else                                // 음수일 경우
        {
            for(int i = 0 ; i < -cur.first ; i++)   // 왼쪽풍선들은 해당 갯수 그대로
            {
                dq.push_front(dq.back());           // 앞으로 이동
                dq.pop_back();
            }
        }
    }
    cout << endl;
}