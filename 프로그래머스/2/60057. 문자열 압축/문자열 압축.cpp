#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;
    int len = s.size();
    for(int i =1; i<=len;++i)
    {
        string pre, res;
        int cnt = 1;
        for(int j =0; j<len; j += i)
        {
            string temp;
            for(int k = j; k < min(len,i + j);++k)
            {
                temp += s[k];
            }
            if(pre != temp)
            {
                res += pre;
                if(cnt > 1)
                {
                    res += to_string(cnt);
                }
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            pre = temp;
        }
        res += pre;
        if(cnt > 1)
        {
            res += to_string(cnt);
        }
        answer = min(answer, (int)res.size());
    }
    return answer;
    
}