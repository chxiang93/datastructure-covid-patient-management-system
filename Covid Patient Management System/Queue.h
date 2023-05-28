//Queue.h 
//Queue Linked List
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
struct Node
{
	T number;
	Node <T> *next;
};

template <class T>
class Queue
{
private:
	Node <T> *front;
	Node <T> *rear;
	int count;			//num of patient

public:
	Queue();				//constructor
	void enqueue();		//generate waiting number for new patient
	void dequeue();		//call next patient 
	T firstPatient();	//return waiting number of first patient
	T lastPatient();		//return waiting number of last patient
	T nextPatient();		//return the waiting number of second patient
	bool empty();		//check if the queue linked list is empty
	T numOfPatient();	//return number of patient waiting
};
#endif

template <class T>
Queue <T>::Queue()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

template <class T>
void Queue <T>::enqueue()
{
	static int num = 100;
	Node <T> *newNode = new Node <T>;
	newNode->number = num;
	newNode->next = NULL;

	if (!empty())
		rear->next = newNode;
	else
		front = newNode;

	cout << "\nThe waiting number for patient is " << num << endl;
	num++;
	count++;
	rear = newNode;
}

template <class T>
void Queue <T>::dequeue()
{
	if (empty())
		cout << "\n\nThere is currently no patient waiting\n\n";
	else
	{
		Node <T> *temp = front;
		if (count == 1)
		{
			front = NULL;
			rear = NULL;
		}
		else
			front = front->next;

		count--;
		delete temp;
	}
}   

template <class T>
bool Queue <T>::empty()
{
	return(count == 0);
}

template <class T>
T Queue <T>::firstPatient()
{
	if (empty())
		return false;
	else
		return front->number;
}

template <class T>
T Queue <T>::lastPatient()
{
	if (empty())
		return false;
	else
		return rear->number;
}

template <class T>
T Queue <T>::nextPatient()
{
	if (count == 0 || count == 1)
		return false;
	else
		return front->next->number;
}

template <class T>
T Queue <T>::numOfPatient()
{
	return count;
}