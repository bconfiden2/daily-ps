#include <iostream>

using namespace std;

int t, p, q, r, s, w;

int main()
{
    cin >> t;
    for(int tc = 0 ; tc < t ; tc++)
    {
        cin >> p >> q >> r >> s >> w;

        int A = p * w;
        int B = q + (w - r > 0 ? w - r : 0) * s;

        cout << "#" << tc+1 << " " << min(A, B) << endl;
    }
}