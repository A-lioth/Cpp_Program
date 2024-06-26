#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findLongestWord(string s, vector<string> &dictionary)
{
    sort(dictionary.begin(), dictionary.end(), [](string &a, string &b)
         {
            if(a.length() == b.length()) return a < b;
            return a.length() > b.length(); });

    for (string ds : dictionary)
    {
        if (ds.length() > s.length())
            continue;
        int i = 0, j = 0;
        while (i < s.length() && j < ds.length())
        {
            if (s[i] == ds[j])
                j++;
            i++;
            if (j == ds.length())
                return ds;
        }
    }
    return "";
}

int main()
{
    string s = "abpcplea";
    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
    cout << findLongestWord(s, dictionary) << endl;
    return 0;
}