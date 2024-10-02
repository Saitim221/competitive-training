/* A. Dragons
https://codeforces.com/problemset/problem/230/A
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
#define fore(i,a,b) for(int i = a;i < b; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;



void solve(vector<pair<ll,ll>> d, ll n, ll s){
    bool alive = true;
    int i = 0;
    while(alive && i < n){
        if(s > d[i].fst){
            s += d[i].snd;
        }else{
            alive = false;
        }
        i++;
    }
    if(alive){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}


int main(){FIN;
ll s, n; cin>>s>>n;
vector<pair<ll,ll>> d(n); 
for(auto &e:d) cin>>e.fst>>e.snd;
sort(d.begin(), d.end());


solve(d, n, s);


}