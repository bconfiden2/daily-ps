#include <iostream>

using namespace std;

int N, w;
unsigned long long answer = 0;              // 오버플로우 대비 ull
unsigned long long min_price = 1000000000;
int length[100001];

int main(void)
{
    cin >> N;
    for(int i = 1 ; i <= N-1 ; i++)         // 도시 간의 거리를 일단 배열에 저장
    {
        cin >> w;
        length[i] = w;
    }
    for(int i = 1 ; i <= N ; i++)           // 각 지점의 기름 값을 확인하면서
    {
        cin >> w;
        if(w < min_price) min_price = w;    // 현재위치까지의 기름의 최솟값을 저장
        answer += (min_price * length[i]);  // 다음 최소값이 나올때까지 현재 최소값의 기름으로 도시를 경유
    }

    cout << answer << endl;
}