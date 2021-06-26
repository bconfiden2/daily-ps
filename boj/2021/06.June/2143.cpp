#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n, m;
unsigned long long answer;
int arrN[1001];
int arrM[1001];

int main(void)
{
    cin >> T;
    
    cin >> n;
    vector<int> N;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> arrN[i];
        arrN[i] += arrN[i-1];                   // n 개의 수들에 대해 누적합을 구하고
        for(int j = 0 ; j < i ; j++)
        {
            N.push_back(arrN[i] - arrN[j]);     // 가능한 모든 부분합들에 대해서 저장함
        }
    }
    cin >> m;
    vector<int> M;
    for(int i = 1 ; i <= m ; i++)               // m 개 배열에 대해서도 마찬가지로 저장
    {
        cin >> arrM[i];
        arrM[i] += arrM[i-1];
        for(int j = 0 ; j < i ; j++)
        {
            M.push_back(arrM[i] - arrM[j]);
        }
    }

    sort(M.begin(), M.end());                   // 두 배열 중 한개 배열에 대해서 정렬을 해준 뒤

    for(int i = 0 ; i < N.size() ; i++)         // 나머지 배열의 원소들을 선형 탐색하면서 정렬된 배열에서 이진 탐색으로 맞는 값 확인
    {
        int target = T - N[i];                  // stl 에서 제공되는 알고리즘을 사용하면 편함...
        answer += (upper_bound(M.begin(), M.end(), target) - lower_bound(M.begin(), M.end(), target));
    }

    cout << answer << endl;
}