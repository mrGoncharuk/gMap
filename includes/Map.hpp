#include <iostream>


typedef unsigned int uint;
const uint gSegment = 16;

template<typename K, typename V>
class Map
{
public:
	struct pair
	{
		K key;
		V value;
	};

private:
	pair	*arr;
	uint	len;
	uint	capacity;

public:
	Map()
	: arr(new pair[gSegment])
	, len(0)
	, capacity(gSegment)
	{}

	~Map()
	{
		this->clear();
	}
	Map(const Map& rhs)
	: arr(new pair[16 + rhs.len])
	, len(rhs.len)
	, capacity(rhs.capacity)
	{
		if (rhs.arr)
		{
			for (uint i = 0; i < rhs.size(); i++)
			{
				arr[i] = rhs.arr[i];
			}
		}
	}
	Map& operator= (const Map& rhs)
	{
		if (this->capacity > rhs.size())
		{
			delete [] this->arr;
			this->arr = new pair[rhs.max_size()];
		}
		this->len = rhs.size();
		this->capacity = rhs.capacity;
		if (rhs.arr && this->arr)
		{
			for (uint i = 0; i < rhs.size(); i++)
			{
				arr[i] = rhs.arr[i];
			}
		}
		return (*this);
	}
	/* ***********************
	 * *******Capacity********
	 * *********************** */
	uint size() const
	{
		return (len);
	}

	bool empty() const
	{
		return (len == 0);
	}

	uint max_size() const
	{
		return (capacity);
	}

	/* ***********************
	 * *******Accessors*******
	 * *********************** */
	V &operator[](const K &key)
	{
		uint pos = bin_search_insert(key);
		if ((pos < len) && key == arr[pos].key)
			return arr[pos].value;
		if (buf_alloc())
		{
			if (pos < len)
			{
				shift(pos);
			}
			arr[pos].key = key;
			arr[pos].value = V();
			len++;

		}
		return (arr[pos].value);
	}

	/* ***********************
	 * *******Modifiers*******
	 * *********************** */
	V *insert(const K &key, const V &val)
	{
		uint pos = bin_search_insert(key);
		if (!buf_alloc())
			return NULL;
		if (pos < len)
		{
			if (key == arr[pos].key)
				return NULL;
			shift(pos);
		}
		arr[pos].key = key;
		arr[pos].value = val;
		len++;
		return (&(arr[pos].value));
	}

	uint erase(const K &key)
	{
		uint pos = bin_search_location(key);
		if (pos != (uint)-1)
		{
			--len;
			pair *curr = arr + pos;
			const pair *end = arr + len;
			while(curr < end)
			{
				*curr = *(curr + 1);
				curr++;
			}
			return 1;
		}
		return 0;
	}

	void swap(Map &m)
	{
		pair *arr_tmp = this->arr;
		this->arr = m.arr;
		m.arr = arr_tmp;
		uint size_tmp = this->len;
		this->len = m.len;
		m.len = size_tmp;
		size_tmp = this->capacity;
		this->capacity = m.capacity;
		m.capacity = size_tmp;
	}

	void clear()
	{
		if (arr)
		{
			delete[] arr;
			arr = NULL;
		}
		len = 0;
		capacity = gSegment;
	}
	/* *****************************
	 * *******Almost iterators******
	 * ***************************** */
	const pair *begin() const
	{
		return arr;
	}

	pair *begin()
	{
		return arr;
	}

	const pair *end() const
	{
		return arr + len;
	}

	pair *end()
	{
		return arr + len;
	}
	/* *****************************
	 * ********Operations***********
	 * ***************************** */
	pair *find(const K &key)
	{
		uint pos = bin_search_location(key);
		if (pos == (uint)-1)
			return this->end();
		else
			return (this->arr) + pos;
	}

	const pair *find (const K &key) const
	{
		uint pos = bin_search_location(key);
		if (pos == (uint)-1)
			return this->end();
		else
			(this->arr) + pos;
	}
private:
	bool buf_alloc()
	{
		if(arr == NULL)
		{
			arr = new (std::nothrow) pair[capacity];
			if (arr == NULL)
				return false;
		}
		else if ((len + 1) >= capacity)
		{
			uint  tmp_cap = len + gSegment;
			pair* tmp_arr  = new (std::nothrow) pair[tmp_cap];
			if(tmp_arr == NULL)
				return false;

			const pair *curr = arr;
			const pair *end = arr + len;
			pair *d = tmp_arr;
			while(curr != end)
				*d++ = *curr++;

			delete[] arr;
			arr = tmp_arr;
			capacity = tmp_cap;
		}
		return true;
	}

	uint bin_search_location(const K &key)
	{
		if (len == 0)
			return (uint)-1;
		else if (key < arr[0].key)
			return (uint)-1;
		else if (key > arr[len - 1].key)
			return (uint)-1;

		uint low = 0;
		uint high = len;
		uint mid;
		while (low < high)
		{
			mid = (low + high) >> 1U;
			if (key < arr[mid].key)
				high = mid;
			else if (key == arr[mid].key)
				return (mid);
			else
				low = mid + 1;
		}
		return (uint)-1;
	}

	uint bin_search_insert(const K &key)
	{
		if (len == 0)
			return 0;
		else if (key < arr[0].key)
			return 0;
		else if (key > arr[len - 1].key)
			return len;

		uint low = 0;
		uint high = len;
		uint mid;
		while (low < high)
		{
			mid = (low + high) >> 1U;
			if (key < arr[mid].key)
				high = mid;
			else if (key == arr[mid].key)
				return (mid);
			else
				low = mid + 1;
		}
		return low;
	}
	void shift(uint pos)
	{
		pair *first = arr + pos;
		pair *last = arr + len;
		while (first < last)
		{
			*last = *(last - 1);
			last--;
		}
	}
};
