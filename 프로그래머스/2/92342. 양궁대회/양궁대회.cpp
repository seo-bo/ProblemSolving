#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int>score(11);
    int pivot = INT_MIN;
    reverse(info.begin(),info.end());
    function<void(int, int)> dfs = [&] (int depth, int nokori)
    {
        if(depth == 10)
        {
            score[10] += nokori;
            int a = 0, b = 0; // 어피치, 라이언
            for(int i =0; i<=10;++i)
            {
                if(info[i] >= score[i])
                {
                    if(info[i])
                    {
                        a += i;
                    }
                }
                else
                {
                    b += i;
                }
            }
            if(a < b)
            {
                if(b - a > pivot)
                {
                    pivot = b-a;
                    answer = score;
                }
            }
            score[10] -= nokori;
            return;
        }
        for(int i = nokori; i>=0;--i)
        {
            score[depth] += i;
            dfs(depth+1,nokori - i);
            score[depth] -= i;
        }
    };
    dfs(0,n);
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}