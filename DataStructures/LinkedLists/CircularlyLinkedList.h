#pragma once

template<typename ElementType>
class CLinkedList
{
private:
	class CNode
	{
		friend class CLinkedList;

		ElementType Element;
		CNode* Next {nullptr};
	};

public:
	CLinkedList();
	~CLinkedList();

	[[nodiscard]] bool IsEmpty() const;
	[[nodiscard]] const ElementType& Get() const;
	[[nodiscard]] const ElementType& GetNext() const;
	void Advance();
	void Add(const ElementType& InElement);
	void Remove();

private:
	CNode* Cursor;
};

template <typename ElementType>
CLinkedList<ElementType>::CLinkedList()
	: Cursor(nullptr)
{
}

template <typename ElementType>
CLinkedList<ElementType>::~CLinkedList()
{
	while (!IsEmpty())
	{
		Remove();
	}
}

template <typename ElementType>
bool CLinkedList<ElementType>::IsEmpty() const
{
	return Cursor == nullptr;
}

template <typename ElementType>
const ElementType& CLinkedList<ElementType>::Get() const
{
	return Cursor->Element;
}

template <typename ElementType>
const ElementType& CLinkedList<ElementType>::GetNext() const
{
	return Cursor->Next->Element;
}

template <typename ElementType>
void CLinkedList<ElementType>::Advance()
{
	Cursor = Cursor->Next;
}

template <typename ElementType>
void CLinkedList<ElementType>::Add(const ElementType& InElement)
{
	auto* NodeToAdd = new CNode;
	NodeToAdd->Element = InElement;

	if (IsEmpty())
	{
		NodeToAdd->Next = NodeToAdd;
		Cursor = NodeToAdd;
	}
	else
	{
		NodeToAdd->Next = Cursor->Next;
		Cursor->Next = NodeToAdd;
	}
}

template <typename ElementType>
void CLinkedList<ElementType>::Remove()
{
	auto* NodeToRemove = Cursor->Next;

	if (NodeToRemove == Cursor)
	{
		Cursor == nullptr;
	}
	else
	{
		Cursor->Next = NodeToRemove->Next;
	}

	delete NodeToRemove;
}