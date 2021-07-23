#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N, K, answer, tmp;
int digits[7];
int numbers[10];

// 특정 위치의 값이 주어지면 수식을 완성시킬 수 있는 값인지 검사
bool is_valid(string tmp, int idx)
{
    // 해당 값의 자릿수가 수식의 자릿수와 같은지
    if(tmp.size() != digits[idx]) return false;
    // 해당 값이 모두 주어진 값들로만 구성이 되어있는지
    for(int i = 0 ; i < tmp.size() ; i++)
    {
        bool exist = false;
        for(int k = 0 ; k < K ; k++)
        {
            if((tmp[i]-'0')==numbers[k]) exist = true;
        }
        if(!exist) return false;
    }
    return true;
}

// 두 숫자가 주어졌을 때, 현재 수식을 만족하는지 검사
bool able(int a, int b)
{
    // 두 숫자를 곱한 정답이 유효한지
    if(!is_valid(to_string(a * b), N-1)) return false;
    // 첫번째 숫자와, 두번째 숫자의 각 자릿수들을 곱한 중간값들이 유효한지
    for(int i = 0 ; i < digits[1] ; i++)
    {
        if(!is_valid(to_string(a * (to_string(b)[i]-'0')), N-2-i)) return false;
    }
    return true;
}

// 두번째 숫자(최대 3자리) 백트래킹으로 가능한 모든 경우의 수 탐색
void selectB(int blen, int bval, int aval)
{
    // 두번째 숫자도 다 뽑았으면, 첫번째 숫자와 함께 수식을 완성시킬 수 있는지 검사
    if(blen == digits[1])
    {
        answer += able(aval, bval);
        return;
    }
    // 1의자리부터 하나씩 뽑아나감
    for(int i = 0 ; i < K ; i++)
    {
        selectB(blen+1, bval+(numbers[i])*(pow(10,blen)), aval);
    }
}

// 첫번째 숫자(최대 5자리) 백트래킹으로 가능한 모든 경우의 수 탐색
void selectA(int alen, int aval)
{
    // 첫번째 숫자를 다 뽑았으면, 두번째 숫자를 뽑기 시작
    if(alen == digits[0])  
    {
        selectB(0, 0, aval);
        return;
    }
    // 1의자리부터 하나씩 뽑아나감
    for(int i = 0 ; i < K ; i++)
    {
        selectA(alen+1, aval+(numbers[i])*(pow(10,alen)));
    }
}

int main(void)
{
    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> tmp;
        digits[i] = tmp;
    }
    cin >> K;
    for(int i = 0 ; i < K ; i++)
    {
        cin >> tmp;
        numbers[i] = tmp;
    }

    selectA(0, 0);
    cout << answer << endl;    
}