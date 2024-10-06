#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node(int d, node* n = 0)
	{
		data = d;
		next = n;
	}
};
class stack
{
	node* top;
public:
	stack();
	void push(int el);
	bool pop();
	int rtop();
	void print();
	/*~stack();
	void operator=(stack& o);
	stack(stack& o);*/
};
stack::stack()
{
	top = NULL;
}
void stack::push(int el)
{
	if (top == 0)
		top = new node(el);
	else
	{
		top = new node(el, top);
	}
}
bool stack::pop()
{
	if (top == 0)
		return false;
	else
	{
		node* t = top;
		top = top->next;
		delete t;
		return true;
	}
}
int stack::rtop()
{
	if (top != 0)
		return top->data;
}
void stack::print()
{
	stack s;
	while (top != 0)
	{
		s.push(rtop());
		pop();
		cout << s.rtop() << " ";
	}
	while (s.top != 0)
	{
		push(s.rtop());
		s.pop();
	}
	cout << endl;
}
/*stack::~stack()
{
	while (top != 0)
		pop();
	cout << "Deleted" << endl;
}
void stack::operator=(stack& o)
{
	while (top != 0)
		pop();
	if (o.top != 0)
	{
		top = new node(o.top->data,0);
		o.pop();
		while (o.top != 0)
		{
			top=new node(o.top->data,top);
			o.pop();
		}
	}
	else
		top = 0;
}
stack::stack(stack& o)
{
	if (o.top != 0)
	{
		top = new node(o.top->data, 0);
		o.pop();
		while (o.top != 0)
		{
			top = new node(o.top->data, top);
			o.pop();
		}
	}
	else
		top = 0;
}*/
void main()
{
	stack s;
	s.push(1);
	s.push(5);
	s.push(3);
	s.push(99);
	s.print();
	s.pop();
	cout << s.rtop() << endl;
	s.print();
}