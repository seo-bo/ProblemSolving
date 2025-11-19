#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
    int n = board.size(), m = board[0].size();
    vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
    for(int i =1; i<=n;++i)
    {
        for(int j =1; j<=m;++j)
        {
            prefix[i][j] = board[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]; 
        }
    }
    auto query = [&] (int sx, int sy, int ex, int ey)
    {
      return prefix[ex][ey] + prefix[sx -1][sy -1] - prefix[ex][sy -1] - prefix[sx -1][ey];
    };
    int left = 0, right = max(n,m), answer = 0;
    auto cal = [&] (int mid)
    {
        int base = (mid+1) * (mid+1);
        for(int i =1; i + mid <=n;++i)
        {
            for(int j =1; j+mid <=m;++j)
            {
                if(base == query(i,j,i+mid,j+mid))
                {
                    return true;
                }
            }
        }
        return false;
    };
    while(left <=right)
    {
        int mid = (left +right) / 2;
        if(cal(mid))
        {
            left = mid + 1;
            answer = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return answer * answer;
}