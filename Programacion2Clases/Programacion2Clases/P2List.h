#ifndef __P2List_H__
#define __P2List_H__

#define NULL 0	

/////////////////////////////
// Double Linked List
////////////////////////////

template<class tdata>
struct p2ListItem
{
	tdata	data;
	p2ListItem<tdata>	*next;
	p2ListItem<tdata>	*prev;

	inline p2ListItem(const tdata &data2)
	{
		data = data2;
		next = prev = NULL;

	}
	~p2ListItem(){}
};

	/////////////////////////////////////
	// Manages Double linked list
	////////////////////////////////////

template<class tdata>
class P2List
{
public:
	p2ListItem<tdata>	*start;
	p2ListItem<tdata>	*end;

private:
	unsigned size;

public:
	/////////////////////////////
	// Constructor
	////////////////////////////

	inline P2List()
	{
		start = end = NULL;
		size = 0;
	}

	/////////////////////////////////
	// Destructor
	/////////////////////////////

	~P2List()
	{
		Clear();
	}

	//////////////////////////
	// Get size 
	/////////////////////////

	unsigned int countSize()
	{
		return size;
	}
	////////////////////////
	// Add Item
	///////////////////////

	unsigned int add(const tdata &item)
	{
		p2ListItem<tdata>	pdataItem;
		pdataItem = new p2ListItem<tdata>(item);
		if (start == NULL)
		{
			start = end = pdataItem;
		}
		else
		{
			pdataItem->prev = end;
			end->next = pdataitem;
			end = pdataItem;
		}
		return (++size);
	}

	//////////////////////////////////////
	// Delte a item from the list
	//////////////////////////////////////

	bool del(p2ListItem<tdata> *item)
	{
		if (item == NULL)
		{
			return false;
		}
		//reconstruct the list

		if (item->prev != NULL)
		{
			item->prev->next = item->next;
			if (item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
				{
				end = item->prev;
				}
		}
		else
		{
			if (item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
					}

					delete item;
					--size;
					return true;
				}




	void Clear()
	{
		p2ListItem<tdata>	*pdata;
		p2ListItem<tdata>	*pnext;
		pdata = start;

		while (pdata != NULL)
		{
			pnext = pdata->next; 
			delete pdata;
			pdata = pnext;
		}
		start = end = NULL;
		size = 0;
	}

};



#endif // !__P2List_H__
