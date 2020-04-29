// 并查集
// Leetcode 547. 朋友圈

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class UF
{
private:
	int count;     // 分组个数
	int *parent;   // 存放当前结点的父结点
	int *size;     // 存放当前结点的个数

public:
	UF(int n)
	{
		this->count = n;         // 开始结点互不连通
		parent = new int[n];     // 初始状态下每个结点的父结点使其本身
		size = new int[n];       // 每个结点的结点数是1

		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}

	// 返回某个结点的根结点
	int _find(int x)
	{
		while (parent[x] != x)
		{
			// 进行路径压缩，使树的高度保持为常数
			parent[x] = parent[parent[x]];  
			x = parent[x];
		}
		return x;
	}

	// 	返回当前的连通分量
	int _count()
	{
		return count;
	}

	// 将两个结点合并
	void _union(int p, int q)
	{
		int root_p = _find(p);
		int root_q = _find(q);

		if (root_p == root_q)
			return;

		// 较小的树接到较大的树后面，以保持平衡
		if (size[root_p] > size[root_q])
		{
			parent[root_q] = root_p;
			size[root_p] += size[root_q];
		}
		else
		{
			parent[root_p] = root_q;
			size[root_q] += size[root_p];
		}
		count--;
	}

	bool _connected(int p, int q)
	{
		int root_p = _find(p);
		int root_q = _find(q);
		return root_p == root_q;
	}
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		UF uf = UF(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (M[i][j] == 1)
					uf._union(i, j);
			}
		}
		return uf._count();
	}
};


int main()
{

	return 0;
}
