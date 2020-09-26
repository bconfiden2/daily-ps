#include <iostream>

using namespace std;

int bingo[5][5];
int answer[25], bingnum;

void check(int r, int c)
{
    int i;
    for(i = 0 ; i < 5 ; i++)
        if(bingo[r][i] != 0) break;
    if(i == 5) bingnum++;

    for(i = 0 ; i < 5 ; i++)
        if(bingo[i][c] != 0) break;
    if(i == 5) bingnum++;

    if(r == c)
    {
        for(i = 0 ; i < 5 ; i++)
            if(bingo[i][i] != 0) break;
        if(i == 5) bingnum++;
    }
    if(r + c == 4)
    {
        for(i = 0 ; i < 5 ; i++)
            if(bingo[i][4-i] != 0) break;
        if(i == 5) bingnum++;
    }
}

void erase(int value)
{
    for(int r = 0 ; r < 5 ; r++)
        for(int c = 0 ; c < 5 ; c++)
        {
            if(bingo[r][c] == value)
            {
                bingo[r][c] = 0;
                check(r, c);
                return;
            }
        }
}

int main()
{
    for(int r = 0 ; r < 5 ; r++)
        for(int c = 0 ; c < 5 ; c++)
            cin >> bingo[r][c];
    for(int i = 0 ; i < 25 ; i++)
        cin >> answer[i];

    for(int i = 0 ; i < 25 ; i++)
    {
        erase(answer[i]);
        
        if(bingnum >= 3)
        {
            cout << i+1 << endl;
            return 0;
        }
    }

}