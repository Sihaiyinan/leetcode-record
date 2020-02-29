// 面试题35. 复杂链表的复制

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 用map将旧的链表结点和新的链表结点对应起来
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        map<Node*, Node*> m;
        Node *re = new Node(0);
        Node *ptr = re, *old_ptr = head;
        while (old_ptr)
        {
            ptr->next = new Node(old_ptr->val);
            m[old_ptr] = ptr->next;
            old_ptr = old_ptr->next;
            ptr = ptr->next;
        }
        ptr = re->next;
        while (head)
        {
            ptr->random = m[head->random];
            ptr = ptr->next;
            head = head->next;
        }
        ptr = re->next;
        delete re;
        return ptr;
    }
};

int main() {



    std::cout << std::endl;
    return 0;
}
