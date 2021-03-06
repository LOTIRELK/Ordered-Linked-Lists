#pragma once
template <class ItemType>
struct NodeType;

template <class ItemType>
class SortedType
{
public:
	SortedType();	// Class constructor
	~SortedType();   	// Class destructor
	void InsertItem(ItemType item);
	void RetrieveItem(ItemType& item, bool& found);
	void MakeEmpty();
	void PrintList();
	void SetCurrentPos();
	void MoveToNextItem();
	
public:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;
};

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>* next;
};

template <class ItemType>
SortedType<ItemType>::SortedType()
{
	length = 0;
	listData = NULL;
}

template <class ItemType>
SortedType<ItemType>::~SortedType()
{
	NodeType<ItemType>* tempPtr;
	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
	NodeType<ItemType>* newNode;
	// pointer to node being inserted
	NodeType<ItemType>* predLoc;
	// trailing pointer
	NodeType<ItemType>* location;
	// traveling pointer
	bool moreToSearch;

	location = listData;
	predLoc = NULL;
	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		if (location->info < item)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else
			moreToSearch = false;
	}

	// Prepare node for insertion
	newNode = new NodeType<ItemType>;
	newNode->info = item;
	// Insert node into list.
	if (predLoc == NULL)
		// Insert as first
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;


}

template <class ItemType>
void SortedType<ItemType>::RetrieveItem
(ItemType& item, bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);
	while (moreToSearch && !found)
	{
		if (location->info < item)
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
			moreToSearch = false;
	}
}

template <class ItemType>
void SortedType<ItemType>::PrintList()
{
	NodeType<ItemType>* tempPtr;

	tempPtr = listData;
	while (tempPtr != NULL)
	{
		cout << tempPtr->info;
		cout << " ";
		tempPtr = tempPtr->next;
	}
	cout << "\n";

}