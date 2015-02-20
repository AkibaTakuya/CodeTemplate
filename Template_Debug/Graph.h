/*
 *	Name : Directed Graph ����ͼ
 *	Copyright : www.fateud.com
 *	
 *	ģ�������
 *	Graph <_Tp>
 *		�޶�Ԫ�ص����� _Tp
 *
 *	��Ա������
 *	null
 *	
 *	��������
 *	null
 *	
 *	ְ�ܣ�
 *	null
 *	
 *	Ԫ�ط��ʣ�
 *	null
 *	
 *	�޸ķ���
 *	null
 *	
 *	��������
 *	null
 *	
 *	��������أ�
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
// ��Ա���壺
	typedef _Tp						value_type;

// ��Ա������
public	:
	size_t v;
	value_type c;

// ��Ա������
public	:
	_Graph_node(size_t __v, value_type __c)
	: v(__v), c(__c) { }

};

template <typename _Tp>
class Graph 
{
// Name : Graph ����ͼ
// Copyright : www.fateud.com

// ��Ա���壺
public	:
	typedef Graph<_Tp>				_Self;
	typedef _Graph_node<_Tp>		_Node;
	typedef _Tp						value_type;
	typedef _Tp *					pointer;
	typedef _Tp &					reference;

// ��Ա������
private	: 

// ��Ա������
public	: 
	Graph() {}
	~Graph() {}

// ��������
public	: 

// ְ�ܣ�
public	: 

// Ԫ�ط��ʣ�
public	: 

// �޸ķ���
public	: 

// ��������
public	: 

// ��������أ�
public	: 

};

#endif	/* _TEMPLATE_GRAPH */
