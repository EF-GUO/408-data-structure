#pragma once


/*
* 3.3小节栈的应用
*/
namespace stack_apps
{




	/*
	*	栈的应用：括号匹配
	*	匹配括号类型：()、[]、{}
	*/
	bool isBracketMatched(const char* str, const int size)
	{
		if (!str || size < 0) return false;
		char* stack = new char[size];
		int top = -1;

		for (int i = 0; i < size; ++i)
		{
			//如果是左侧括号，直接入栈
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				stack[++top] = str[i];
			//如果是右侧括号，则和栈顶括号做匹配
			else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
			{
				//如果匹配的时候，栈空了，则匹配失败
				if(top == -1) 
				{
					delete[] stack;
					return false;
				}

				char stack_top = stack[top--];
				if(!(
					(stack_top == '(' && str[i] == ')') ||
					(stack_top == '[' && str[i] == ']') ||
					(stack_top == '{' && str[i] == '}')
					))
				{
					delete[] stack;
					return false;
				}
				
			}
			/*
			*	如果匹配字符只运行出现括号，就不能省略
			*	如果括号之间能有其他的字符，可以省略
			*/
			else
			{
				delete[] stack;
				return false;
			}
		}
		delete[] stack;
		return top == -1;
	}







}







