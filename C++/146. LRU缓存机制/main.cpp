// LRU (Least Recently Used)缓存机制

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <ctime>
#include <unordered_map>


using namespace std;

// 方法一
class LRUCache1 {
public:
    long long int l = 0;   // 最新次数，每次调用该数值加一，容器中数值最低的表示最少使用
    int cap;   // 容器大小
    map<int, pair<int, int>> m;   // map<key, pair<val, level>>

    LRUCache1(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;   // 如果不存在返回-1，否则更新key对应的level
        m[key].second = ++l;
        return m[key].first;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end())   // 如果key已经存在，更新key对应的val和level
        {
            m[key] = make_pair(value, ++l);
            return;
        }
        if (m.size() < cap)   // 如果小于容量值，添加key对应的值，否则找出level最小的删除
        {
            m[key] = make_pair(value, ++l);
        } else
        {
            auto t = m.begin();
            for (auto it = m.begin(); it != m.end(); ++it)
            {
                if (it->second.second < t->second.second)
                {
                    t = it;
                }
            }
            m.erase(t);
            m[key] = make_pair(value, ++l);
        }
    }
};


struct DeListNode
{
    int key, val;
    DeListNode *prev, *next;
    DeListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DeListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    unordered_map<int, DeListNode*> m;
    DeListNode *head, *tail;
    int size;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new DeListNode();
        tail = new DeListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!m.count(key)) return -1;
        DeListNode *tmp = m[key];
        move_to_head(tmp);
        return tmp->val;
    }

    void put(int key, int value) {
        if (m.count(key))
        {
            DeListNode *tmp = m[key];
            tmp->val = value;
            move_to_head(tmp);
            return;
        }

        DeListNode *node = new DeListNode(key, value);
        m[key] = node;
        add_to_head(node);
        ++size;
        if (size > cap)
        {
            DeListNode *re = remove_tail();
            m.erase(re->key);
            --size;
        }
    }

    void add_to_head(DeListNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void remove_node(DeListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void move_to_head(DeListNode *node)
    {
        remove_node(node);
        add_to_head(node);
    }

    DeListNode *remove_tail()
    {
        DeListNode *tmp = tail->prev;
        remove_node(tmp);
        return tmp;
    }
};



int main()
{
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << obj->get(2) << endl;
    obj->put(4,4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;


    return 0;
}



