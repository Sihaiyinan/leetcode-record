// 547. 朋友圈

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class UF
{
private:
	int count;
	int *parent;
	int *size;

public:
	UF(int n)
	{
		this->count = n;
		parent = new int[n];
		size = new int[n];

		for (int i = 0; i < n; ++i)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}

	int _find(int x)
	{
		while (parent[x] != x)
		{
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	int _count()
	{
		return count;
	}

	void _union(int p, int q)
	{
		int root_p = _find(p);
		int root_q = _find(q);

		if (root_p == root_q)
			return;

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
