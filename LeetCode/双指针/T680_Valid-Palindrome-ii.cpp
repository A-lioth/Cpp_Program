#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int left, int right)
{
    while (left < right)
        if (s[left++] != s[right--])
            return false;
    return true;
}

bool validPalindrome(string s)
{
    for (int left = 0, right = s.size() - 1; left < right; left++, right--)
        if (s[left] != s[right])
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    return true;
}

int main()
{
    string s = "abcdeca";
    cout << validPalindrome(s) << endl;
    return 0;
}