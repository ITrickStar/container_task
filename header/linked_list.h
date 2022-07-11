#include <random>
#include <cstring>

template <class T>
struct Node
{
	T value;
	Node *next;
};

template <class T>
class List
{
private:
	Node<T> *head;
	int size;

public:
	// default constructor
	List(int _size = 0) : head(nullptr), size(_size)
	{
		head = new Node<T>;
		if (size > 0)
		{
			head->value = rand();
			Node<T> *temp = head;
			for (int i = 1; i < size; i++)
			{
				temp->next = new Node<T>;
				temp = temp->next;
				temp->value = rand();
			}
		}
	};
	// copy constructor
	List(const List& cpy)
	{
		head = new Node<T>;
		size = 1;
		this->operator=(cpy);
	};
	~List()
	{
		while (head != nullptr)
		{
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
	};

	// copies the contents of the eq list
	// maybe it should only assign head of this list to another but idk
	List& operator=(const List& eq)
	{
		this->Resize(eq.size);
		Node<T> *tempA = this->head;
		Node<T> *tempB = eq.head;
		for (int i = 0; i < size; i++)
		{
			tempA->value = tempB->value;
			tempA = tempA->next;
			tempB = tempB->next;
		}
		return *this;
	};
	// checks if all the values of nodes are equal between each other
	bool operator==(const List& eq)
	{
		if (this->size != eq.size)
			return false;
		else
		{
			Node<T> *tempA = this->head;
			Node<T> *tempB = eq.head;
			for (int i = 0; i < size; i++)
			{
				if (tempA->value != tempB->value)
					return false;
				tempA = tempA->next;
				tempB = tempB->next;
			}
		}
		return true;
	};
	// returns POINTER to node not their value
	Node<T> *operator[](int ind)
	{
		if (ind < size && ind >= 0)
		{
			Node<T> *temp = head;
			for (int i = 0; i < ind; i++)
				temp = temp->next;
			return temp;
		}
		throw("out of range");
	};

	int getSize() { return size; };
	// utility function to resize list
	// if it is used to extend list adds empty nodes
	void resize(int newcap)
	{
		if (size > newcap)
			for (size; size > newcap; size--)
			{
				Node<T> *temp = head;
				head = head->next;
				delete temp;
			}
		else
		{
			for (size; size < newcap; size++)
			{
				Node<T> *temp = new Node<T>;
				temp->next = head;
				head = temp;
			}
		}
	};
	void pushFront(T input)
	{
		Node<T> *temp = new Node<T>;
		temp->value = input;
		temp->next = head;
		head = temp;
		size++;
	};
	void pushBack(T input)
	{
		Node<T> *temp = this->operator[](size - 1);
		temp->next = new Node<T>;
		temp = temp->next;
		temp->value = input;
		size++;
	};
	void popFront()
	{
		if (size != 0)
		{
			Node<T> *temp = head;
			head = head->next;
			delete temp;
			size--;
		}
		else
			throw("List is empty");
	};
	void popBack()
	{
		if (size != 0)
		{
			delete this->operator[](size - 1);
			size--;
		}
		else
			throw("List is empty");
	};
	// returns pointer to node
	Node<T> *find(T val)
	{
		Node<T> *temp = head;
		for (int i = 0; i < size; i++)
		{
			if (temp->value == val)
				return temp;
			temp = temp->next;
		}
		return nullptr;
	};

	template <class U>
	friend std::ostream& operator<<(std::ostream& strm, const List<U>& list);
};

// output is the values of nodes
template <class U>
std::ostream& operator<<(std::ostream& strm, const List<U>& list)
{
	strm << '[';
	Node<U> *temp = list.head;
	for (int i = 0; i < list.size - 1; i++)
	{
		strm << temp->value << " ";
		temp = temp->next;
	}
	strm << temp->value << ']';

	return strm;
}
