#pragma once

template<typename ElementType>
class SLinkedList
{
private:
	class SNode
	{
		friend class SLinkedList;

		ElementType Element;
		SNode* Next {nullptr};
	};

public:
	SLinkedList();
	~SLinkedList();

	[[nodiscard]] bool IsEmpty() const;
	[[nodiscard]] const ElementType& GetFront() const;
	void AddFront(const ElementType& InElement);
	void RemoveFront();

private:
	SNode* Head;
};

template <typename ElementType>
SLinkedList<ElementType>::SLinkedList()
	: Head(nullptr)
{
}

template <typename ElementType>
SLinkedList<ElementType>::~SLinkedList()
{
	while (!IsEmpty())
	{
		RemoveFront();
	}
}

template <typename ElementType>
bool SLinkedList<ElementType>::IsEmpty() const
{
	return Head == nullptr;
}

template <typename ElementType>
const ElementType& SLinkedList<ElementType>::GetFront() const
{
	return Head->Element;
}

template <typename ElementType>
void SLinkedList<ElementType>::AddFront(const ElementType& InElement)
{
	auto* NodeToAdd = new SNode;
	NodeToAdd->Element = InElement;
	NodeToAdd->Next = Head;
	Head = NodeToAdd;
}

template <typename ElementType>
void SLinkedList<ElementType>::RemoveFront()
{
	auto* NodeToRemove = Head;
	Head = NodeToRemove->Next;
	delete NodeToRemove;
}