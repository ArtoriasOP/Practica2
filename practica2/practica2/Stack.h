
#ifndef __Stack_H__
#define __Stack_H__



#define STACK_BLOCK_SIZE 16
#define MIN(a, b)( ((a) < (b)) ? (a) : (b) )

template<class VALUE>
class Stack
{
private:

	VALUE*			data;
	unsigned int	mem_capacity;
	unsigned int	num_elements;

public:

	// Constructors
	Stack() : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(STACK_BLOCK_SIZE);
	}

	Stack(unsigned int capacity) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(capacity);
	}

	// Destructor
	~Stack()
	{
		delete[] data;
	}

	// Data Management
	void PushBack(const VALUE& element)
	{
		if (num_elements >= mem_capacity)
		{
			Alloc(mem_capacity + STACK_BLOCK_SIZE);
		}

		data[num_elements++] = element;
	}

	bool Pop(VALUE& result)
	{
		if (num_elements > 0)
		{
			result = data[--num_elements];
			return true;
		}
		return false;
	}

	void Clear()
	{
		num_elements = 0;
	}

	const VALUE* Peek(unsigned int index) const
	{
		VALUE* result = NULL;

		if (index < num_elements)
			return result = &data[index];

		return result;
	}

	// Utils
	unsigned int GetCapacity() const
	{
		return mem_capacity;
	}

	unsigned int Count() const
	{
		return num_elements;
	}

private:

	// Private Utils
	void Alloc(unsigned int mem)
	{
		VALUE* tmp = data;

		mem_capacity = mem;
		data = new VALUE[mem_capacity];

		num_elements = MIN(mem_capacity, num_elements);

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}
};
#endif // __Stack_H__