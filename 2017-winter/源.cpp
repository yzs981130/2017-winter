#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 3000100
int p[MAXN];
string pre(const string &str)
{
	string s;
	s.push_back('$');
	s.push_back('#');
	for(int i = 0; i < str.length(); i++)
	{
		s.push_back(str[i]);
		s.push_back('#');
	}
	s.push_back('^');
	return s;
}
int main()
{
	int cnt;
	cin >> cnt;
	string str;
	while(cnt--)
	{
		cin >> str;
		string s = pre(str);
		memset(p, 0, sizeof(p));
		int mx = 0, id = 0;
		for(int i = 1; s[i] != '\0'; i++)
		{
			p[i] = mx > i ? min(p[(id << 1) - i], mx - i) : 1;
			while (s[i + p[i]] == s[i - p[i]])
				p[i]++;
			if(i + p[i] > mx)
			{
				mx = i + p[i];
				id = i;
			}
		}
		int ans = 0;
		for (int i = 0; i < MAXN; i++)
			if (p[i] > ans)
				ans = p[i];
		cout << ans - 1 << endl;
	}
	system("pause");
	return 0;
}