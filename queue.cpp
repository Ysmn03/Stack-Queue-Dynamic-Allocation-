#include<iostream>
using namespace std;
struct node
{
	node* next;
	int data;
	node(int d,node*n=0)
	{
		next = n;
		data = d;
	}
};
class queue
{
	node* front, * rear;
public:
	queue();
	bool empty();
	void append(int el);
	bool serve();
	bool retrieve(int& el);
	~queue();
};
queue::queue()
{
	front = 0;
	rear = 0;
}
bool queue::empty()
{
	return front == 0;
}
void queue::append(int el)
{
	if (empty())
		front = rear = new node(el);
	else
		rear = rear->next = new node(el);
}
bool queue::serve()
{
	if (empty())
		return false;
	else if (front == rear)
	{
		delete front;
		front = 0;
		rear = 0;
		return true;
	}
	else
	{
		node* t = front;
		front = front->next;
		delete t;
		return true;
	}
}
bool queue::retrieve(int& el)
{
	if (empty())
		return false;
	el = front->data;
	return true;
}
queue::~queue()
{
	while (!empty())
	{
		node* t = front;
		front = front->next;
		delete t;
	}
	cout << "deleted";
}
int main()
{
	queue q;
	cout << q.empty() << "\n";
	int n;
	cout << "Enter number of elements to add\n";
	cin >> n;
	for(int i=0;i<n;++i)
	{
		int num;
		cin >> num;
		q.append(num);
	}
	int front;
	q.retrieve(front);
	cout <<"Element in the front: " << front << "\n";
	q.serve();
	q.retrieve(front);
	cout <<"Element in the front: " << front << "\n";
}