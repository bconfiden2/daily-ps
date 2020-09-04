#include <iostream>

using namespace std;

int n;

pair<unsigned long,unsigned long> nums[91];     // <끝이 0 으로 끝나는 숫자, 끝이 1 로 끝나는 숫자>

int main(void)
{
    cin >> n;
    nums[1] = {0, 1};                           // 1자리 숫자는 1 밖에 없기 때문에 <0,1> 로 시작
    
    for(int i = 2 ; i <= n ; i++)               // 2자리 숫자부터 n 자리 숫자까지
    {
        nums[i] = {nums[i-1].first + nums[i-1].second, nums[i-1].first};    // i 번째 자리에서 가능한 값은
    }                                                                       // 0 으로 끝나는 값은 i-1 번째에서 뭐가 오든 상관없지만
                                                                            // 1 로 끝나는 값은 i-1 번째에서 반드시 0으로 끝나야 한다
    cout << nums[n].first + nums[n].second << endl; // 가능한 n 자리 숫자의 갯수
}


/************************************
#include <iostream>

int N;
long long a[91] = {0, 1};

int main()
{
    scanf("%d", &N);
    for(int i = 2 ; i <= N ; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    printf("%lld", a[N]);
}
*************************************/