// 146. LRU缓存机制

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;


struct Value
{
	int value;
	list<int>::iterator iter;

	Value(int v, list<int>::iterator it) : value(v), iter(it) {}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		m_capacity = capacity;
		m_hash.reserve(capacity * 2); //减少rehash
	}

	int get(int key) {
		std::unordered_map<int, Value>::iterator iter = m_hash.find(key);
		if (iter != m_hash.end()) //找到了
		{
			//将该链表节点移动到链表头节点
			m_list.splice(m_list.begin(), m_list, iter->second.iter);

			return iter->second.value;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) {

		std::unordered_map<int, Value>::iterator iter = m_hash.find(key);
		if (iter != m_hash.end()) //找到了
		{
			//将该链表节点移动到链表头节点
			m_list.splice(m_list.begin(), m_list, iter->second.iter);

			iter->second.value = value;
		}
		else //没找到
		{
			if (m_hash.size() == m_capacity) //缓存满了
			{
				//缓存淘汰           
				m_hash.erase(m_list.back()); //hash删除该尾结点的键值对
				m_list.pop_back(); //删除尾结点
			}
			m_list.push_front(key); //在链表头插入新节点
			Value v(value, m_list.begin());
			m_hash.insert(pair<int, Value>(key, v)); //hash插入
		}
	}


private:
	unordered_map<int, Value> m_hash;
	list<int> m_list; //存key
	int m_capacity;
};

int main()
{

	return 0;
}