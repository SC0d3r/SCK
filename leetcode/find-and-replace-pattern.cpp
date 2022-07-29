#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution
{
public:
  std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string pattern)
  {
    std::vector<std::string> res;

    for (auto word : words)
    {
      if (pattern.size() != word.size())
        continue;
      std::map<char, char> m;
      bool didMatch = true;
      for (int i = 0; i < pattern.size(); i++)
      {
        auto letter = pattern[i];
        auto mapTo = word[i];
        if (m.find(letter) == m.end())
        {
          // not found
          // if mapTo already exist as value in map its error
          for (auto [key, val] : m)
          {
            if (val == mapTo)
              didMatch = false;
          }

          m[letter] = mapTo;
        }
        else
        {
          // found
          if (m[letter] != mapTo)
          {
            didMatch = false;
            // error
          }
        }
      }
      if (didMatch)
      {
        res.push_back(word);
      }
    }

    return res;
  }
};

// int main()
// {
//   Solution s;
//   std::cout << "hello world to your" << std::endl;
//   std::vector<std::string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
//   std::string pattern = "abb";
//   auto res = s.findAndReplacePattern(words, pattern);
//   std::cout << "matched words are: ";
//   for (auto word : res)
//   {
//     std::cout << word << ", ";
//   }
//   std::cout << "\n";
//   return 0;
// }
