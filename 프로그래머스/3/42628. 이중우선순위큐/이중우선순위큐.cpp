#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    multiset<int>ss;
    for(auto & i : operations)
    {
        if(i[0] == 'D')
        {
            if(ss.empty())
            {
                continue;
            }
            auto it = ss.begin();
            if(i[2] != '-')
            {
                it = prev(ss.end());
            }
            ss.erase(it);
            continue;
        }
        int idx = ((i[2] == '-') ? 3 : 2), p = 0,len = i.size();
        while(idx < len) 
        {
            p = p * 10 + (i[idx++] - '0');
        }
        if(i[2] == '-')
        {
            p *= -1;
        }
        ss.insert(p);
    }
    if(!ss.empty())
    {
        answer[1] = *ss.begin();
        answer[0] = *(prev(ss.end()));
    }
    return answer;
}