/*
Kuriyama Mirai has killed many monsters and got many (namely n) stones. She numbers the stones from 1 to n. The cost of the i-th stone is vi. Kuriyama Mirai wants to know something about these stones so she will ask you two kinds of questions:

She will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her .
Let ui be the cost of the i-th cheapest stone (the cost that will be on the i-th place if we arrange all the stone costs in non-decreasing order). This time she will tell you two numbers, l and r (1 ≤ l ≤ r ≤ n), and you should tell her .
For every question you should give the correct answer, or Kuriyama Mirai will say "fuyukai desu" and then become unhappy.

Input
The first line contains an integer n (1 ≤ n ≤ 105). The second line contains n integers: v1, v2, ..., vn (1 ≤ vi ≤ 109) — costs of the stones.

The third line contains an integer m (1 ≤ m ≤ 105) — the number of Kuriyama Mirai's questions. Then follow m lines, each line contains three integers type, l and r (1 ≤ l ≤ r ≤ n; 1 ≤ type ≤ 2), describing a question. If type equal to 1, then you should output the answer for the first question, else you should output the answer for the second one.

Output
Print m lines. Each line must contain an integer — the answer to Kuriyama Mirai's question. Print the answers to the questions in the order of input.
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

    ll n; cin>>n;
    ll array[n];
    ll arraysorted[n];


    fore(i, 0, n){
        cin>>array[i];
        
    }
    copy(array, array + n, arraysorted);
    sort(arraysorted, arraysorted + n);

    ll partialsum[n+1];
    ll partialsum_o[n+1];

    partialsum_o[0] = 0;
    partialsum[0] = 0;

    for(int i = 1; i < n+1; i++){
        partialsum[i] = partialsum[i-1] + array[i-1];
        partialsum_o[i] = partialsum_o[i-1] + arraysorted[i-1];
    }
    

    ll m; cin >> m;
    while(m--){
        ll type, l, r; cin >> type >> l >> r;
        ll sum;
        l--;
        if(type == 1){
            sum = partialsum[r] - partialsum[l];
        }else{
            sum = partialsum_o[r] - partialsum_o[l];
        }
        cout << sum << endl;
    }

   

}