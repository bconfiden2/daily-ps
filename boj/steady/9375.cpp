#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int tc;
    cin >> tc;
    for(int t = 0 ; t < tc ; t++)
    {
        int n;
        cin >> n;
        // 보기 편하게 의상의 종류들 모아놓은 벡터
        vector<string> cates;
        // 의상 종류별로 옷들 넣어놓는 맵, 옷 이름 대신 번호로 저장
        map<string, vector<int>> m;
        string cate;
        string cloth;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> cloth >> cate;
            // 만약 처음 들어온 의상 종류라면
            if(m.find(cate) == m.end())
            {
                vector<int> clothes;
                // 의상 종류를 맵에 추가
                m.insert(pair<string,vector<int>>(cate, clothes));
                cates.push_back(cate);
            }
            // 해당 종류에 번호로 추가
            m[cate].push_back(m[cate].size() + 1);
        }

        int mul = 1;
        // (n + 1) * (m + 1) * ... * (x + 1) - 1
        for(int i = 0 ; i < cates.size() ; i++)
        {
            mul *= m[cates[i]].size() + 1;
        }
        cout << mul - 1<< '\n';
    }
}