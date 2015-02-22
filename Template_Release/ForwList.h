/*
 *	Name : Forward List 前向链表
 *	Copyright : www.fateud.com
 *
 *	模板参数：
 *	ForwList <_Tp>
 *		限定元素的类型 _Tp
 *
 *	成员函数：
 *	ForwList()
 *		初始一个根部迭代器
 *	~ForwList()
 *		清除所有元素
 *
 *	迭代器:
 *	begin() const ： iterator
 *		返回起始迭代器
 *	end() const ： iterator
 *		返回终止迭代器
 *	root() const ： iterator
 *		返回根部迭代器
 *
 *	职能:
 *	empty() const : bool
 *		检测容器是否为空
 *
 *	元素访问:
 *	front() : _Tp &
 *		起始元素的引用
 *	front() const : const _Tp &
 *		起始元素的值
 *
 *	修改符:
 *	insert(iterator pos, const _Tp & data) ： void
 *		在 pos 后插入元素 data
 *	erase(iterator pos) : bool
 *		删除 pos 后的元素，返回是否成功
 *	push_front(_Tp data) : void
 *		在头部插入元素 data
 *	clear() : void
 *		清除所有非根部元素
 *
 *	操作符：
 *	reserve() : void
 *		倒置所有元素的顺序
 *
 */

#ifndef _TEMPLATE_FORWLIST
#define _TEMPLATE_FORWLIST 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif	/* _TEMPLATE_STANDARD */

template <typename _Tp> class _ForwList_node;
template <typename _Tp> class _ForwList_iterator;
template <typename _Tp> class ForwList;

template <typename _Tp>
class _ForwList_node {
public	:
	friend class _ForwList_iterator<_Tp>;
	friend class ForwList<_Tp>;
	typedef _ForwList_node<_Tp>		_Self;
	typedef _Tp						value_type;
private	:
	value_type _data; _Self* _next;
public	:
	_ForwList_node() : _data(), _next() { }
	explicit _ForwList_node(value_type __data) : _data(__data), _next() { }
	explicit _ForwList_node(value_type __data, _Self* __next) : _data(__data), _next(__next) { }
};

template <typename _Tp>
class _ForwList_iterator {
public	:
	friend class ForwList<_Tp>;
	typedef _ForwList_iterator<_Tp>		_Self;
	typedef _ForwList_node<_Tp>			_Node;
	typedef _Tp *						pointer;
	typedef _Tp &						reference;
private	:
	_Node* _node;
public	:
	_ForwList_iterator() : _node() { }
	explicit _ForwList_iterator(_Node* __target) : _node(__target) { }
	reference operator * () const { return _node->_data; }
	pointer operator -> () const { return &(_node->_data); }
	_Self & operator ++ () { _node = _node->_next; return *this; }
	_Self operator ++ (int) { _Self __res(*this); _node = _node->_next; return __res; }
	bool operator == (const _Self& other) const { return _node == other._node; }
	bool operator != (const _Self& other) const { return _node != other._node; }
};

template <typename _Tp>
class ForwList {
// Name : ForwList 前向链表
// Copyright : www.fateud.com
public	:
	typedef _ForwList_node<_Tp>			_Node;
	typedef _ForwList_iterator<_Tp>		iterator;
	typedef _Tp							value_type;
	typedef _Tp &						reference;
private	:
	_Node* _node;
public	:
	ForwList() : _node(new _Node()) { }
	~ForwList() { clear(); delete _node; }
	inline iterator begin() const { return iterator(_node->_next); }
	inline iterator end() const { return iterator(NULL); }
	inline iterator root() const { return iterator(_node); }
	inline bool empty() const { return _node->_next ? false : true; }
	inline reference front() { return _node->_next._data; }
	inline const reference front() const { return _node->_next._data; }
	void insert(iterator __pos, const value_type& __data) { _Node* __tmp = new _Node(__data, __pos._node->_next); __pos._node->_next = __tmp; }
	bool erase(iterator __pos) { if ((!__pos._node) || (!__pos._node->_next)) return false; _Node* __tmp = __pos._node->_next->_next; delete __pos._node->_next; __pos._node->_next = __tmp; return true; }
	inline void push_front(value_type __data) { this->insert(root(), __data); }
	void clear() { _Node* __node = _node->_next; while (__node) { _Node* __tmp = __node->_next; delete __node; __node = __tmp; } _node->_next = 0; }
	void reserve() { _Node* __node = _node->_next; _node->_next = 0; while (__node) { _Node* __tmp = __node->_next; __node->_next = _node->_next; _node->_next = __node; __node = __tmp; } }
};

#endif /* _TEMPLATE_FORWLIST */
