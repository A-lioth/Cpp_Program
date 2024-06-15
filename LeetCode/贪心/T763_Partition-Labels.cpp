#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> partitionLabels(string s)
{
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