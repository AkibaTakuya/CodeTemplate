/*
 *	Name : Binary Indexed Tree 树状数组
 *	Copyright : www.fateud.com
 *	
 *	模板参数：
 *	null
 *
 *	成员函数：
 *	null
 *	
 *	迭代器：
 *	null
 *	
 *	职能：
 *	null
 *	
 *	元素访问：
 *	null
 *	
 *	修改符：
 *	null
 *	
 *	操作符：
 *	null
 *	
 *	运算符重载：
 *	null
 *
 */

#ifndef _TEMPLATE_FENWICK
#define _TEMPLATE_FENWICK 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif	/* _TEMPLATE_STANDARD */

template <typename _Tp>
class Fenwick 
{
// Name : Binary Indexed Tree 树状数组
// Copyright : www.fateud.com

// 成员定义：
public	:
	typedef Fenwick			_Self;
	typedef _Tp				value_type;
	typedef _Tp *			pointer;
	typedef _Tp &			reference;

// 成员变量：
private	: 
	size_t _size;
	value_type* _data;

// 成员函数：
public	: 
	Fenwick(size_t __size)
	: _size(__size), _data(new value_type[_size])
	{ }

	~Fenwick() 
	{ }

// 迭代器：
public	: 

// 职能：
public	: 
	const size_t
	size() const
	{ return _data.sz; }

	void
	resize(size_t __sz)
	{
		_data.resize(__sz);
	}


// 元素访问：
public	: 

// 修改符：
public	: 

// 操作符：
public	: 

// 运算符重载：
public	: 

};

#endif	/* _TEMPLATE_FENWICK */
