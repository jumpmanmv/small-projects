#include <algorithm>
#include <string>

bool anagram_check(std::string s1, std::string s2)
{
    if (s1.size() != s2.size()) return false;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
}