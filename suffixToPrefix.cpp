/*
	convert a postfix expresion 
    to a prefix expresion
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;
// check operators
bool isOperator(char x)
{
	switch (x)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	}
	return false;
}
// convert suffix expression to prefix
string postToPre(string exp_post)
{
	stack<string> s;
	int length = exp_post.size();

	for (int i = 0; i <= length - 1; i++)
	{
		if (!(isOperator(exp_post[i])))
		{
		    s.push(string(1, exp_post[i]));
		}
		else
		{
            string operand1 = s.top();
			s.pop();
			string operand2 = s.top();
			s.pop();

			string temp = exp_post[i] + operand2 + operand1;
			s.push(temp);
		}
	}
	return s.top();
}

int main()
{
	string t, test = "AB+CD-/";
	cout << "Converted expresion to prefix is:";
	t = postToPre(test);
	cout<<t;
	cin.get();
	return 0;
}
