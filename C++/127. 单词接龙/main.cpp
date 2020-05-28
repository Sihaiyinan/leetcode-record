// 127. 单词接龙

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.empty() || endWord.empty() || wordList.empty()) return 0;

        map<string, vector<string>> m;

        // 获得wordList中所有字符串的匹配模式和对应的字符串
        // "*og" : "dog", "log", "cog"
        for (const auto& i : wordList)
        {
            for (int j = 0; j < i.size(); ++j)
            {
                string t = i;
                t.replace(j, 1, "*");
                m[t].push_back(i);
            }
        }

        queue<pair<string, int>> q;
        q.push({ beginWord, 1 });
        map<string, int> visited;   // 判断当前字符串是否被访问过，防止死循环
        visited[beginWord] = 1;

        while (!q.empty())
        {
            auto s = q.front().first;
            int level = q.front().second;
            q.pop();

            // 循环获得当前字符串所有的匹配模式
            for (int i = 0; i < s.size(); ++i)
            {
                string cur_str = s;
                cur_str.replace(i, 1, "*");

                // 判断当前匹配模式是否在map中， 如果map中当前匹配模式对应的字符串等于endWord，直接返回
                // 如果map中当前匹配模式对应的字符串没有被访问过，将其加入到队列中
                for (const auto& word : m[cur_str])
                {
                    if (word == endWord)
                        return level + 1;
                    if (visited.find(word) == visited.end())
                    {
                        visited[word] = 1;
                        q.push({ word, level + 1 });
                    }
                }
                // 因为有visited，这一句可以不用
//                m[cur_str].clear();
            }
        }
        return 0;
    }
};


int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}