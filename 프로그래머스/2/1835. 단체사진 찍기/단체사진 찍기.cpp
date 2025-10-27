#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char>per = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    sort(per.begin(),per.end());
    map<char,int>mm;
    int cnt = 1;
    for(auto & i : per)
    {
        mm[i] = cnt++; 
    }
    vector<vector<pii>>graph(10,vector<pii>(10,make_pair(-1,-1)));
    for(auto & i : data)
    {
        int a = mm[i[0]], b = mm[i[2]];
        char pivot = i[3];
        int num = (i[4] - '0');
        pii now = make_pair(-1,-1);
        if(pivot == '>')
        {
            now = make_pair(num+1,INT_MAX);
        }
        else if(pivot == '<')
        {
            now = make_pair(INT_MIN,num-1);
        }
        else
        {
            now = make_pair(num,num);
        }
        if(graph[a][b] == make_pair(-1,-1))
        {        
           graph[a][b] = graph[b][a] = now;
        }
        else
        {
            pii pre = graph[a][b];
            if(now.first <= pre.second && pre.first <= now.second)
            {
                graph[a][b] = graph[b][a] = make_pair(max(now.first,pre.first),min(pre.second,now.second));
            }
            else if(pre.first <= now.second && now.first <= pre.second)
            {
                graph[a][b] = graph[b][a] = make_pair(max(now.first,pre.first), min(pre.second,now.second));
            }
            else
            {
                return 0;
            }
        }
    }
    auto cal = [&]
        {
            for(int i =0;i<8;++i)
            {
                for(int j =0;j<8;++j)
                {
                    int a = mm[per[i]], b = mm[per[j]];
                    int dist = abs(i-j)-1;
                    auto [start,end] = graph[a][b];
                    if(start == -1 && end == -1)
                    {
                        continue;
                    }
                    if(!(start <= dist && dist <= end))
                    {
                        return false;
                    }
                }
            }
            return true;
        };
    do
    {
        if(cal())
        {
            answer++;
        }
    }while(next_permutation(per.begin(),per.end()));
    return answer;
}