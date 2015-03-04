/*
 *	Name : Binary Indexed Tree ��״����
 *	Copyright : www.fateud.com
 *	
 *	ģ�������
 *	null
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

#ifndef _TEMPLATE_FENWICK
#define _TEMPLATE_FENWICK 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif	/* _TEMPLATE_STANDARD */

template <typename _Tp>
class Fenwick 
{
// Name : Binary Indexed Tree ��״����
// Copyright : www.fateud.com

// ��Ա���壺
public	:
	typedef Fenwick			_Self;
	typedef _Tp				value_type;
	typedef _Tp *			pointer;
	typedef _Tp &			reference;

// ��Ա������
private	: 
	size_t _size;
	value_type* _data;

// ��Ա������
public	: 
	Fenwick(size_t __size)
	: _size(__size), _data(new value_type[_size])
	{ }

	~Fenwick() 
	{ }

// ��������
public	: 

// ְ�ܣ�
public	: 
	const size_t
	size() const
	{ return _data.sz; }

	void
	resize(size_t __sz)
	{
		_data.resize(__sz);
	}


// Ԫ�ط��ʣ�
public	: 

// �޸ķ���
public	: 

// ��������
public	: 

// ��������أ�
public	: 

};

#endif	/* _TEMPLATE_FENWICK */
