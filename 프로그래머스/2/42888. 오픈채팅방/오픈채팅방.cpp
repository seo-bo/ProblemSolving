#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int>pii;
vector<string> solution(vector<string> record) {
    vector<string>answer;
string ent = "님이 들어왔습니다.";
string exi = "님이 나갔습니다.";
map<string, string>mm;
for (auto& i : record)
{
	string temp;
	stringstream ss(i);
	vector<string>ok;
	while (ss >> temp)
	{
		ok.push_back(temp);
	}
	if (ok[0] == "Leave")
	{
		continue;
	}
	mm[ok[1]] = ok[2];
}
for (auto& i : record)
{
	string temp;
	stringstream ss(i);
	vector<string>ok;
	while (ss >> temp)
	{
		ok.push_back(temp);
	}
	if (ok[0] == "Change")
	{
		continue;
	}
	string res = mm[ok[1]];
	if (ok[0] == "Enter")
	{
		res += ent;
	}
	else
	{
		res += exi;
	}
	answer.push_back(res);
}
return answer;
}