#include "Stack.hpp"

int main()
{
	Stack<int> i;
	i.push(5);
	i.push(56);
	i.push(3);

	Stack<int> ii = i;
	ii.print();

	/*i.print();

	i.pop();
	i.print();
*/
}