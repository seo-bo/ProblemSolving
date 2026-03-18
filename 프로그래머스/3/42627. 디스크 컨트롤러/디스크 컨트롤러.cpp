#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int>tp;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<tp>v;
    for(auto & i : jobs)
    {
        int a = i[0], b = i[1], c = v.size();
        v.push_back(make_tuple(a,b,c));    
    }
    sort(v.begin(),v.end());
    priority_queue<tp,vector<tp>,greater<tp>>pq;
    int time = 0, idx = 0, len = v.size();
    while(idx < len || !pq.empty())
    {
        while(idx < len && get<0>(v[idx]) <= time)
        {
            auto [a,b,c] = v[idx++];
            pq.push(make_tuple(b,a,c));
        }
        if(!pq.empty())
        {
            auto [b,a,c] = pq.top();
            pq.pop();
            time += b;
            answer += time - a;
        }
        else
        {
            time++;
        }
    }
    return answer / len;
}