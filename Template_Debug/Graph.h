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
class _Graph_base
{
// 成员定义：
public  :
	typedef _Graph_base<_Tp>		_Self;
	typedef _Tp						value_type;

// 成员变量：
public	:
	size_t v;
	value_type w;

// 成员函数：
public	:
	_Graph_base()
	: v(), w() { }
	_Graph_base(size_t __v, value_type __w)
	: v(__v), w(__w) { }

// 操作符重载：
public	:
	bool
	operator < (const _Self &other) const
	{ return w < other.w; }

	bool
	operator > (const _Self &other) const
	{ return w > other.w; }

	bool
	operator <= (const _Self &other) const
	{ return w <= other.w; }

	bool
	operator >= (const _Self &other) const
	{ return w >= other.w; }
};

template <typename _Tp>
class Graph 
{
// Name : Graph 有向图
// Copyright : www.fateud.com

// 成员定义：
public	:
	typedef Graph<_Tp>				_Self;
	typedef _Graph_base<_Tp>		_Base;
	typedef ForwList<_Base>			_Node;
	typedef _Node					value_type;
	typedef _Node *					pointer;
	typedef _Node &					reference;

// 成员变量：
private	: 
	vector<pointer> _data;

// 成员函数：
public	:
	Graph()
	: _data() { }

	explicit
	Graph(size_t _Sz)
	: _data( vector<pointer>(_Sz) )
	{ REP(i,_Sz) _data[i] = new value_type(); }

	~Graph()
	{ RREP(i,sz) { delete _data[i]; } _data.clear(); }

// 职能：
public	:
	inline const size_t
	size() const
	{ return _data.size(); }

// 元素访问：
public	: 
	inline reference
	operator [] (size_t __n)
	{ return *_data[__n]; }

	inline const reference
	operator [] (size_t __n) const
	{ return *_data[__n]; }

	inline reference
	at (size_t __n)
	{ return *_data[__n]; }

	inline const reference
	at (size_t __n) const
	{ return *_data[__n]; }

// 修改符：
private	:
	void
	_add_elem(size_t __u, size_t __v, _Tp __w)
	{ _data[__u]->push_front(_Base(__v, __w)); }

public	:
	inline void
	add_edge(size_t __u, size_t __v, _Tp __w)
	{ _add_elem(__u, __v, __w); }

	inline void
	add_edge_double(size_t __u, size_t __v, _Tp __w)
	{ _add_elem(__u, __v, __w); _add_elem(__v, __u, __w); }

	inline void
	add_edge_couple(size_t __u, size_t __v, _Tp __w)
	{ _add_elem(__u, __v, __w); _add_elem(__v, __u, 0); }

// 操作符：
public	: 
	inline void
	clear(size_t __n)
	{ _data[__n]->clear(); }

	void
	clear()
	{ REP(i,sz) _data[i]->clear(); }

	void
	Dijkstra(size_t __source, _Tp* __dist, bool* __used = 0)
	{
		bool __haveused = !!__used;
		if (!__haveused)
		{
			__used = new bool[size()];
			memset(__used, false, size() * sizeof(bool));
		}
		if (__used[__source]) return;

		__dist[__source] = 0;
		__used[__source] = 1;

		typedef pair<_Tp,size_t> mytype;
		priority_queue< mytype, vector<mytype>, greater<mytype> > __queue;
		TRV(i,at(__source)) __queue.push(mp(i->w, i->v));

		while (!__queue.empty())
		{
			_Tp __w = __queue.top().X;
			size_t __v = __queue.top().Y;
			__queue.pop();

			if (__used[__v]) continue;
			__used[__v] = true;
			__dist[__v] = __w;

			TRV(i,at(__v)) __queue.push(mp(__dist[__v]+i->w,i->v));
		}
		if (!__haveused) delete []__used;
	}

};

#endif	/* _TEMPLATE_GRAPH */
