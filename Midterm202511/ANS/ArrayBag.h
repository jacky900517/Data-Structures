#include "BagInterface.h"
#include <cstddef>
#include <string>

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];		// Array of bag items
	int itemCount;							// Current count of bag items
	int maxItems;							// Max capacity of the bag

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType &newEntry);
	bool remove(const ItemType &anEntry);
	bool containsAllValues(ArrayBag<ItemType> &other);
	bool isSameUnordered(ArrayBag<ItemType> &other);
	void clear();
	vector<ItemType> toVector() const;
};

template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template <class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;

	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);

	return bagContents;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	} // end if

	return hasRoomToAdd;

	return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry)
{

	// add yor code here

	return false;
}

template <class ItemType>
bool ArrayBag<ItemType>::containsAllValues(ArrayBag<ItemType> &other)
{
	// add yor code here

	for (int i = 0; i < other.itemCount; i++)
	{
		bool flag = false;
		for (int j = 0; j < itemCount; j++)
		{
			if (other.items[i] == this->items[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			return flag;
	}
	return true;
}

template <class ItemType>
bool ArrayBag<ItemType>::isSameUnordered(ArrayBag<ItemType> &other)
{
	// add yor code here

	if (this->itemCount != other.itemCount)
		return false;

	vector<ItemType> thisVector = this->toVector();
	vector<ItemType> otherVector = other.toVector();

	// insertsort
	for (int i = 1; i < thisVector.size(); i++)
	{
		ItemType key = thisVector[i];
		int j = i - 1;

		while (j >= 0 && thisVector[j] > key)
		{
			thisVector[j + 1] = thisVector[j];
			j--;
		}
		thisVector[j + 1] = key;
	}

	for (int i = 1; i < otherVector.size(); i++)
	{
		ItemType key = otherVector[i];
		int j = i - 1;

		while (j >= 0 && otherVector[j] > key)
		{
			otherVector[j + 1] = otherVector[j];
			j--;
		}
		otherVector[j + 1] = key;
	}
	// end sort

	for (int i = 0; i < thisVector.size(); i++)
	{
		if (thisVector[i] != otherVector[i])
			return false;
	}

	return true;
}
