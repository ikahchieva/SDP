#include"LList.hpp"

int main()
{
	List<int> i;
	i.pushBack(5);
	i.pushBack(6);
	i.pushFront(4);
	i.print();
	cout << i.search(4) << " " << i.search(3) << endl;
	try{
		i.popBack();
		i.popBack();
		i.popBack();
		i.popBack();
	}
	catch (char * e)
	{
		cout << e << endl;
	}
}