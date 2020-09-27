#include <iostream>

using namespace std;

int n, answer;
bool pos[100][100];

int main(void)
{
    cin >> n;
    for(int i = 0, a, b ; i < n ; i++)
    {
        cin >> a >> b;
        for(int r = a ; r < a + 10 ; r++)
            for(int c = b ; c < b + 10 ; c++)
                pos[r][c] = true;
    }
    for(int r = 0 ; r < 100 ; r++)
        for(int c = 0 ; c < 100 ; c++)
            if(pos[r][c]) answer++;
    cout << answer << endl;
}