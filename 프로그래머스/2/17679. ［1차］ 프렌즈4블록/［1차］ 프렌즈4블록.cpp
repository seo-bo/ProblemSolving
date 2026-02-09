#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<string> board) {
    int answer = 0;
    vector<vector<int>>dir = {{0,0},{0,1},{1,0},{1,1}};
    auto cal = [&] ()
    {
        vector<string>temp = board;
        int ans = 0;
        for(int i =0; i<n;++i)
        {
            for(int j =0; j<m;++j)
            {
                int flag = 1;
                char pivot = board[i][j];
                if(pivot == '_')
                {
                    continue;
                }
                for(int k=0; k<4;++k)
                {
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if(nx >=0 && nx < n && ny >=0 && ny < m && board[nx][ny] == pivot)
                    {
                        continue;
                    }
                    flag = 0;
                    break;
                }
                if(flag)
                {
                    for(int k=0; k<4;++k)
                    {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        ans += (temp[nx][ny] != '_');
                        temp[nx][ny] = '_';
                    }
                }
            }
        }
        vector<string>save(n);
        for(int j = 0; j <m;++j)
        {
            vector<char>v;
            for(int i = n-1; i>=0;--i)
            {
                if(temp[i][j] == '_')
                {
                    continue;
                }
                int x = i;
                while(x < n-1)
                {
                    if(temp[x+1][j] == '_')
                    {
                        swap(temp[x][j], temp[x+1][j]);
                        x++;
                        continue;
                    }
                    break;
                }
            }
        }
        board = move(temp);
        if(!ans)
        {
            return false;
        }
        answer += ans;
        return true;
    };
    while(cal());
    return answer;
}