#ifndef ALIST_H_INCLUDED
#define ALIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>

using namespace std;
const int gSegment = 16;

typedef enum __ItemValueType
{
    IVT_NULL = 0,
    IVT_BOOL = 1,
    IVT_INT = 2,
    IVT_FLOAT = 3,
    IVT_DOUBLE = 4,
    IVT_STRING = 5,
    IVT_LIST = 6,
    IVT_OBJECT = 7

} _ItemValueType;

class _Gen
{
    public:
        _Gen()
        {
        }

        virtual ~_Gen()
        {
        }

    protected:
        virtual void Destroy() = 0;

};

typedef struct __ItemValueInfo
{
    int index;
    char* name;
    _ItemValueType type;
    union
    {
        bool bValue;
        int iValue;
        float fValue;
        double eValue;
        char* sValue;
        _Gen* aValue;
        void* oValue;
    };

} _ItemValueInfo, *_lpItemValueInfo;

class ItemInfo : public _Gen
{
    public:
        ItemInfo()
        {
            memset(&m_value, 0, sizeof(_ItemValueInfo));
            m_value.type = IVT_NULL;
            m_value.index = -1;
        }

        ItemInfo(ItemInfo& ref)
        {
            m_value.type = ref.get_type();
            switch (m_value.type)
            {
                case IVT_BOOL:
                {
                    m_value.bValue = ref.get_value().bValue;
                }
                break;

                case IVT_INT:
                {
                    m_value.iValue = ref.get_value().iValue;
                }
                break;

                case IVT_FLOAT:
                {
                    m_value.fValue = ref.get_value().fValue;
                }
                break;

                case IVT_DOUBLE:
                {
                    m_value.eValue = ref.get_value().eValue;
                }
                break;

                case IVT_STRING:
                {
                    char* sValue = ref.get_value().sValue;
                    int len = strlen(sValue) + 1;
                    m_value.sValue = (char*)malloc(len);
                    strncpy(m_value.sValue, sValue, len-1);
                    m_value.sValue[len-1] = '\0';
                }
                break;

                case IVT_LIST:
                {
                    m_value.aValue = ref.get_value().aValue;
                }
                break;

                case IVT_OBJECT:
                {
                    m_value.oValue = ref.get_value().oValue;
                }
                break;

                default:
                {
                    memset(&m_value, 0, sizeof(_ItemValueInfo));
                    m_value.type = IVT_NULL;
                }
                break;
            }
        }

        virtual ~ItemInfo()
        {
            free(m_value.name);

            Destroy();
        }

        inline ItemInfo& operator = (ItemInfo& ref)
        {
            Destroy();

            m_value.type = ref.get_type();
            switch (m_value.type)
            {
                case IVT_BOOL:
                {
                    m_value.bValue = ref.get_value().bValue;
                }
                break;

                case IVT_INT:
                {
                    m_value.iValue = ref.get_value().iValue;
                }
                break;

                case IVT_FLOAT:
                {
                    m_value.fValue = ref.get_value().fValue;
                }
                break;

                case IVT_DOUBLE:
                {
                    m_value.eValue = ref.get_value().eValue;
                }
                break;

                case IVT_STRING:
                {
                    char* sValue = ref.get_value().sValue;
                    int len = strlen(sValue) + 1;
                    m_value.sValue = (char*)malloc(len);
                    strncpy(m_value.sValue, sValue, len-1);
                    m_value.sValue[len-1] = '\0';
                }
                break;

                case IVT_LIST:
                {
                    m_value.aValue = ref.get_value().aValue;
                }
                break;

                case IVT_OBJECT:
                {
                    m_value.oValue = ref.get_value().oValue;
                }
                break;

                default:
                {
                    memset(&m_value, 0, sizeof(_ItemValueInfo));
                    m_value.type = IVT_NULL;
                }
                break;
            }

            return (*this);
        }

        inline ItemInfo& operator = (const bool& ref)
        {
            Destroy();

            m_value.type = IVT_BOOL;
            m_value.bValue = ref;

            return (*this);
        }

        inline ItemInfo& operator = (const int& ref)
        {
            Destroy();

            m_value.type = IVT_INT;
            m_value.iValue = ref;

            return (*this);
        }

