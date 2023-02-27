#include "PCH.h"
//#include "MyVector.h"
//#include "MyList.h"
//#include "MyQueue.h"

int main()
{
	/*MyVector<int> myV;


	for (int i = 0; i < 100; ++i)
	{
		myV.Push_back(i);
		cout << myV.Size() << " " << myV.Capacity() << endl;
	}

	for (size_t i = 0; i < myV.Size(); ++i)
	{
		cout << myV[i] << endl;
	}

	for (MyVector<int>::Iterator it = myV.Begin(); it != myV.End(); ++it)
	{
		cout << *it << endl;
	}*/

	/*MyList<int> li;
	MyList<int>::Iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.Insert(li.End(), i);
		}
		else
		{
			li.Push_back(i);
		}
	}

	li.Pop_back();

	li.erase(eraseIt);

	for (MyList<int>::Iterator it = li.Begin(); it != li.End(); ++it)
	{
		cout << (*it) << endl;
	}*/

	/*MyQueue<int> q;
	for (int i = 0; i < 10; i++)
	{
		q.push(i);
		if(!q.empty())
			cout << "front : " << q.front() << "\tback : " << q.back() <<"\tsize : " << q.size() << endl;
	}
	cout << "======================================" << endl;
	for (int i = 0; i < 10; i++)
	{
		q.pop();
		if (!q.empty())
			cout << "front : " << q.front() << "\tback : " << q.back() << "\tsize : " << q.size() << endl;
	}*/

	vector<int> v;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 100; ++i)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// 1) Ư�� int�� �����ϴ� �� Ȯ���ϴ� ��� (bool ��ȯ, ù �����ϴ� iter ��ȯ)
	{
		int value = 50;
		bool found = false;
		vector<int>::iterator foundit = v.end();

		// 1. v[i] ������ ����
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == value)
			{
				found = true;
				foundit = v.begin() + i;
				break;
			}
		}
		// 2. iterator �� ����
		for (auto it = v.begin();it != v.end(); ++it)
		{
			if (*it == value)
			{
				found = true;
				foundit = it;
				break;
			}
		}
		// 3. STL find
		foundit = find(v.begin(), v.end(), value);
		if (foundit == v.end())
			cout << "����" << endl;
		else
			cout << "ã��" << endl;
	}

	// 2) Ư�� int �� ������ ���� �����ϴ��� Ȯ���ϴ� ���
	{
		int value = 11;
		bool found = false;
		vector<int>::iterator foundit = v.end();

		// 1. v[i] ������ ����
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i]% value == 0)
			{
				found = true;
				foundit = v.begin() + i;
				break;
			}
		}
		// 2. iterator �� ����
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			if (*it % value == 0)
			{
				found = true;
				foundit = it;
				break;
			}
		}
		
		// 3. STL find_if
		foundit = find_if(v.begin(), v.end(), [](int n) {return n % 11 == 0; });
		if (foundit == v.end())
			cout << "����" << endl;
		else
			cout << "ã��" << endl;
	}

	// 3) Ȧ���� ����
	{
		int iCount = 0;
		// 1. v[i] ������ ����
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] % 2 == 1)
			{
				iCount++;
			}
		}
		// 2. iterator �� ����
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			if (*it % 2 == 1)
			{
				iCount++;
			}
		}
		// 3. STL count_if
		int count = static_cast<int>(count_if(v.begin(), v.end(), [](int n) {return n % 2 != 0; }));

		bool b1 = all_of(v.begin(), v.end(), [](int n) {return n % 2 != 0; }); // ��� �����ϸ� true �ƴϸ� false
		bool b2 = any_of(v.begin(), v.end(), [](int n) {return n % 2 != 0; }); // �ϳ��� �����ϸ� true �ƴϸ� false
		bool b3 = none_of(v.begin(), v.end(), [](int n) {return n % 2 != 0; }); // �ϳ��� �������� ������ true �ϳ��� ������ false
		
	}


	// 4) ���� ���� ��� ���ڿ� 3�� ����
	{
		// 1. v[i] ������ ����
		for (int i = 0; i < v.size(); ++i)
		{
			v[i] *= 3;
		}
		// 2. iterator �� ����
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			*it *= 3;
		}

		// 3. STL for_each
		for_each(v.begin(), v.end(), [](int& n) {n = n * 3;});
	}

	// 5) Ȧ���� ������ �ϰ� ����
	{
		// 1. iterator�� ����
		for (auto it = v.begin(); it != v.end(); )
		{
			if ((*it % 2) != 0)
			{
				it = v.erase(it);
			}
			else
				it++;
		}
		/*template<class ForwardIt, class UnaryPredicate>
		ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
		{
			first = std::find_if(first, last, p);
			if (first != last)
				for (ForwardIt i = first; ++i != last;)
					if (!p(*i))
						*first++ = std::move(*i);
			return first;
		}*/
		vector<int>::iterator it = remove_if(v.begin(), v.end(), [](int n) {return n % 2 != 0; }); 
		// --> ���ܵ־� �� �ֵ��� ������ �����, �ڿ� �ִ°� ������ ����.
		v.erase(it, v.end());
		// --> ���������.
	}
	return 0;
}
