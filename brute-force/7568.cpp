#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<pair<int, int> > v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int rank = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second)
            {
                rank += 1;
            }
            
        }
        cout << rank << endl;
        rank = 1;
    }
}
// 입력 최대 개수 50(2500은 100만 보다 작아서)이여서, 제한시간도 빡빡하지 않아 완전 탐색으로 해결할 수 있음.
// 문제는 그냥 나보다 '덩치'가 큰놈이 몇명인지 count해서 print하면 되는 간단한 문제이다.
// 선형 자료구조 선택을 잘하면 금방 풀릴거 같다. cpp경우는 pair + 아무 선형 자료구조로 푸는게 베스트인거 같다.