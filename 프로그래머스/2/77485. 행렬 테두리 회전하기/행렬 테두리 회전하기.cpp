#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>v(rows+1,vector<int>(columns+1,0));
    int cnt = 1;
    for(int i =1; i<=rows;++i)
    {
        for(int j =1; j<=columns;++j)
        {
            v[i][j] = cnt++;
        }
    }
    auto sv = [&] (int sx, int sy, int ex, int ey)
    {
        int pivot = INT_MAX;
        deque<int>dq;
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = sx, y = sy;
        dq.push_back(v[sx][sy]);
        pivot = min(pivot, v[sx][sy]);
        v[sx][sy] = -1;
        auto go = [&] (int d)
        {
            while(1)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if(nx >=sx && nx <=ex && ny >= sy && ny <= ey)
                {
                    x = nx;
                    y = ny;
                    int temp = v[x][y];
                    if(temp == -1)
                    {
                        continue;
                    }
                    pivot = min(temp,pivot);
                    dq.push_back(temp);
                    v[x][y] = -1;
                    continue;
                }
                break;
            }
        };
        for(int i =0; i<4;++i)
        {
            go(i);
        }
        v[sx][sy] = dq.back();
        dq.pop_back();
        auto psh = [&] (int d)
        {
            while(1)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if(nx >=sx && nx <=ex && ny >= sy && ny <= ey)
                {
                    x = nx;
                    y = ny;
                    if (v[x][y] != -1)
                    {
                        continue;
                    }
                    v[x][y] = dq.front();
                    dq.pop_front();
                    continue;
                }
                break;
            }
        };
        for(int i =0; i<4;++i)
        {
            psh(i);
        }
        return pivot;
    };
    for(auto & i : queries)
    {
        answer.push_back(sv(i[0],i[1],i[2],i[3]));
    }
    return answer;
}