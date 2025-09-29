#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    pii ans = make_pair(INT_MIN,INT_MIN);
    int limit = emoticons.size();
    vector<vector<int>>dis(41);
    function<void(int)> dfs = [&] (int depth)
    {
      if(depth == limit)
      {
          int a = 0, b = 0;
          for(auto & i : users)
          {
              int sum = 0;
              for(int j = i[0]; j<=40;++j)
              {
                  for(auto & k : dis[j])
                  {
                      sum += k;
                  }
              }
              if(sum < i[1])
              {
                  b += sum;
              }
              else
              {
                  a++;
              }
          }
          if(a == 0 && b == 0)
          {
              return;
          }
          if(a > ans.first)
          {
              ans = make_pair(a,b);
          }
          else if(a == ans.first)
          {
              ans.second = max(ans.second, b);
          }
          return;
      }
      for(int i =10; i<=40;i += 10)
      {
          int cost = emoticons[depth] * (100 - i) / 100;
          dis[i].push_back(cost);
          dfs(depth+1);
          dis[i].pop_back();
      }
    };
    dfs(0);
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}