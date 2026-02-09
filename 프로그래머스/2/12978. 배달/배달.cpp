#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pii>>graph(N+1);
    for(auto & i : road)
    {
        int a = i[0], b = i[1], c = i[2];
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    vector<int>visited(N+1,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push(make_pair(0,1));
    visited[1] = 0;
    while(!pq.empty())
    {
        auto [co,ver] = pq.top();
        pq.pop();
        if(visited[ver] < co)
        {
            continue;
        }
        for(auto & [nv,nc] : graph[ver])
        {
            if(visited[nv] > co + nc)
            {
                visited[nv] = co + nc;
                pq.push(make_pair(co+nc,nv));
            }
        }
    }
    for(int i =1; i<=N;++i)
    {
        if(visited[i] <= K)
        {
            answer++;
        }
    }
    return answer;
}