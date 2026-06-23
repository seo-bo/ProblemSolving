#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int h = 0, w = 0;
	cin >> h >> w;
	vector<vector<char>>v1(w,vector<char>(h)), v2(w, vector<char>(h));
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> v1[j][i];
		}
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> v2[j][i];
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout << ((v1 == v2) ? "Yes" : "No");
	return 0;
}