        inline ItemInfo& operator = (const float& ref)
        {
            Destroy();

            m_value.type = IVT_FLOAT;
            m_value.fValue = ref;

            return (*this);
        }

        inline ItemInfo& operator = (const double& ref)
        {
            Destroy();

            m_value.type = IVT_DOUBLE;
            m_value.eValue = ref;

            return (*this);
        }

        inline ItemInfo& operator = (const char* ref)
        {
            Destroy();

            m_value.type = IVT_STRING;
            int len = strlen(ref) + 1;
            m_value.sValue = (char*)malloc(len);
            strncpy(m_value.sValue, ref, len-1);
            m_value.sValue[len-1] = '\0';

            return (*this);
        }

        inline ItemInfo& operator = (_Gen* ref)
        {
            Destroy();

            m_value.type = IVT_LIST;
            m_value.aValue = ref;

            return (*this);
        }

        inline ItemInfo& operator = (void* ref)
        {
            Destroy();

            m_value.type = IVT_OBJECT;
            m_value.oValue = ref;

            return (*this);
        }

        friend inline ostream& operator << (ostream &stream, ItemInfo& ref)
        {
            switch (ref.get_type())
            {
                case IVT_BOOL:
                {
                    stream << ref.get_value().bValue;
                }
                break;

                case IVT_INT:
                {
                    stream << ref.get_value().iValue;
                }
                break;

                case IVT_FLOAT:
                {
                    stream << ref.get_value().fValue;
                }
                break;

                case IVT_DOUBLE:
                {
                    stream << ref.get_value().eValue;
                }
                break;

                case IVT_STRING:
                {
                    stream << ref.get_value().sValue;
                }
                break;

                case IVT_LIST:
                {
                    stream << "[List]";
                }
                break;

                case IVT_OBJECT:
                {
                    stream << "[Object]";
                }
                break;

                default:
                {
                }
                break;
            }

            return stream;
        }

        ItemInfo& operator [] (const int index);
        ItemInfo& operator [] (const char* name);

        inline int get_index()
        {
            return (m_value.index);
        }

        inline void set_index(const int index)
        {
            m_value.index = index;
        }

        inline char* get_name()
        {
            return (m_value.name);
        }

        inline void set_name(const char* name)
        {
            int len = strlen(name) + 1;
            m_value.name = (char*)realloc(m_value.name, len*sizeof(char));
            strcpy(m_value.name, name);
            m_value.name[len-1] = '\0';
        }

        inline _ItemValueType get_type()
        {
            return (m_value.type);
        }

        inline _ItemValueInfo get_value()
        {
            return (m_value);
        }

    protected:
        virtual void Destroy()
        {
            if (m_value.type == IVT_STRING)
            {
                free(m_value.sValue);
            }

            if (m_value.type == IVT_LIST)
            {
                delete (m_value.aValue);
            }

            m_value.type = IVT_NULL;
        }

    private:
        _ItemValueInfo m_value;

};

class AList : public _Gen
{
	private:
		ItemInfo** m_items;
		int m_size;
		int m_capacity;
		int m_strbegin;
    public:
        AList()
        {
            m_items = NULL;
            m_size = 0;
            m_capacity = 0;
            m_strbegin = 0;
        }

        virtual ~AList()
        {
            erase();
        }

        inline void erase()
        {
            Destroy();
        }

		/* ***********************
		* *******Capacity********
		* *********************** */
		uint size() const
		{
			return (m_size);
		}

		bool empty() const
		{
			return (m_size == 0);
		}

		uint max_size() const
		{
			return (m_capacity);
		}


		inline ItemInfo& operator[] (const int index)
		{
			ItemInfo* pItem = NULL;
			if (m_strbegin > 0)
				pItem = find_item(index);
			if (pItem != NULL)
			{
				return (*pItem);
			}
			else
			{
				int pos = 0;
				if (m_strbegin > 0)
					pos = bin_search_insert(index);
				buf_alloc();
				if (pos <= m_strbegin)
					shift(pos);
				m_items[pos] = new ItemInfo();
				m_items[pos]->set_index(index);
				m_size++;
				m_strbegin++;
				return (*(m_items[pos]));
			}
		}

