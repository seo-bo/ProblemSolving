#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size(), m = maps[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    auto cal = [&] (char a)
    {
      return int(a - '0');  
    };    
    auto bfs = [&] (int xx, int yy)
    {
        visited[xx][yy] = true;
        int res = cal(maps[xx][yy]);
        queue<pii>q;
        q.push(make_pair(xx,yy));
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            for(int i =0; i<4;++i)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >=0 && nx < n && ny >=0 && ny < m && !visited[nx][ny] && maps[nx][ny] != 'X')
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                    res += cal(maps[nx][ny]);
                }
            }
        }
        return res;
    };
    for(int i =0; i<n;++i)
    {
        for(int j =0; j<m;++j)
        {
            if(maps[i][j] == 'X' || visited[i][j])
            {
                continue;
            }
            answer.push_back(bfs(i,j));
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}