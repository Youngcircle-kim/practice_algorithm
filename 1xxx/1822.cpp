#include<bits/stdc++.h>
using namespace std;
int nA, nB;
int a[500005], b[500005];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> sol;
    cin >> nA >> nB;
    for(int i = 0; i < nA; i++){
        cin >> a[i];
    }
    for(int i = 0; i < nB; i++){
        cin >> b[i];
    }
    sort(a, a+nA);
    sort(b, b+nB);
    
    for(int i = 0; i < nA; i++){
        auto lo = lower_bound(b, b+nB, a[i]) - b;
        if(b[lo] != a[i]) sol.push_back(a[i]);
    }
    cout << sol.size() << "\n";
    for(auto it : sol) cout << it << " ";
}
