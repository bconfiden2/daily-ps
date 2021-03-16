#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x, item, cnt;
int ldx, rdx;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> item;
        v.push_back(item);          // 배열 전부 입력받은 후
    }
    cin >> x;
    sort(v.begin(), v.end());       // 오름차순으로 정렬

    ldx = 0;
    rdx = v.size()-1;               // 양 끝점부터 시작
    while(ldx < rdx)                // 원소 다 돌때까지
    {
        item = v[ldx] + v[rdx];     // 두 수의 합이
        if(item < x) ldx++;         // 작다면 왼쪽포인터를 옮겨 값을 키우고
        else if(item > x) rdx--;    // 크다면 오른쪽을 내려 값을 줄이고
        else
        {
            cnt++;                  // 구하는 값과 같다면 카운트해주고 오른쪽을 내림
            rdx--;
        }
    }

    cout << cnt << endl;
}