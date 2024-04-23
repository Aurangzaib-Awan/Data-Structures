//this is a code in c++ to check if the given string is palindrome or not and i have done it by manually making a stack through linklist and then by simply dividing the //string into 2 parts then by comparing them . I just store the first half in stack and then when i pop it , it is automaticallly reversed bcoz of the the lifo property of //stack. In case of odd palindrome just ignore the middle element .

#include<iostream>
using namespace std;
class Node {
public:
	char val;
	Node* nxt;
	Node(char c) :val(c), nxt(NULL) {}
};
//following is the class to implement stack
class stack {
	
	Node * Top;
	public: 
	stack() 
	{
			Top = NULL;
	}
	bool push(char ch)
	{
		Node* newnode = new Node(ch);
		if (Top == NULL)
		{
			Top = newnode;
			newnode->nxt = NULL;
			return true;
		}
		else
		{
			newnode->nxt = Top;
			Top = newnode;
			return true;
		}
	}
	char pop()
	{
		if (isEmpty())
		{
			cout << "cant pop already empty\n";
		}
		else
		{
			Node* tmp = Top;
			int val = tmp->val;
			Top = Top->nxt;
			delete tmp;
			return val;
		}
	}
	bool isEmpty()
	{
		return (Top == NULL);
	}
	void display()
	{
		Node* tmp = Top;
		while (tmp) {
			cout << tmp->val << " ";
			tmp = tmp->nxt;
		}

	}
	
};
bool isPalindrome(string exp) //This will check if the string is palindrome or not 
{
	stack s1;
	int count = 0;

	if (exp.length() % 2 == 0)
	{
		for (int i = 0; i < exp.length() / 2; i++)
		{
			s1.push(exp[i]);
		}
		for (int i = exp.length() / 2; i < exp.length(); i++)
		{
			if (exp[i] == s1.pop())
			{
				count++;
			}
		}
		if (count == exp.length() / 2)
		{
			cout << "the given expression is an even palindrome\n";
			return true;
		}
		else
			return false;
	}
	else
	{
		for (int i = 0; i < (exp.length() / 2); i++)
		{
			s1.push(exp[i]);
		}

		int midIndex = exp.length() / 2;
		
		for (int i = midIndex+1; i < exp.length(); i++)
		{
			if (exp[i] == s1.pop())
			{
				count++;
			}
		}
		if (count == (exp.length() / 2))
		{
			cout << "the given expression is odd palindrome\n";
			return true;
		}
		else
			return false;
	}
}
int main()
{
	string exp;
	cout << "Enter the expression : ";
	cin >> exp;
	isPalindrome(exp);

	cout<<endl;  // for showing the return statement in next line
	system("pause");
	return 0;
}
