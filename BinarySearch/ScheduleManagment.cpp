/*There are n
 workers and m
 tasks. The workers are numbered from 1
 to n
. Each task i
 has a value ai
 — the index of worker who is proficient in this task.

Every task should have a worker assigned to it. If a worker is proficient in the task, they complete it in 1
 hour. Otherwise, it takes them 2
 hours.

The workers work in parallel, independently of each other. Each worker can only work on one task at once.

Assign the workers to all tasks in such a way that the tasks are completed as early as possible. The work starts at time 0
. What's the minimum time all tasks can be completed by?

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of testcases.

The first line of each testcase contains two integers n
 and m
 (1≤n≤m≤2⋅105
) — the number of workers and the number of tasks.

The second line contains m
 integers a1,a2,…,am
 (1≤ai≤n
) — the index of the worker proficient in the i
-th task.

The sum of m
 over all testcases doesn't exceed 2⋅105
.

Output
For each testcase, print a single integer — the minimum time all tasks can be completed by.*/







/*I couldn't do it*/
#include <iostream>
#include <algorithm>
using namespace std;
 
bool check(int time[], int n, int t)
{
    long long free = 0, need = 0;
 
    for(int i = 0; i < n; i++) {
        if(t >= time[i]) { // assign more which takes time 2
            free += (t - time[i]) / 2;
        }
        else {
            need += (time[i] - t);
        }
    }
 
    return free >= need;
}
 
 
void solve(int arr[], int n, int m)
{
    int time[n] = {0};
 
    for(int i = 0; i < m; i++) {
        time[arr[i]]++;
    }
 
    int s = 0, e = 2 * m;
    int ans = 0;
 
    while(s <= e) {
        int mid = (s + e) / 2;
 
        if(check(time, n, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
 
    cout << ans << endl;
}
 
int main()
{
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
 
        int arr[m];
 
        for(int i = 0; i < m; i++) {
            cin >> arr[i];
            --arr[i];
        }
 
        solve(arr, n, m);
    }
 
    return 0;
}

    