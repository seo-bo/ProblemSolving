#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
   int n = genres.size();
vector<int>res(n);
vector<int>answer;
iota(res.begin(), res.end(), 0);
map<string, int>mm;
map<string, int>gen;
int cnt = 0;
for (int i = 0; i < n; ++i)
{
	if (gen.find(genres[i]) == gen.end())
	{
		gen[genres[i]] = cnt++;
	}
	mm[genres[i]] += plays[i];
}
sort(res.begin(), res.end(), [&](const int& a, const int& b)
	{
		if (genres[a] == genres[b])
		{
			if (plays[a] == plays[b])
			{
				return a < b;
			}
			return plays[a] > plays[b];
		}
		return mm[genres[a]] > mm[genres[b]];
	});
vector<int>score(150);
for (auto& i : res)
{
	if (++score[gen[genres[i]]] > 2)
{
	continue;
}
	answer.push_back(i);
}
return answer;
}