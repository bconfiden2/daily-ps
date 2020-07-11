#include <iostream>
#include <set>
using namespace std;

int t, k;
char func;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for(int tc = 0 ; tc < t ; tc++)
    {
        multiset<int> s;
        cin >> k;
        for(int i = 0, data ; i < k ; i++)
        {
            cin >> func >> data;
            if(func == 'I') s.insert(data);                 // 삽입 시 자동 오름차순 정렬
            else
            {
                if(s.empty())  continue;
                if(data == 1)  s.erase(--s.end());          // 뒤에서 하나 지움
                else           s.erase(s.begin());          // 앞에서 하나 지움
            }
        }
        if(s.empty()) cout << "EMPTY" << '\n';
        else cout << *(--s.end()) << " " << *(s.begin()) << '\n';
    }
}