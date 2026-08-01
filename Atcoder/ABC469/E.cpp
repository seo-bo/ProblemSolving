#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	string str;
	cin >> str;
	vector<ld>prefix(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + (str[i - 1] == 'o');
	}
	/*
	* prefix[r] - prefix[l-1] / (r - l +1) >= mid
	* prefix[r] - prefix[l-1] >= (r - l + 1)mid;
	* prefix[r] - mid*r >= prefix[l-1] - mid*l + mid
	* l은 계속 바뀌어서 애매하니, r을 하나씩 순회하고 과거 l중에 그런놈이 있다면 불러오기
	*/
	auto cal = [&](ld mid)
		{
			ld pivot = LLONG_MAX;
			for (int l = 1, r = 1; r <= n; ++r)
			{
				while (l <= r && prefix[r] - prefix[l - 1] >= k)
				{
					pivot = min(pivot, prefix[l - 1] - mid * l + mid);
					l++;
				}
				if (prefix[r] - mid * r >= pivot)
				{
					return true;
				}
			}
			return false;
		};
	ld left = 0, right = 1, ans = -1;
	for (int i = 0; i < 100; ++i)
	{
		ld mid = (left + right) / 2;
		if (cal(mid))
		{
			ans = mid;
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	cout << fixed << setprecision(15) << ans;
	return 0;
}
