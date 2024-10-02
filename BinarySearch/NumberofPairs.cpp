/* C. Number of Pairs
https://codeforces.com/contest/1538/problem/C
Solution From Santino C.

   |\__/|
   /     \
  /_.~ ~,_\   
     \@/


*/


#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i = 0;i < b; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;


bool check(ll l, ll r, ll sum) {
    return l <= sum && sum <= r;
}

pair<int, int> binarySearchBounds(int i, int n, int l, int r, vector<ll>& a) {
    int s = i + 1, e = n - 1;
    int low = -1, high = -1;

    while (s <= e) {
        int mid = (s + e) / 2;
        ll currentSum = a[i] + a[mid];

        if (check(l, r, currentSum)) {
            high = mid; 
            s = mid + 1; 
        } else if (currentSum < l) {
            s = mid + 1; 
        } else {
            e = mid - 1; 
        }
    }

    e = n - 1;
    s = i + 1; 

    while (s <= e) {
        ll mid = (s + e) / 2;
        ll currentSum = a[i] + a[mid];

        if (check(l, r, currentSum)) {
            low = mid; 
            e = mid - 1; 
        } else if (currentSum < l) {
            s = mid + 1; 
        } else {
            e = mid - 1; 
        }
    }

    return {low, high};
}

void solve(ll n, ll l, ll r, vector<ll>& a) {
    ll solution = 0;

    for (int i = 0; i < n; i++) {
        auto [left, right] = binarySearchBounds(i, n, l, r, a);
        if (left != -1 && right != -1 && right >= left) {
            solution += (right - left + 1);
        }
    }

    cout << solution << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        solve(n, l, r, a);
    }
    return 0;
}