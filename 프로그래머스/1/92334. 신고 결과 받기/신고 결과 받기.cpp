#include <bits/stdc++.h>
using namespace std;
typedef pair<string,string>pss;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
   int n = id_list.size();
vector<int>answer(n);
map<string, int>mm;
for (int i = 0; i < n; ++i)
{
	mm[id_list[i]] = i;
}
vector<int>score(n);
vector<vector<bool>>graph(n, vector<bool>(n, false));
for (auto& i : report)
{
	stringstream ss(i);
	vector<string>ok;
	string temp;
	while (ss >> temp)
	{
		ok.push_back(temp);
	}
	int p1 = mm[ok[0]], p2 = mm[ok[1]];
	if (graph[p1][p2])
	{
		continue;
	}
	graph[p1][p2] = true;
	score[p2]++;
}
for (int i = 0; i < n; ++i)
{
	for (int j = 0; j < n; ++j)
	{
		if (i == j)
		{
			continue;
		}
		if (graph[i][j] && score[j] >= k)
		{
			answer[i]++;
		}
	}
}
return answer;
}