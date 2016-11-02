#include "STACK.hpp"

int total( char* exp)
{
	char *p = exp;
	Stack<int> stack;
	int first, second, total;

	while (*p != '\0')
	{
		if (*p >= '0' && *p <= '9')
			stack.push(*p - '0');
		else
		{
			first = stack.peek();
			stack.pop();
			second = stack.peek();
			stack.pop();
			switch (*p)
			{
			case '+':total = first + second;
				break;
			case '-':total = second - first;
				break;
			case '*': total = first*second;
				break;
			case '/':total = second / first;
				break;
			default:
				break;
			}
			stack.push(total);
		}
		*p++;
	}
	return stack.peek();

}


int main()
{
	char exp[] = "54+7*";
	
	cout << total(exp) << endl;
	
}
