#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> solution(int n, long long k) {
	k--;
	vector<int> answer;
	vector<ll>fact(21, 1);
	set<int>s;
	for (int i = 1; i <= n; ++i)
	{
		fact[i] = (fact[i - 1] * i);
		s.insert(i);
	}
	if (fact[n] == k)
	{
		vector<int>temp(n);
		iota(temp.begin(), temp.end(), 1);
		sort(temp.rbegin(), temp.rend());
		return temp;
	}
	for (int i = n - 1; i >= 0 && k && !s.empty(); --i)
	{
		auto it = s.begin();
		while (k >= fact[i])
		{
			k -= fact[i];
			++it;
		}
		answer.push_back(*it);
		s.erase(*it);
	}
	for (auto& i : s)
	{
		answer.push_back(i);
	}
	return answer;
}