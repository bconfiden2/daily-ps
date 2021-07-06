#include <iostream>
#include <vector>

using namespace std;

int cumsum, x;
vector<int> values(1000001, 1);                         // 모두 자기 자신만을 가질 수 있기 때문에 최소 1 의 값들은 가짐 (1원 제외)

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    values[1] = 0;
    for(int cur = 2 ; cur <= 1413 ; cur++)              // 1부터 1413 까지의 연속합이 100만에 가장 가까움 - 1413 은 최대로 연속 가능한 값의 개수
    {
        cumsum += cur-1;
        for(int i = 2 ; cur*i+cumsum <= 1000000 ; i++)  // 2개가 연속된 값의 경우 2x+1, 3개는 3x+3, 4개는 4x+6 의 꼴로 표현 가능
        {
            values[cur*i+cumsum]++;                     // 따라서 해당 표현식으로 가능한 모든 값들에 대해서 경우의 수 하나씩 올려줌
        }
    }

    cin >> x;
    while(x)
    {
        cout << values[x] << '\n';
        cin >> x;
    }
}