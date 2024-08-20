#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> count;
    for (char c : t)
        count[c]++;

    int left = 0, right = 0, cnt = t.size();
    int min_len = s.size() + 1, min_left = 0;
    for (right = 0; right < s.size(); right++)
    {
        if (--count[s[right]] >= 0)
            cnt--;
        while (cnt == 0)
        {
            if (right - left + 1 < min_len)
            {
                min_len = right - left + 1;
                min_left = left;
            }
            if (++count[s[left]] > 0)
                cnt++;
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