#include <bits/stdc++.h>
using namespace std;
int A, B, C;
const int p[6] = {2, 4, 8, 16, 32, 64};

int main()
{

    cin >> A >> B >> C;

    int r_cnt = 0, p_cnt = 0;
    for (int x = -100; x <= 100; x++)
    {
        if (A * x * x + B * x + C == 0)
        {
            r_cnt++;
            for (int i = 0; i < 6; i++)
            {
                if (x == p[i])
                    p_cnt++;
            }
        }
    }

    if (r_cnt != 2)
        cout << "둘다틀렸근";
    else if (p_cnt == 2)
        cout << "이수근";
    else
        cout << "정수근";

    return 0;
}
