#include <bits/stdc++.h>

using namespace std;

string check(string s, int &n)
{
    int t = 1;
    int maxt = 0;
    int maxfirstIndex = 0;
    int maxEndIndex = 0;
    int firstIndex = 0;
    int lastStrF = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            string lastStr = s.substr(lastStrF, i - lastStrF);
            int u = 1;
            while (islower(s[i + u]))
            {
                u++;
            }
            string nowStr = s.substr(i, u--);
            if (lastStr < nowStr)
            {
                if (lastStr.length() != 0)
                    t++;
            }
            else
            {
                if (t > maxt)
                {
                    maxt = t;
                    maxfirstIndex = firstIndex;
                    maxEndIndex = i - 1;
                }
                t = 1;
                firstIndex = i;
            }
            lastStrF = i;
        }
    }
    if (t > maxt)
    {
        maxt = t;
        maxfirstIndex = firstIndex;
        maxEndIndex = s.length() - 1;
    }
    n = maxt;
    return s.substr(maxfirstIndex, maxEndIndex - maxfirstIndex + 1);
}
int main()
{
    string s;
    int n;
    cin >> s;
    cout << check(s, n);
    return 0;
}