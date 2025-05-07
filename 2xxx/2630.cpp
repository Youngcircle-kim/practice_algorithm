#include<bits/stdc++.h>
using namespace std;
int k;
int mat[130][130];
int ans[2];
vector<int> v;
bool chk(int n, int x, int y) {
  for (int i = x; i < x + n; i++)
    for (int j = y; j < y + n; j++)
      if (mat[i][j] != mat[x][y]) return false;
  return true;
}

void func(int n, int x, int y) {
  if (chk(n, x, y)) {
    ans[mat[x][y]]++;
    return;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) func(n / 2, x + i * n / 2, y + j * n / 2);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //constraints
    // 2<= k <= 128
    cin >> k;
    for(int x= 0; x < k; x++){
        for(int y = 0; y < k; y++){
            cin >> mat[x][y];
        }
    }
    func(k, 0,0);
    cout << ans[0] << "\n";
    cout << ans[1] << "\n";

}