		inline ItemInfo& operator[] (const char* name)
		{
			ItemInfo* pItem = NULL;
			if (m_items)
				pItem = find_item(name);
			if (pItem != NULL)
			{
				return (*pItem);
			}
			else
			{
				int pos = bin_search_insert(name);
				buf_alloc();
				if (pos < m_size)
					shift(pos);
				m_items[pos] = new ItemInfo();
				m_items[pos]->set_name(name);
				m_size++;
				return (*(m_items[pos]));
			}
		}

        friend inline ostream& operator << (ostream &stream, AList& ref)
        {
            stream << "[List]";

            return stream;
        }


		/* *****************************
		* *******Almost iterators******
		* ***************************** */
		ItemInfo **begin()
		{
			return m_items;
		}

		ItemInfo **end()
		{
			return m_items + m_size;
		}

protected:
		void buf_alloc()
		{
			if(m_items == NULL)
			{
				m_capacity = gSegment;
				m_items = (ItemInfo**)realloc(m_items, m_capacity*sizeof(ItemInfo*));

			}
			else if ((m_size + 1) >= m_capacity)
			{
				int  tmp_cap = m_size + gSegment;
				m_items = (ItemInfo**)realloc(m_items, tmp_cap*sizeof(ItemInfo*));
				m_capacity = tmp_cap;
			}
		}

		inline ItemInfo* find_item(const int index)
		{
			if ((index < m_items[0]->get_index()) || (index > m_items[m_strbegin - 1]->get_index()))
				return NULL;

			int low = 0;
			int high = m_strbegin;
			int mid;
			while (low < high)
			{
				mid = (low + high) / 2;
				if (index < m_items[mid]->get_index())
					high = mid;
				else if (index == m_items[mid]->get_index())
					return (m_items[mid]);
				else
					low = mid + 1;
			}
			return NULL;
		}

		inline ItemInfo* find_item(const char* name)
		{

			if (strcmp(name, m_items[m_strbegin]->get_name()) < 0 || strcmp(name, m_items[m_size - 1]->get_name()) > 0)
			{
				return NULL;
			}
			int low = m_strbegin;
			int high = m_size;
			int mid;
			while (low < high)
			{
				mid = (low + high) / 2;
				if (strcmp(name, m_items[mid]->get_name()) < 0)
					high = mid;
				else if (strcmp(name, m_items[mid]->get_name()) == 0)
					return (m_items[mid]);
				else
					low = mid + 1;
			}
			return NULL;
		}

		int bin_search_insert(const int index) const
		{
			if (m_size == 0)
				return (0);
			else if (index < m_items[0]->get_index())
				return (0);
			else if ((index > m_items[m_strbegin - 1]->get_index()))
				return (m_strbegin);

			int low = 0;
			int high = m_strbegin;
			int mid;
			while (low < high)
			{
				mid = (low + high) / 2;
				if (index < m_items[mid]->get_index())
					high = mid;
				else if (index > m_items[mid]->get_index())
					return (mid);
				else
					low = mid + 1;
			}
			return low;
		}

		int bin_search_insert(const char* name) const
		{
			if (m_size == 0)
				return (0);
			else if (strcmp(name, m_items[m_strbegin]->get_name()) < 0)
				return (m_strbegin);
			else if (strcmp(name, m_items[m_size - 1]->get_name()) > 0)
				return (m_size);

			int low = m_strbegin;
			int high = m_size;
			int mid;
			while (low < high)
			{
				mid = (low + high) / 2;
				if (strcmp(name, m_items[mid]->get_name()) > 0)
					high = mid;
				else if (strcmp(name, m_items[mid]->get_name()) < 0)
					return (mid);
				else
					low = mid + 1;
			}
			return low;
		}


		void shift(int pos)
		{
			ItemInfo **first = m_items + pos;
			ItemInfo **last = m_items + m_size;
			while (first < last)
			{
				*last = *(last - 1);
				last--;
			}
		}
        virtual void Destroy()
        {
            for (int i=0; i<m_size; i++)
            {
                delete m_items[i];
            }
            free(m_items);
            m_size = 0;
        }



};

ItemInfo& ItemInfo::operator[] (const int index)
{
    return (((AList&)(*m_value.aValue))[index]);
}

ItemInfo& ItemInfo::operator[] (const char* name)
{
    return (((AList&)(*m_value.aValue))[name]);
}

#endif // ALIST_H_INCLUDED
