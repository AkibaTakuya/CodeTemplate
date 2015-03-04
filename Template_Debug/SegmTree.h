/*
 *	Name : Segment Tree �߶���
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

#ifndef _TEMPLATE_SEGMTREE
#define _TEMPLATE_SEGMTREE 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif	/* _TEMPLATE_STANDARD */

template <typename _Tp>
_Tp _SegmTree_init(size_t __n)
{ return _Tp(); }

template <typename _Tp>
class SegmTree 
{
// Name : SegmTree �߶���
// Copyright : www.fateud.com

// ��Ա���壺
public	:
	typedef SegmTree<_Tp>		_Self;
	typedef _Tp					_Node;
	typedef _Node				value_type;
	typedef _Node *				pointer;
	typedef _Node &				reference;

// ��Ա������
private	: 
	size_t _max_size;
	size_t _size;
	value_type* _data;
	value_type (*_func_init)(size_t);

public	:

// ��Ա������
public	: 
	explicit
	SegmTree(size_t _Sz, value_type (*__func_init)(size_t) = _SegmTree_init<value_type>)
	: _max_size(), _size(_Sz), _data(),
	  _func_init(__func_init)
	{
		for (_max_size = 1; _max_size < _size; _max_size <<= 1); _max_size <<= 1;
		_data = new value_type[_max_size];
	}

	~SegmTree()
	{ clear(); delete _data; }

// ��������
public	: 

// ְ�ܣ�
public	: 
	const size_t
	size() const
	{ return _size; }

// Ԫ�ط��ʣ�
public	: 
	reference
	root()
	{ return _data[1]; }

	const reference
	root() const
	{ return _data[1]; }

// �޸ķ���
public	: 
	void
	clear(size_t id = 1)
	{ }

// ��������
private	:
	void
	_push_up(size_t id)
	{ _data[id] = _data[l(id)] + _data[r(id)]; }

	void
	_push_down(size_t id)
	{ }

private	:
	void
	_build(size_t __id, size_t l, size_t r)
	{
//		printf("id = %d, l = %d, r = %d\n", __id, l, r);
		if (l == r) { _data[__id] = _func_init(l); return; }
		size_t mid = (l + r) >> 1;
		_build(lson(__id));
		_build(rson(__id));
		_push_up(__id);
	}

	value_type
	_get(size_t __s, size_t __t, size_t __id, size_t l, size_t r)
	{
		if (__t < l || __s > r) return value_type();
		if (__s <= l && r <= __t) return _data[__id];
		size_t mid = (l + r) >> 1;
		value_type __x = _get(__s, __t, lson(__id));
		value_type __y = _get(__s, __t, rson(__id));
		return __x + __y;
	}

	void
	_set(size_t __s, size_t __t, value_type __w, size_t __id, size_t l, size_t r)
	{
		if (__t < l || __s > r) return;
		if (__s <= l && r <= __t) {
			_data[__id] = _data[__id] + __w;
			return;
		}
		size_t mid = (l + r) >> 1;
		_set(__s, __t, __w, lson(__id));
		_set(__s, __t, __w, rson(__id));
		_push_up(__id);
	}

public	:
	void
	build()
	{ _build(1, 1, _size); }

	value_type
	get(size_t __s, size_t __t)
	{ return __s > __t ? value_type() : _get(__s, __t, 1, 1, _size); }

	void
	set(size_t __s, size_t __t, value_type __w)
	{ if (__t < __s) return; _set(__s, __t, __w, 1, 1, _size); }

// ��������أ�
public	: 

};

#endif	/* _TEMPLATE_SEGMTREE */
