#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Convolution //https://github.com/seo-bo/Algorithm_templates/blob/main/Convolution.cpp
{
private:
	vector<complex<double>>v1, v2;
	int len;
	void fft(vector<complex<double>>& v, int pivot)
	{
		for (int i = 1, j = 0; i < len; ++i)
		{
			int bit = len >> 1;
			while (j & bit)
			{
				j ^= bit;
				bit >>= 1;
			}
			j ^= bit;
			if (i < j)
			{
				swap(v[i], v[j]);
			}
		}
		for (int i = 2; i <= len; i <<= 1)
		{
			double angle = 2 * acos(-1.0) * pivot / i;
			complex<double> z(cos(angle), sin(angle));
			for (int j = 0; j < len; j += i)
			{
				complex<double> w(1, 0);
				for (int k = 0; k < i / 2; ++k)
				{
					complex<double>fa = v[j + k];
					complex<double>fb = v[j + k + i / 2] * w;
					v[j + k] = fa + fb;
					v[j + k + i / 2] = fa - fb;
					w *= z;
				}
			}
		}
		if (pivot == -1)
		{
			for (auto& i : v)
			{
				i /= len;
			}
		}
	}
	vector<int> get_conv()
	{
		fft(v1, 1);
		fft(v2, 1);
		for (int i = 0; i < len; ++i)
		{
			v1[i] *= v2[i];
		}
		fft(v1, -1);
		vector<int>ans(len);
		for (int i = 0; i < len; ++i)
		{
			ans[i] = (int)round(v1[i].real());
		}
		return ans;
	}
public:
	Convolution(vector<int>& p1, vector<int>& p2)
	{
		v1 = vector<complex<double>>(p1.begin(), p1.end());
		v2 = vector<complex<double>>(p2.begin(), p2.end());
		int n = 1;
		while (n < (int)v1.size() + (int)v2.size())
		{
			n <<= 1;
		}
		len = n;
		v1.resize(len), v2.resize(len);
	}
	vector<int> solve()
	{
		vector<int>ok = get_conv();
		int carry = 0;
		for (auto& i : ok)
		{
			i += carry;
			carry = i / 10;
			i %= 10;
		}
		while (carry)
		{
			ok.push_back(carry % 10);
			carry /= 10;
		}
		return ok;
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	if (n == 0)
	{
		cout << 1;
		return 0;
	}
	function<vector<int>(int, int)> dfs = [&](int left, int right)
		{
			if (left == right)
			{
				vector<int>temp;
				int x = left;
				while (x)
				{
					temp.push_back(x % 10);
					x /= 10;
				}
				return temp;
			}
			int mid = (left + right) >> 1;
			auto L = dfs(left, mid);
			auto R = dfs(mid + 1, right);
			Convolution res(L, R);
			vector<int>ok = res.solve();
			while (!ok.back())
			{
				ok.pop_back();
			}
			return ok;
		};
	vector<int>ans = dfs(1, n);
	int len = ans.size();
	for (int i = len - 1; i >= 0; --i)
	{
		cout << ans[i];
	}
	return 0;
}