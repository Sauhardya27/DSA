#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	int st = 0, e = s.size() - 1;
	while (st < e)
	{
		if ((s[st] >= 'a' && s[st] <= 'z') || (s[st] >= '0' && s[st] <= '9'))
		{
			if ((s[e] >= 'a' && s[e] <= 'z') || (s[e] >= '0' && s[e] <= '9'))
			{
				if (s[st] == s[e])
				{
					st++;
					e--;
				}
				else
					return false;
			}
			else
			{
				e--;
			}
		}
		else
		{
			if ((s[e] >= 'a' && s[e] <= 'z') || (s[e] >= '0' && s[e] <= '9'))
			{
				st++;
			}
			else
			{
				st++;
				e--;
			}
		}
	}
	return true;
}