#include <iostream>
#include <vector>
#include <algorithm>
#define Point pair<int,int>
#define ABS(a) (((a) < 0) ? (-(a)) : (a))               // 괄호 처리에 주의할 것
using namespace std;

int n,m;
int ans = 1000000;
int city[50][50];

int distance(const Point& a, const Point& b)
{
    return ABS(a.first - b.first) + ABS(a.second - b.second);   // 두 점 사이의 맨해튼 거리를 반환해주는 함수
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    vector<Point> chickens;                             // 치킨집 위치들을 담을 벡터
    for(int r = 0 ; r < n ; r++)
    {
        for(int c = 0 ; c < n ; c++)
        {
            cin >> city[r][c];
            if(city[r][c] == 2)                         // 데이터 입력 받으면서 치킨집도 갱신
            {
                chickens.push_back(Point(r,c));
            }
        }
    }
    vector<int> tempVector;                             // 조합 처리용 벡터
    for (int i = 0; i < m; i++)
    {
        tempVector.push_back(1);
    }
    for (int i = 0; i < chickens.size() - m; i++)       // 조합을 구하기 위한 값들 처리
    {
        tempVector.push_back(0);
    }
    sort(tempVector.begin(), tempVector.end());

    do                                                  // 치킨집 C m (가능한 조합 경우의 수 완전탐색)
    {                                                   // 이번에 살릴 치킨집들에 대한 정보는 tempVector 에 있음
        int cur = 0;
        for(int r = 0 ; r < n ; r++)                    
        {
            for(int c = 0 ; c < n ; c++)                // 이번 조합에서의 치킨거리 cur 을 구함
            {
                if(city[r][c] == 1)                     // 각각의 집 별로 가장 가까운 치킨거리를 cur 에 더함
                {
                    int minimum = 10000;
                    for (int i = 0; i < tempVector.size(); i++)
                    {
                        if (tempVector[i] == 1)         // 살릴 치킨집들에 대해서만 치킨거리를 구함
                        {
                            int te = distance(chickens[i], Point(r,c));
                            if(te < minimum) minimum = te; 
                        }
                    }
                    cur += minimum;                     // 모든 집들에 대해서 각자의 치킨거리를 더해줌
                }
            }
        }
        if(cur < ans) ans = cur;                        // 치킨거리가 최소화되는 조합을 업데이트
    } while (next_permutation(tempVector.begin(), tempVector.end()));
    cout << ans << '\n';
}