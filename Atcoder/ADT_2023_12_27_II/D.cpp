#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v = { 0,3,1,4,1,5,9};
	vector<int>prefix(8);
	for (int i = 2; i <= 7; ++i)
	{
		prefix[i] = prefix[i - 1] + v[i-1];
	}
	char a, b;
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	int pa = a - 'A' + 1, pb = b - 'A' + 1;
	cout << prefix[pb] - prefix[pa];
	return 0;
}
