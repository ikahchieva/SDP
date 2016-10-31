#include "Stack.hpp"
#include<fstream>

char leftbraces[] = { '(', '[', '{' };
char rightbraces[] = { ')', ']', '}' };


bool checkExpression(ifstream& f, Stack<char>& stack)
{
	char ch;
	f >> ch;
	while (!f.eof())
	{
		for (int i = 0; i < 3; i++)
		{
			if (ch == leftbraces[i])
				stack.push(ch);
			else {
				if (ch == rightbraces[i])
				{
					if (stack.isEmpty())
					{
						return false;
					}
					if (stack.peek() == leftbraces[i])
					{
						stack.pop();
					}
					else return false;
				}
			}
		}
		f >> ch;
	}
	return !stack.isEmpty()? false: true;
}

int main()
{
	ifstream file("f.txt");
	Stack<char> stack;
	cout << checkExpression(file, stack) << endl;

}
