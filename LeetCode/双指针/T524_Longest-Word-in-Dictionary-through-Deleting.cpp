#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findLongestWord(string s, vector<string> &dictionary)
{
}

int main()
{
    string s = "abpcplea";
    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
    cout << findLongestWord(s, dictionary) << endl;
    return 0;
}