#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int n = data.size(), m = data[0].size();
    sort(data.begin(),data.end(),[&] (vector<int>&a, vector<int>&b)
         {
             if(a[col-1] == b[col-1])
             {
                 return a[0] > b[0];
             }
             return a[col-1] < b[col-1];
         });
    for(int i = row_begin-1; i<row_end;++i)
    {
        int mod = i +1, temp = 0;
        for(auto & j : data[i])
        {
            temp += j % mod;
        }
        answer ^= temp;
    }
    return answer;
}