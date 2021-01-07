// test for checking if two strings are anagrams of each other
#include <iostream>
#include <string>
#include "anagram_check.hpp"

int main()
{
    std::string s1;
    std::string s2;

    std::cout << "Give first string: ";
    std::getline(std::cin, s1);
    std::cout << "Give second string: ";
    std::getline(std::cin, s2);

    if (anagram_check(s1, s2)) std::cout << "\nThe two strings are anagrams!";
    else std::cout << "\nThe two strings aren't anagrams!";

    return 0;
}