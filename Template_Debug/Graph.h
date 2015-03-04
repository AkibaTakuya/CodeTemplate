/*
 *	Name : Directed Graph ����ͼ
 *	Copyright : www.fateud.com
 *	
 *	ģ�������
 *	Graph <_Tp>
 *		�޶�Ȩֵ������ _Tp
 *
 *	��Ա������
 *	Graph()
 *		��ʼһ���յ�ͼ
 *	Graph(size_t _Sz)
 *		��ʼһ�� _Sz �������ͼ
 *	~Graph()
 *		���ͼ������Ԫ��
 *	
 *	��������
 *	size_t v;
 *		ָ�򶥵� v
 *	_Tp w;
 *		ȨֵΪ w
 *
 *	ְ�ܣ�
 *	size() const : const size_t
 *		���ض��������
 *	resize(size_t Sz) : void
 *		���ͼ, �����޶����������
 *	
 *	Ԫ�ط��ʣ�
 *	operator [] (size_t n) : ForwList<..> &
 *		���ص� n �������ǰ�����������
 *	operator [] (size_t n) const : const ForwList<..> &
 *		���ص� n �������ǰ�������ֵ
 *	at (size_t n) �� ForwList<..> &
 *		���ص� n �������ǰ�����������
 *	at (size_t n) const �� const ForwList<..> &
 *		���ص� n �������ǰ�������ֵ
 *	
 *	�޸ķ���
 *	add_edge(size_t u, size_t v, _Tp w) : void
 *		���һ�� u ָ�� v ȨֵΪ w �������
 *	add_edge_double(size_t u, size_t v, _Tp w) : void
 *		���һ�� u ָ�� v ȨֵΪ w �������
 *	add_edge_couple(size_t u, size_t v, _Tp w) : void
 *		���һ�� u ָ�� v ȨֵΪ w �����򻡵������
 *	push_back(size_t n) : void
 *		���� n ������
 *	flush(size_t n) : void
 *		������� n ���������б�
 *	flush() : void
 *		���ͼ�����б�
 *	clear() : void
 *		���ͼ�����ж���ͱ�
 *
 *	��������
 *	Dijkstra(size_t s, _Tp* dist, bool* used = 0) : void
 *		����Դ��Ϊ s ʱ��ͼ�ĵ�Դ���·,
 *		used �����ʾĳ�����Ƿ����,
 *		��������� dist ���飬0 ��ʾ��·.
 *	Hungary(int* __used = 0) �� int
 *		�������ͼ�����ƥ����,
 *		used �����ʾĳ�����ƥ����Ϊ˭.
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
// ��Ա���壺
public  :
	typedef _Graph_base<_Tp>		_Self;
	typedef _Tp						value_type;

// ��Ա������
public	:
	size_t v;
	value_type w;

// ��Ա������
public	:
	_Graph_base()
	: v(), w() { }
	_Graph_base(size_t __v, value_type __w)
	: v(__v), w(__w) { }

// ���������أ�
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
// Name : Graph ����ͼ
// Copyright : www.fateud.com

// ��Ա���壺
public	:
	typedef Graph<_Tp>				_Self;
	typedef _Graph_base<_Tp>		_Base;
	typedef ForwList<_Base>			_Node;
	typedef _Node					value_type;
	typedef _Node *					pointer;
	typedef _Node &					reference;

// ��Ա������
private	:
	vector<pointer> _data;

// ��Ա������
public	:
	Graph()
	: _data() { }

	explicit
	Graph(size_t _Sz)
	: _data( vector<pointer>(_Sz) )
	{ REP(i, _Sz) _data[i] = new value_type(); }

	~Graph()
	{ clear(); }

// ְ�ܣ�
public	:
	const size_t
	size() const
	{ return _data.size(); }

	void
	resize(size_t __Sz)
	{
		clear();
		push_back(__Sz);
	}

// Ԫ�ط��ʣ�
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

// �޸ķ���
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
	{
		_add_elem(__u, __v, __w);
		_add_elem(__v, __u, __w);
	}

	inline void
	add_edge_couple(size_t __u, size_t __v, _Tp __w)
	{
		_add_elem(__u, __v, __w);
		_add_elem(__v, __u, 0);
	}

	void
	push_back(size_t __n)
	{ REP(i, __n) _data.inb(new value_type()); }

	void
	flush(size_t __n)
	{ _data[__n]->clear(); }

	void
	flush()
	{ REP(i,sz) _data[i]->clear(); }

	void
	clear()
	{
		RREP(i,sz) delete _data[i];
		_data.clear();
	}

// ��������
public	:
	void
	Dijkstra(size_t __source, _Tp* __dist, bool* __used = 0)
	{
		bool __haveused = !!__used;
		memset(__dist, 0, size() * sizeof(_Tp));
		if (!__haveused)
		{
			__used = new bool[size()];
			memset(__used, false, size() * sizeof(bool));
		}
		if (__used[__source]) return;

		__dist[__source] = 0;
		__used[__source] = 1;

		typedef pair<_Tp, size_t> mytype;
		priority_queue< mytype, vector<mytype>, greater<mytype> > __queue;
		TRV(i, at(__source)) __queue.push(mp(i->w, i->v));

		while (!__queue.empty())
		{
			_Tp __w = __queue.top().X;
			size_t __v = __queue.top().Y;
			__queue.pop();
			if (__used[__v]) continue;

			__dist[__v] = __w;
			__used[__v] = true;
			TRV(i, at(__v)) __queue.push(mp(__dist[__v] + i->w, i->v));
		}
		if (!__haveused) delete []__used;
	}

	int
	Hungary(int* __used = 0)
	{
		bool __haveused = !!__used;
		if (!__haveused) {
			__used = new int[size()];
			memset(__used, 0xff, size() * sizeof(int));
		}

		bool* __vist = new bool[size()];
		memset(__vist, 0x00, size() * sizeof(bool));

		struct _Hungary_find
		{
			_Self* _g;
			bool* _vist;
			int* _used;

			explicit
			_Hungary_find(_Self* __g, bool* __vist, int* __used)
			: _g(__g), _vist(__vist), _used(__used) { }

			bool
			operator () (int u) {
				TRV(i, _g->at(u)) {
					int v = i->v;
					if (_vist[v]) continue;
					_vist[v] = true;
					if (_used[v] == -1 || (*this)(_used[v])) {
						_used[u] = v;
						_used[v] = u;
						return true;
					}
				}
				return false;
			}
		};

		_Hungary_find __find(this, __vist, __used);
		int __res = 0;
		REP(i, size()) {
			memset(__vist, 0x00, size() * sizeof(bool));
			__res += __find(i);
		}
		return __res;
	}
};

#endif	/* _TEMPLATE_GRAPH */
