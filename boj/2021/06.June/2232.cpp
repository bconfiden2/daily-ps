#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int mines[50001];
vector<int> answer;

int max_idx(int l, int r)           // 특정 구간에서 터트릴 지뢰 인덱스(최대값) 구하기
{
    int ret = l, val = mines[l];
    for(int i = l+1 ; i <= r ; i++)
    {
        if(mines[i] > val)
        {
            ret = i;
            val = mines[i];
        }
    }
    return ret;
}

void explode(int l, int r)          // 특정 구간 기준으로 재귀
{
    int point = max_idx(l, r);      // 해당 구간에서 터트릴 위치 가져와서
    answer.push_back(point);        // 출력벡터에 추가해주고
    int cur_l = point, cur_r = point;
    bool changed = true;
    while(changed)                  // 인덱스를 양쪽으로 퍼트려나가면서 지뢰 터짐 처리
    {
        changed = false;
        if(cur_l > l && mines[cur_l] > mines[cur_l - 1]) cur_l--, changed=true;
        if(cur_r < r && mines[cur_r] > mines[cur_r + 1]) cur_r++, changed=true;
    }
    if(cur_l > l) explode(l, cur_l-1);  // 양쪽 끝까지 지뢰 다 터트린 후 왼쪽 구간과 오른쪽 구간에 대해서 다시 재귀적으로 처리
    if(cur_r < r) explode(cur_r+1, r);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i++) cin >> mines[i];
    explode(0, N-1);                                                            // 전체 구간에 대해서 재귀 호출 시작
    sort(answer.begin(), answer.end());
    for(int i = 0 ; i < answer.size() ; i++) cout << answer[i]+1 << '\n';       // 정렬 후 하나씩 출력
}