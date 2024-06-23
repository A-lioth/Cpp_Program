#include <iostream>
#include <string>
#include <vector>

using namespace std;

string minWindow(string s, string t)
{
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    for (char c : t)
    {
        flag[c] = true;
        chars[c]++;
    }

    int left = 0, right = 0, count = 0;
    int min_len = s.size() + 1, min_left = 0, min_right = 0;

    for (right = 0; right < s.size(); right++)
    {
        if (flag[s[right]])
        {
            if (--chars[s[right]] >= 0)
                count++;
        }
        while (count == t.size())
        {
            if (right - left + 1 < min_len)
            {
                min_len = right - left + 1;
                min_left = left;
                min_right = right;
            }
            if (flag[s[left]] && ++chars[s[left]] > 0)
                count--;
            left++;
        }
    }

    return min_len > s.size() ? "" : s.substr(min_left, min_len);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}