#include "MyLibrary.h"

using namespace MyNamespace;

//����������� ������
template<typename T>
My_List<T>::My_List()
{
	SIZE = 0;
	head = nullptr;
}

//���������� ������
template<typename T>
My_List<T>::~My_List()
{
	Clear();
}

//���������� ��������� ���������� ������
template<typename T>
T& My_List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}

		current = current->pNext;
		counter++;
	}
}

//����� ������� ��-� � ������ ������
template<typename T>
void My_List<T>::Pop_Front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;

	SIZE--;
}

//����� ������� ������
template<typename T>
void My_List<T>::Clear()
{
	while (SIZE)
	{
		Pop_Front();
	}
}

//����� ��������� ��-� ������ � ������������ ��������
template<typename T>
void My_List<T>::Insert(T value)
{
	Node<T>* current = head;
	Node<T>* prev = nullptr;
	Node<T>* newNode = new Node<T>(value);

	// ������ ����� ��� ������� ������ �������� � ��������������� ������
	while (current != nullptr && value > current->data)
	{
		prev = current;
		current = current->pNext;
	}

	// ���� ����� ������� ����������� � ������ ������
	if (prev == nullptr)
	{
		newNode->pNext = head;
		head = newNode;
	}
	else
	{
		prev->pNext = newNode;
		newNode->pNext = current;
	}

	SIZE++;
}

//����� ������� ��-� ������ � ������������ ��������
template<typename T>
void My_List<T>::RemoveAt(int index)
{
	if ((index >= SIZE) || index < 0)
	{
		throw exception("��� ��-�� � ����� ��������!\n");
	}

	if (index == 0)
	{
		Pop_Front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;

		SIZE--;
	}
}

//����� ������� ��-� � ����� ������
template<typename T>
void My_List<T>::Pop_Back()
{
	RemoveAt(SIZE - 1);
}

//����� ������� ��-� ������ � ������������ ��������
template<typename T>
void My_List<T>::PrintElement(int index)
{
	if (SIZE == 0)
	{
		throw exception("������ ����!\n");
	}

	if ((index >= SIZE) || index < 0)
	{
		throw exception("������ ��-�� � ������ ���!\n");
	}

	Node<T>* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}

	cout << current->data << endl;
}

//����� ������� ���� ������ �� �����
template<typename T>
void My_List<T>::PrintList()
{
	if (SIZE == 0)
	{
		throw exception("������ ����!\n");
	}

	cout << "������ ��-���:\n";

	Node<T>* current = head;

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->pNext;
	}

	cout << endl;
}

//����� ���������� ������ ������� ���������� ��-�� � ���������� ���������
template<typename T>
int My_List<T>::Find(T value)
{
	if (SIZE == 0)
	{
		throw exception("������ ����!\n");
	}

	int index = 0;
	Node<T>* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			return index;
		}

		current = current->pNext;
		index++;
	}

	throw exception("������ ��-�� ���!\n");
}