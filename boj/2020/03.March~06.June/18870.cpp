#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> data(n);            // 실제 데이터들 그대로 담을 배열
    vector<int> answer(n);          // 좌표 압축할 배열
    for(int i = 0 ; i < n ; i++)
    {
        cin >> data[i];
        answer[i] = data[i];
    }
    sort(answer.begin(), answer.end());                                     // 우선 오름차순 정렬을 해준 뒤
    answer.erase(unique(answer.begin(), answer.end()), answer.end());       // 중복되는 값들을 제거해주면 인덱싱 성공
    for(int i = 0 ; i < n ; i++)
    {
        cout << int(lower_bound(answer.begin(), answer.end(), data[i]) - answer.begin()) << " ";    // 인덱싱된 값을 출력
    }
    cout << '\n';
}