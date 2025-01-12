#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for(auto e : v){
        cout << e << " ";
    }
}