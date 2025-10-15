#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    map<string,int>mm = {{"cpp",0},{"java",1},{"python",2},{"backend",0},{"frontend",1},{"junior",0},{"senior",1},{"chicken",0},{"pizza",1}};
    vector<int>v[3][2][2][2];
    for(auto & i : info)
    {
        stringstream ss(i);
        string temp;
        vector<string>count;
        while(ss >> temp)
        {
            count.push_back(temp);
        }
        v[mm[count[0]]][mm[count[1]]][mm[count[2]]][mm[count[3]]].push_back(stoi(count.back()));
    }
    for(int i =0; i<3;++i)
    {
        for(int j =0; j<2;++j)
        {
            for(int k =0; k<2;++k)
            {
                for(int z = 0; z < 2; ++z)
                {
                    sort(v[i][j][k][z].begin(), v[i][j][k][z].end());
                }
            }
        }
    }
    vector<int>answer;
    for(auto & i : query)
    {
        stringstream ss(i);
        string temp;
        vector<string>ok;
        while(ss >> temp)
        {
            if(temp != "and")
            {
                ok.push_back(temp);
            }
        }
        vector<bool>flag(4,true);
        for(int i =0; i<4;++i)
        {
            if(ok[i] == "-")
            {
                flag[i] = false;
            }
        }
        int res = 0;
        for(int i = ((flag[0]) ? mm[ok[0]] : 0); i <= ((flag[0]) ? mm[ok[0]] : 2) ;++i)
        {
            for(int j = ((flag[1]) ? mm[ok[1]] : 0) ; j<= ((flag[1]) ? mm[ok[1]] : 1) ;++j)
            {
                for(int k = ((flag[2]) ? mm[ok[2]] : 0) ; k<= ((flag[2]) ? mm[ok[2]] : 1);++k)
                {
                    for(int z = ((flag[3]) ? mm[ok[3]] : 0) ; z <= ((flag[3]) ? mm[ok[3]] : 1); ++z)
                    {
                        int idx = lower_bound(v[i][j][k][z].begin(),v[i][j][k][z].end(), stoi(ok[4])) - v[i][j][k][z].begin();
                        int len = v[i][j][k][z].size();
                        res += len - idx;
                    }
                }
            }
        }
        answer.push_back(res);
    }
    return answer;
}