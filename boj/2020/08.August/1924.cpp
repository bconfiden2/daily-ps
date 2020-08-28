#include <iostream>

using namespace std;

int x, y;
int day;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string date[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main(void)
{
    cin >> x >> y;
    for(int i = 0 ; i < x - 1 ; i++)
    {
        day += days[i];
    }
    day += y;
    cout << date[day % 7] << endl;
}