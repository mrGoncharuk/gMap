//
// Created by mhonchar on 03.12.19.
//

#ifndef MIXNODE_HPP
# define MIXNODE_HPP

# include <string>
# include <iostream>

enum			e_valueType
{
	VT_INT,
	VT_DOUBLE,
	VT_STR,
	LT_MAP
};

class Base
{
public:
	Base(){}
	virtual ~Base(){}
};


typedef struct	s_mixValue
{
	int			index;
	std::string	name;
	e_valueType	type;
	union {
		int		iValue;
		double	dValue;
		char	*sValue;
		Base	*mValue;
	};
}				t_mixValue;



class MixNode: public Base
{
public:
	MixNode();
	virtual ~MixNode();
	MixNode(const MixNode &rhs);
	MixNode &operator=(const MixNode &rhs);

	MixNode &operator=(const int &rhs);
	MixNode &operator=(const double &rhs);
	MixNode &operator=(const char *rhs);
	MixNode &operator=(const Base *rhs);

	friend std::ostream& operator << (std::ostream &os, MixNode &rhs)
};


#endif //MIXNODE_HPP
