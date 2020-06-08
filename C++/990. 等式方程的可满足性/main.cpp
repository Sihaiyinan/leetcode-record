// 990. 等式方程的可满足性

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class UF
{
private:
    int count;     // 分组个数
    vector<int> parent;   // 存放当前结点的父结点
    vector<int> size;     // 存放当前结点的个数

public:
    UF(int n)
    {
        this->count = n;           // 开始结点互不连通
        parent.assign(n, 0);   // 初始状态下每个结点的父结点是其本身
        size.assign(n, 1);     // 初始状态下每个结点的结点数是1
        for (int i = 0; i < n; ++i)  parent[i] = i;
    }

    /**
     * 返回某个结点的根结点
     */
    int _find(int x)
    {
        while (parent[x] != x)
        {
            // 进行路径压缩，使当前结点的父结点变成当前结点的父结点的父结点
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    /**
     * 将两个结点合并
     */
    void _union(int p, int q)
    {
        int rp = _find(p);
        int rq = _find(q);
        if (rp == rq) return;

        // 较小的树接到较大的树后面，以保持平衡
        if (size[rp] > size[rq])
        {
            parent[rq] = rp;
            size[rp] += size[rq];
        } else
        {
            parent[rp] = rq;
            size[rq] += size[rp];
        }
        --count;
    }

    /**
     * 判断两个结点是否连通
     */
    bool _connected(int p, int q)
    {
        int rp = _find(p);
        int rq = _find(q);
        return rp == rq;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);

        for (string &str : equations)
        {
            if (str[1] == '=')
            {
                int a = str[0] - 'a';
                int b = str[3] - 'a';
                uf._union(a, b);
            }
        }

        for (string &str : equations)
        {
            if (str[1] == '!')
            {
                int a = str[0] - 'a';
                int b = str[3] - 'a';
                if (uf._connected(a, b)) return false;
            }
        }
        return true;
    }
};


int main()
{
    return 0;
}