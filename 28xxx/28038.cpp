#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926;
int t, type;
double _x, _y, _r, _t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        _x = 0.0; // 직교 좌표 x
        _y = 0.0; // 직교 좌표 y
        _r = 0.0; // 극 좌표 r
        _t = 0.0; // 극 좌표 theta
        cin >> type;
        if (type == 1)
        {
            cin >> _x >> _y;
            // 피타고라스 원점부터의 거리
            _r = sqrt(pow(_x, 2) + pow(_y, 2));
            // 각도(theta) 구하기 reverse tangent(arctan) 사용
            _t = atan2(_y, _x);
            if (_t < 0)
            {
                _t += 2 * PI;
            }
            cout << fixed << setprecision(8) << _r << " " << _t << "\n";
        }
        else
        {
            cin >> _r >> _t;
            _x = (double)_r * cos(_t);
            _y = (double)_r * sin(_t);
            cout << fixed << setprecision(8) << _x << " " << _y << "\n";
        }
    }

    return 0;
}