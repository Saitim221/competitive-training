/*Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

Input
The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 109).

Output
Write the needed number of flagstones.*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n, m, a;
    cin >> n >> m >> a;

    ll number1 = n/a;
    ll number2 = m/a;

    if(n%a != 0){
        number1 ++;
    }
    if(m%a != 0){
        number2 ++;
    }

    ll result = number1*number2;
    cout << result;
}

/*another thing that we could do, is a round up.
the formula: if we have a/b and we want to make a round up 
do (a+b-1)/b
*/