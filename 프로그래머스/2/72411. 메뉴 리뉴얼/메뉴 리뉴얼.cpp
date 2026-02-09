#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string>answer;
    map<int,int>mm,ss;
    int mask = 0;
    for(auto & i : course)
    {
        mask |= (1<<i);
    }
    for(auto & i : orders)
    {
        int len = i.size();
        for(int j =1; j<(1<<len);++j)
        {
            int temp = 0, cnt = __builtin_popcount(j);
            if(!(mask & (1<<cnt)))
            {
                continue;
            }
            for(int k =0; k<len;++k)
            {
                if(j &(1<<k))
                {
                    temp |= (1<< int(i[k] - 'A'));
                }
            }
            ss[cnt] = max(ss[cnt], ++mm[temp]);
        }
    }
    for(auto & [a,b] : mm)
    {
        string str;
        int cnt = __builtin_popcount(a);
        if(b < ss[cnt] || b == 1)
        {
            continue;
        }
        for(int i =0; i<26;++i)
        {
            if(a & (1<<i))
            {
                str += char('A' + i);
            }
        }
        answer.push_back(str);
    }
    sort(answer.begin(),answer.end());
    return answer;
}