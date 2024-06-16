#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> partitionLabels(string s)
{
    vector<int> res;
    if (s.empty())
    {
        return res;
    }

    vector<int> last(26);
    // 记录每个字符最后出现的位置
    for (int i = 0; i < s.size(); i++)
    {
        last[s[i] - 'a'] = i;
    }

    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        end = max(end, last[s[i] - 'a']);
        if (i == end)
        {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}

int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}