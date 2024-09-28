/*
The classic maximun subarray sum problem

*/




#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i = 0;i < b; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin, x.end
#define mset(a,v) memset((a), (v), sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;






int main(){FIN;
//O(n^2)
    /*int n; cin >> n;
    int a[n];
    int maxsum = 0;
    fore(i, 0, n){
        cin >> a[i];
    }
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i < n+1; i++){
        sum[i] = sum[i-1] + a[i-1];
    }
    fore(i, 0, n+1){
        fore(j, i, n){
            maxsum = max(maxsum, sum[j+1] - sum[i]);
        }
    }
    cout << maxsum << endl;
    */

//O(n)
    int n; cin >> n;
    int a[n];
    int maxsum = 0;
    int mins = 0;
    fore(i, 0, n){
        cin >> a[i];
    }
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i < n+1; i++){
        sum[i] = sum[i-1] + a[i-1];
    }
    


    fore(j, 0, n+1){
        mins = min(mins, sum[j]);
        maxsum = max(maxsum, sum[j] - mins);
    }


    cout << maxsum << endl;
}