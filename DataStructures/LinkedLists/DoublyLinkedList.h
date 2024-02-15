#pragma once
#include <memory>

template<typename ElementType>
class DLinkedList
{
private:
	class DNode
	{
		friend class DLinkedList;

		ElementType Element;
		DNode* Prev {nullptr};
		DNode* Next {nullptr};
	};

public:
	DLinkedList();
	~DLinkedList();

	[[nodiscard]] bool IsEmpty() const;
	const ElementType& GetFront() const;
	const ElementType& GetBack() const; 
	void AddFront(const ElementType& InElement);
	void AddBack(const ElementType& InElement);
	void RemoveFront();
	void RemoveBack();

protected:
	void Add(DNode* InNextNode, const ElementType& InElement);
	void Remove(DNode* InNodeToDelete);

private:
	DNode* Head;
	DNode* Tail;
};

template <typename ElementType>
DLinkedList<ElementType>::DLinkedList()
	: Head(new DNode)
	, Tail(new DNode)
{
	Head->Next = Tail;
	Tail->Prev = Head;
}

template <typename ElementType>
DLinkedList<ElementType>::~DLinkedList()
{
	while (!IsEmpty())
	{
		RemoveFront();
	}

	delete Head;
	delete Tail;
}

template <typename ElementType>
bool DLinkedList<ElementType>::IsEmpty() const
{
	return Head->Next == Tail;
}

template <typename ElementType>
const ElementType& DLinkedList<ElementType>::GetFront() const
{
	return Head->Next->Element;
}

template <typename ElementType>
const ElementType& DLinkedList<ElementType>::GetBack() const
{
	return Tail->Prev->Element;
}

template <typename ElementType>
void DLinkedList<ElementType>::AddFront(const ElementType& InElement)
{
	Add(Head->Next, InElement);
}

template <typename ElementType>
void DLinkedList<ElementType>::AddBack(const ElementType& InElement)
{
	Add(Tail, InElement);
}

template <typename ElementType>
void DLinkedList<ElementType>::RemoveFront()
{
	Remove(Head->Next);
}

template <typename ElementType>
void DLinkedList<ElementType>::RemoveBack()
{
	Remove(Tail->Prev);
}

template <typename ElementType>
void DLinkedList<ElementType>::Add(DNode* InNextNode, const ElementType& InElement)
{
	auto* NewNode = new DNode;
	NewNode->Element = InElement;
	NewNode->Next = InNextNode;
	NewNode->Prev = InNextNode->Prev;
	InNextNode->Prev->Next = NewNode;
	InNextNode->Prev = NewNode;
}

template <typename ElementType>
void DLinkedList<ElementType>::Remove(DNode* InNodeToDelete)
{
	auto* PrevNode = InNodeToDelete->Prev;
	auto* NextNode = InNodeToDelete->Next;
	PrevNode->Next = NextNode;
	NextNode->Prev = PrevNode;
	delete InNodeToDelete;
}