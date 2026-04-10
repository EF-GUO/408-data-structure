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
	bool is_bracket_matched(const char* str, const int size)
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


	/*
	*	后缀表达式求值
	*/
	double evaluate_postfix_expression(const char *expr, const int size)
	{
		if(!expr || size <= 0) return 0;

		double *stack = new double[size];
		int top = -1;

		for(int i = 0; i < size; ++i)
		{
			char ch = expr[i];
			if(ch == '/0') break;
			if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if(top < 1) break;
				double right = stack[top--];
				double left = stack[top--];
				switch(ch)
				{
				case '+':
					stack[++top] = left + right;
					break;
				case '-':
					stack[++top] = left - right;
					break;
				case '*':
					stack[++top] = left * right;
					break;
				case '/':
					if(right == 0)
					{
						delete[] stack;
						return 0;
					}
					stack[++top] = left / right;
					break;
				}
			}			
			else if(ch >= '0' <= '9')
				stack[++top] = double(ch-'0');
			// ch是字符，存储的是ASCII码
			else
			{
				//非法字符
				delete[] stack;
				return 0;
			}
		}

		if(top != 0)
		{
			delete[] stack;
			return 0;
		}

		double result = stack[top--];
		delete[] stack;
		return result;
	}


	/*
	*	中缀表达式转后缀表达式
		核心思想是用一个 运算符栈：
			遇到数字：		直接输出到后缀表达式
			遇到左括号 '('：	直接入栈
			遇到右括号 ')'：	一直弹栈，直到遇到左括号
			遇到运算符:		把栈中 优先级大于等于当前运算符 的运算符先弹出来，再把当前运算符入栈
	*/
	char* infix_to_postfix(const char* expr, const int size)
	{
		if(!expr || size <= 0) return nullptr;

		auto precedence = [](char op)
		{
			if(op == '+' || op == '-') return 1;
			else if(op == '*' || op == '/') return 2;
			return 0;
		};
		auto is_digit = [](char ch) ->bool{ return ch >= '0' && ch <= '9';};
		auto is_op = [](char ch) ->bool{ return ch == '+' || ch =='-' || ch == '*' || ch == '/'; };

		char *stack = new char[size];
		char *result = new char[size + 1];
		int top = -1;
		int res_index = 0;

		for(int i = 0; i < size; ++i)
		{
			char expr_ch = expr[i];
			if(is_digit(expr_ch))
				result[res_index++] = expr_ch;
			else if(expr_ch == '(')
				stack[++top] = expr_ch;
			else if(expr_ch == ')')
			{
				while(top >= 0 && stack[top] != '(')
					result[res_index++] = stack[top--];
				if(top >= 0) 
					--top;
				else //没有对应的'('匹配
				{
					delete[] stack;
					delete[] result;
					return nullptr;
				}
			}
			else if(is_op(expr_ch))
			{//遇到运算符
				while(top >= 0 && stack[top] != '(' 
					&& precedence(stack[top]) >= precedence(expr_ch))
					result[res_index++] = stack[top--];
				stack[++top] = expr_ch;
			}
			else
			{//遇到非法字符
				delete[] stack;
				delete[] result;
				return nullptr;
			}
		}

		while(top >= 0)
		{
			if (stack[top] == '(')	//如情况: (3+4
	        {
	            delete[] stack;
	            delete[] result;
	            return nullptr;   // 括号不匹配
	        }
			result[res_index++] = stack[top--];
		}
		result[res_index] = '\0';
		delete[] stack;
		return result;
	}



}







