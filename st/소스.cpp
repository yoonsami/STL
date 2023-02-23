#include "PCH.h"
//#include "MyVector.h"
//#include "MyList.h"
#include <queue>
#include "MyQueue.h"

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

	MyQueue<int> q;
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
	}

	return 0;
}
