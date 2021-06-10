#include <iostream>

using namespace std;

int N;
int values[1000];
int fleft[1000];
int fright[1000];

int main(void)
{
    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        fleft[i] = fright[i] = 1;
        cin >> values[i];
    }

    for(int i = 0 ; i < N ; i++)        // 가장 긴 증가하는 부분 수열
    {
        int maxi = 1;
        for(int k = 0 ; k < i ; k++)
        {
            if(values[k] < values[i])
            {
                if(fleft[k] + 1 > maxi) maxi = fleft[k] + 1;
            }
        }
        fleft[i] = maxi;
    }

    for(int i = N-1 ; i >= 0 ; i--)     // 가장 긴 감소하는 부분 수열
    {
        int maxi = 1;
        for(int k = N-1 ; k > i ; k--)
        {
            if(values[k] < values[i])
            {
                if(fright[k] + 1 > maxi) maxi = fright[k] + 1;
            }
        }
        fright[i] = maxi;
    }

    int answer = 0;
    for(int i = 0 ; i < N ; i++)        // 두 수열의 합 중 최댓값이 가장 긴 바이토닉 수열
    {
        if(fleft[i] + fright[i] > answer)
        {
            answer = fleft[i] + fright[i];
        }
    }
    cout << answer - 1 << endl;
}