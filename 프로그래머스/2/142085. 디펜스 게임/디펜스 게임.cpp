#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n, int k, vector<int> enemy) {
    int sum =0, len = enemy.size();
    priority_queue<int>pq;
    for(int i =0; i<len;++i)
    {
        int p = enemy[i];
        sum += p;
        pq.push(p);
        while(!pq.empty() && k && sum > n)
        {
            int t = pq.top();
            pq.pop();
            sum -= t;
            k--;
        }
        if(sum > n)
        {
            return i;
        }
    }
    return len;
}