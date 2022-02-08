#include <bits/stdc++.h>
using namespace std;

template<class Object>
class persistent_avl
{
	struct AVLNode
	{
		Object data;
		int count;
		int size;
		AVLNode* lchild;
		AVLNode* rchild;
		int height;
		AVLNode(const Object& x)
		{
			data = x;
			count = 1;
			size = 1;
			lchild = NULL;
			rchild = NULL;
			height = 0;
		}
		AVLNode(const AVLNode& x)
		{
			data = x.data;
			count = x.count;
			size = x.size;
			lchild = x.lchild;
			rchild = x.rchild;
			height = x.height;
		}
	};

	int sizeOf(AVLNode* T)
	{
		if (T == NULL)
			return 0;
		else return T->size;
	}

	int heightOf(AVLNode* T)
	{
		if (T == NULL)
			return -1;
		else return T->height;
	}

	void rotateLeft(AVLNode*& T)
	{
		AVLNode* k = T->rchild;
		T->rchild = k->lchild;
		k->lchild = T;
		T->height = max(heightOf(T->lchild), heightOf(T->rchild)) + 1;
		k->height = max(heightOf(k->lchild), heightOf(k->rchild)) + 1;
		T->size = sizeOf(T->lchild) + sizeOf(T->rchild) + T->count;
		k->size = sizeOf(k->lchild) + sizeOf(k->rchild) + k->count;
		T = k;
	}

	void rotateRight(AVLNode*& T)
	{
		AVLNode* k = T->lchild;
		T->lchild = k->rchild;
		k->rchild = T;
		T->height = max(heightOf(T->lchild), heightOf(T->rchild)) + 1;
		k->height = max(heightOf(k->lchild), heightOf(k->rchild)) + 1;
		T->size = sizeOf(T->lchild) + sizeOf(T->rchild) + T->count;
		k->size = sizeOf(k->lchild) + sizeOf(k->rchild) + k->count;
		T = k;
	}

	void doubleRotateLeft(AVLNode*& T)
	{
		AVLNode* k1 = T->rchild, * k2 = k1->lchild;
		T->rchild = k2->lchild;
		k2->lchild = T;
		k1->lchild = k2->rchild;
		k2->rchild = k1;
		T->height = max(heightOf(T->lchild), heightOf(T->rchild)) + 1;
		k1->height = max(heightOf(k1->lchild), heightOf(k1->rchild)) + 1;
		k2->height = max(heightOf(k2->lchild), heightOf(k2->rchild)) + 1;
		T->size = sizeOf(T->lchild) + sizeOf(T->rchild) + T->count;
		k1->size = sizeOf(k1->lchild) + sizeOf(k1->rchild) + k1->count;
		k2->size = sizeOf(k2->lchild) + sizeOf(k2->rchild) + k2->count;
		T = k2;
	}

	void doubleRotateRight(AVLNode*& T)
	{
		AVLNode* k1 = T->lchild, * k2 = k1->rchild;
		T->lchild = k2->rchild;
		k2->rchild = T;
		k1->rchild = k2->lchild;
		k2->lchild = k1;
		T->height = max(heightOf(T->lchild), heightOf(T->rchild)) + 1;
		k1->height = max(heightOf(k1->lchild), heightOf(k1->rchild)) + 1;
		k2->height = max(heightOf(k2->lchild), heightOf(k2->rchild)) + 1;
		T->size = sizeOf(T->lchild) + sizeOf(T->rchild) + T->count;
		k1->size = sizeOf(k1->lchild) + sizeOf(k1->rchild) + k1->count;
		k2->size = sizeOf(k2->lchild) + sizeOf(k2->rchild) + k2->count;
		T = k2;
	}

	void balance(AVLNode*& T)
	{
		if (T == NULL)
			return;
		if (abs(heightOf(T->lchild) - heightOf(T->rchild)) > 1)
		{
			if (heightOf(T->lchild) > heightOf(T->rchild))
			{
				if (heightOf(T->lchild->lchild) > heightOf(T->lchild->rchild))
					rotateRight(T);
				else doubleRotateRight(T);
			}
			else
			{
				if (heightOf(T->rchild->rchild) > heightOf(T->rchild->lchild))
					rotateLeft(T);
				else doubleRotateLeft(T);
			}
		}
		T->height = max(heightOf(T->lchild), heightOf(T->rchild)) + 1;
	}

	int findMin(AVLNode* T)
	{
		if (T->lchild == NULL)
			return T->data;
		else return findMin(T->lchild);
	}

	int findMax(AVLNode* T)
	{
		if (T->rchild == NULL)
			return T->data;
		else return findMin(T->rchild);
	}

	void insert(AVLNode*& T, const Object& x)
	{
		if (T == NULL)
			T = new AVLNode(x);
		else
		{
			if (x > T->data)
			{
				if (T->rchild)
					T->rchild = new AVLNode(*(T->rchild));
				insert(T->rchild, x);
			}
			else if (x < T->data)
			{
				if (T->lchild)
					T->lchild = new AVLNode(*(T->lchild));
				insert(T->lchild, x);
			}
			else T->count++;
			T->size++;
			balance(T);
		}
	}

	bool find(AVLNode* T, const Object& k)
	{
		if (T == NULL)
			return false;
		else
		{
			if (k < T->data)
				return find(T->lchild, k);
			else if (k > T->data)
				return find(T->rchild, k);
			else return true;
		}
	}
	Object kth(AVLNode* T, int k)
	{
		if (k <= sizeOf(T->lchild))
			return kth(T->lchild, k);
		else if (k > sizeOf(T->lchild) + T->count)
			return kth(T->rchild, k - sizeOf(T->lchild) - T->count);
		else return T->data;
	}

	vector<AVLNode*> roots;
public:
	void insert(const Object& x);
	bool find(const Object& k, int it) { return find(roots[it], k); }
	Object kth(int k, int it) { return kth(roots[it], k); }
	int size(int it) { return sizeOf(roots[it]); }
	int height(int it) { return heightOf(roots[it]); }
	int iters() { return roots.size(); }

};

template<class Object>
void persistent_avl<Object>::insert(const Object& x)
{
	if (roots.size() == 0)
	{
		roots.push_back(new AVLNode(x));
		return;
	}
	roots.push_back(new AVLNode(*roots[roots.size() - 1]));
	insert(roots[roots.size() - 1], x);
}

int main() {
	int x;
	cin >> x;
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	persistent_avl<int> s;
	for (int i = 0; i < n; i++)
		s.insert(a[i]);
	int preans = 0;
	while (q--)
	{
		int k, l;
		cin >> k >> l;
		if (x)
		{
			k = (k ^ preans);
			l = (l ^ preans);
		}
		preans = s.kth(k, l - 1);
		cout << preans << "\n";
	}
}