#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int MAXN = 1e6;

int N;
pair<int,int> arr[MAXN+4];
int Q, l, r;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> arr[i].fi >> arr[i].se;
    }
    cin >> Q;
    while (Q--){
        cin >> l >> r;
        int res = 0;
        for (int i = 0; i < N; ++i){
            if (arr[i].fi <= l && l <= arr[i].se && arr[i].fi <= r && r <= arr[i].se) ++res;
        }
        cout << res << '\n';
    }
    return 0;
}