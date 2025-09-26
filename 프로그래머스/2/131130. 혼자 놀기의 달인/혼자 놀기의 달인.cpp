#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int>temp;
    int n = cards.size();
    vector<int>visited(n,false);
    for(int i =0; i<n;++i)
    {
        int x = i;
        if(visited[x])
        {
            continue;
        }
        int t = 0;
        while(!visited[x])
        {
            visited[x] = true;
            x = cards[x] -1;
            t++;
        }
        temp.push_back(t);
    }
    sort(temp.rbegin(),temp.rend());
    return temp[0] * ((temp.size() == 1) ? 0 : temp[1]);
}