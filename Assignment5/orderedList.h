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
	void DeleteItem(ItemType& item);
	void PrintList();
	int SortedType<ItemType>::LengthIs() const;
	void DeleteList();
	ItemType ReturnItem();
	void SetCount(int item);
	

private:
	NodeType<ItemType>* listData;
	int length;
	int count;
	NodeType<ItemType>* currentPos;
	NodeType<ItemType>* nextPos;
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
	currentPos = NULL;
	nextPos = NULL;
	count = 0;
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
int SortedType<ItemType>::LengthIs() const
{
	return length;
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
		else if (location->info == item)
		{
			return;
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
void SortedType<ItemType>::DeleteItem
(ItemType& item)
{
	
	NodeType<ItemType>* pre;
	NodeType<ItemType>* del;
	
	
	if (listData->info == item)
	{
		del = listData;
		listData = del->next;
		delete del;
		return;
	}
	pre = listData;
	del = listData->next;
	while(del!=NULL)
	{
			if (del->info == item)
			{
				pre->next = del->next;
				delete del;
				break;
			}
			pre = del;
			del = del->next;
	}
}

template <class ItemType>
void SortedType<ItemType>::DeleteList()
{
	NodeType<ItemType>* tempPtr = listData;

	while (tempPtr != NULL) {
		/* take out the head node */
		listData = listData->next;
		delete tempPtr;
		/* update the head node */
		tempPtr = listData;
	}
	/* Reset the head and tail node */
	currentPos = listData = NULL;
}

template <class ItemType>
void SortedType<ItemType>::PrintList()
{
	NodeType<ItemType>* tempPtr;

	tempPtr = listData;
	while (tempPtr != NULL)
	{
		cout << " ";
		cout << tempPtr->info;
		cout << " ";
		tempPtr = tempPtr->next;
	}
	cout << "\n";

}

template <class ItemType>
ItemType SortedType<ItemType>::ReturnItem()
{
	
	if (count == 0 && listData != NULL)
	{
		count++;
		return  listData->info;
	}
	else if (count == 1 && listData != NULL)
	{
		currentPos = listData->next;
		count++;
		return currentPos->info;
	}
	else if (count > 1 && listData != NULL)
	{
		currentPos = currentPos->next;
		count++;
		return currentPos->info;
	}
}

template <class ItemType>
void SortedType<ItemType>::SetCount(int item)
{
	count=item;
}