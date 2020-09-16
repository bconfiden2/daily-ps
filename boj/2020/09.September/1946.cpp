#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
int n;
int pap, inv;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> tc;
    for(int t = 0 ; t < tc ; t++)
    {
        cin >> n;
        vector<pair<int,int>> v;
        for(int i = 0 ; i < n ; i++)        // 서류순위와 면접순위 입력받아서 벡터에 푸시
        {
            cin >> pap >> inv;
            v.push_back({pap, inv});
        }
        sort(v.begin(), v.end());           // 서류순위 높은순으로 정렬

        int answer = 0, cur = 10e6;
        for(int i = 0 ; i < n ; i++)
        {                                   // 서류순위가 높은 순(등수니까 값이 낮은순)으로 검사하기 때문에
            if(v[i].second < cur)           // 면접순위가 더 높은 사람이 나올때만
            {
                answer++;                   // 해당 사람을 뽑고
                cur = v[i].second;          // 해당 사람의 면접순위를 다시 cur 에 저장하여 그 이후 사람들과 비교
            }
        }
        cout << answer << '\n';
    }
}