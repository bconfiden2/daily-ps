#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 입력되는 정수의 갯수를 담아놓을 배열
int freqs[8001];

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // 입력받을 정수들을 쌓아놓는 벡터
  vector<int> v;
  // 각각 답으로 출력할 변수들
  int mean, mid, freq, sco;

  int sum = 0; // 평균을 구하기 위한 총합
  int max = -4000; // 최댓값을 담아놓을 변수
  int min = 4000; // 최솟값을 담아놓을 변수

  int n = 0;
  cin >> n;
  int val;

  for(int i = 0 ; i < n ; i++)
  {
    cin >> val;
    sum += val;
    if(val > max)
    {
      max = val;
    }
    if(val < min)
    {
      min = val;
    }
    freqs[val+4000]++;
    v.emplace_back(val);
  }
  // 최빈값이 몇인지 확인
  int freqmax = 0;
  for(int i = 0 ; i < 8001 ; i++)
  {
    if(freqs[i] > freqmax)
    {
      freqmax = freqs[i];
    }
  }
  // 최빈값들이 얼마나 있는지 확인, 2개 이상으로 넘어갈 시 2번째 값을 넣고 종료
  int count = 0;
  for(int i = 0 ; i < 8001 ; i++)
  {
    if(freqs[i] == freqmax)
    {
      count++;
      freq = i - 4000;
    }
    if(count == 2)
    {
      break;
    }
  }

  sort(v.begin(), v.end());

  mean = int(round(sum / (double)n));
  mid = v[(n-1)/2]; // n 은 항상 홀수!
  sco = max - min; // 사실 v.end() - v.begin() 으로 해도 된다.

  cout << mean << '\n';
  cout << mid << '\n';
  cout << freq << '\n';
  cout << sco << '\n';
}
