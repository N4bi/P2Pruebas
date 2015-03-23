#ifndef __P2DynArray_H__
#define __P2DynArray_H__

#include <assert.h>
#include <stdio.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template<class VALUE>
class P2DynArray
{
private:

	VALUE*				data;
	unsigned int		memSize;
	unsigned int		numElements;

	///////////////////////////////
	// Utils
	//////////////////////////////

	void Alloc(unsigned int memNeed)
	{
		VALUE *tmp = data;
		memSize = memNeed;
		data = new VALUE[memSize];
		if (numElements > memSize)
			numElements = memSize;

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < numElements; ++i)
				data[i] = tmp[i];
			delete[] tmp;
		}
	}
public:

	////////////////////////////
	// Constructors
	///////////////////////////

	P2DynArray() :memSize(0), numElements(0), data(NULL)
	{
		Alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	P2DynArray(unsigned int capacity) : memSize(0), numElements(0), data(NULL)
	{
		Alloc(capacity);
	}

	/////////////////////////
	// Destructor
	////////////////////////
	~P2DynArray()
	{
		delete[] data;
	}

	///////////////////////
	// operators
	//////////////////////

	VALUE &operator [](unsigned int index)
	{
		assert(index < numElements);
		return data[index];
	}

	const VALUE &operator [](unsigned int index) const
	{
		assert(index < numElements);
		return data[index];
	}

	//////////////////////
	// Functions
	/////////////////////

	void PushBack(const VALUE &element)
	{
		if (numElements >= memSize)
		{
			Alloc(memSize + DYN_ARRAY_BLOCK_SIZE);
		}
		data[numElements++] = element;
	}

	bool Pop(VALUE& value)
	{
		if (numElements > 0)
		{
			value = data[--numElements];
			return true;
		}
		return false;
	}

	void Clear()
	{
		numElements = 0;
	}

	bool Insert(const VALUE &element, unsigned int position)
	{
		if (position > numElements)
			return false;

		if (position == numElements)
		{
			PushBack(element);
			return true;
		}
		
		if (numElements + 1 > memSize)
			Alloc(memSize + DYN_ARRAY_BLOCK_SIZE);
		for (unsigned int i = 0; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		++numElements;
		return true;
	}

	//////////////////////////
	// Utils
	/////////////////////////

	unsigned int GetCapacity() const
	{
		return memSize;
	}

	unsigned int Count() const
	{
		return numElements;
	}



};


#endif // !__P2DynArray_H__
