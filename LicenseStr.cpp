/* 
 Problem #4: License Key Formatting

 You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
 We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
 Return the reformatted license key.
 
 Example 1:
 Input: s = "5F3Z-2e-9-w", k = 4
 Output: "5F3Z-2E9W"
 Explanation: The string s has been split into two parts, each part has 4 characters.
 Note that the two extra dashes are not needed and can be removed.

 Example 2:
 Input: s = "2-5g-3-J", k = 2
 Output: "2-5G-3J"
 Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <regex>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout << "You passed in only " << argc << "argument(s). 3 is needed" << endl;
    }

    string s = argv[1];
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    const size_t k = stoi(argv[2]);

    std::regex re("-");
    string result = std::regex_replace(s, re, "");

    const size_t first_n = result.length() % k;
    const size_t n = result.length() / k;

    string s1 = result.substr(0, first_n);
    string s2 = result.substr(first_n, result.length());

    vector<string> strings;

    for (int i = 0; i < n; ++i)
    {
        strings.push_back(s2.substr(i * k, i * k + k));
    }

    string str_result = accumulate(begin(strings), end(strings), string(),
        [](string& ss, string& s)
        {
            return ss.empty() ? s : ss + "-" + s;
        });

    if (first_n > 0)
        cout << s1 + '-' + str_result << endl;
    else
        cout << str_result << endl;
}
