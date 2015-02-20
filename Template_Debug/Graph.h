/*
 *	Name : Directed Graph 有向图
 *	Copyright : www.fateud.com
 *	
 *	模板参数：
 *	Graph <_Tp>
 *		限定元素的类型 _Tp
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
#ifndef _TEMPLATE_GRAPH
#define _TEMPLATE_GRAPH 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif	/* _TEMPLATE_STANDARD */

#ifndef _TEMPLATE_FORWLIST
#include <Forwlist.h>
#endif	/* _TEMPLATE_FORWLIST */

template <typename _Tp>
class _Graph_node
{
// 成员定义：
	typedef _Tp						value_type;

// 成员变量：
public	:
	size_t v;
	value_type c;

// 成员函数：
public	:
	_Graph_node(size_t __v, value_type __c)
	: v(__v), c(__c) { }

};

template <typename _Tp>
class Graph 
{
// Name : Graph 有向图
// Copyright : www.fateud.com

// 成员定义：
public	:
	typedef Graph<_Tp>				_Self;
	typedef _Graph_node<_Tp>		_Node;
	typedef _Tp						value_type;
	typedef _Tp *					pointer;
	typedef _Tp &					reference;

// 成员变量：
private	: 

// 成员函数：
public	: 
	Graph() {}
	~Graph() {}

// 迭代器：
public	: 

// 职能：
public	: 

// 元素访问：
public	: 

// 修改符：
public	: 

// 操作符：
public	: 

// 运算符重载：
public	: 

};

#endif	/* _TEMPLATE_GRAPH */
