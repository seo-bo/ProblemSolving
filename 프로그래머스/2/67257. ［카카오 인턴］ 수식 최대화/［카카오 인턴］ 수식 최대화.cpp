#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll>pll;
typedef pair<int,char> pch;

long long solution(string expression) {
    long long answer = 0;
    int a_cnt = 0, b_cnt = 0;
    deque<pll>num;
    deque<pch>op;
    string temp;
    map<char,int>mm = {{'+',0}, {'-',1}, {'*',2}};
    map<int,char>ss = {{0,'+'}, {1,'-'}, {2,'*'}};
    for(auto & i : expression)
    {
        if('0' <= i && i <= '9')
        {
            temp += i;
        }
        else
        {
            num.push_back(make_pair(a_cnt++,stoll(temp)));
            op.push_back(make_pair(b_cnt++,i));
            temp.clear();
        }
    }
    num.push_back(make_pair(a_cnt++,stoll(temp)));
    vector<int>per(3);
    iota(per.begin(),per.end(),0);
    auto cal = [&] (ll a, ll b, char o)
    {
        if(o == '+')
        {
            return a + b;
        }
        else if(o == '*')
        {
            return a * b;
        }
        return a - b;
    };
    do
    {
        deque<pll>dq = num;
        deque<pch>oper = op;
        for(int i =0; i<3;++i)
        {
            int len = oper.size();
            for(int j =0; j<len;++j)
            {
                if(ss[per[i]] != oper.front().second)
                {
                    oper.push_back(oper.front());oper.pop_front();
                    dq.push_back(dq.front());dq.pop_front();
                }
                else
                {
                    auto [ax,ay] = dq.front();dq.pop_front();
                    auto [bx,by] = dq.front();dq.pop_front();
                    ll co = cal(ay, by, oper.front().second);
                    dq.push_front(make_pair(max(ax,bx), co));
                    oper.pop_front();
                }
            }
            sort(dq.begin(),dq.end());
            sort(oper.begin(),oper.end());
        }
        answer = max(answer, llabs(dq.front().second));
    }while(next_permutation(per.begin(),per.end()));
    return answer;
}