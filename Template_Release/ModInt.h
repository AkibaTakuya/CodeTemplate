/*
 *	Name : 64-bit Unsigned Auto-modulo Integer 64位无符号自取模整型
 *	Copyright : www.fateud.com
 *
 *	模板参数：
 *	ModInt <_Key>
 *		限定模值 _Key，a ≡ b (mod _Key)，默认为 1000000007
 *
 *	成员函数：
 *	ModInt()
 *		初始数据为 0
 *	ModInt(uInt64 data)
 *		初始数据为 data 对 m 取模的结果
 *
 *	元素访问：
 *	get(void) const ： uInt64
 *		获得存储的值
 *
 *	修改符：
 *	set(const uInt64 data) ： ModInt &
 *		修改存储的值为 data
 *
 *	运算符重载：
 *		支持普通操作：+, +=, -, -=, *, *=, =
 *		支持读取数据：*
 *
 */

#ifndef _TEMPLATE_MODINT
#define _TEMPLATE_MODINT 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <uInt64 _Key = 1000000007ull>
class ModInt {
// Name : ModInt 64位无符号自取模整型
// Copyright : www.fateud.com
public	:
	typedef ModInt<_Key>		_Self;
	typedef uInt64				value_type;
	typedef uInt64 &			reference;
private	:
	value_type _data;
public	:
    ModInt(void) : _data() { }
	ModInt(value_type __data) : _data(__data % _Key) { }
	inline value_type get(void) const { return (*this)._data; }
	inline _Self & set(const value_type __data) { _data = __data % _Key; return (*this); }
	reference operator * () { return _data; }
	_Self & operator = (const value_type __data) { return set(__data); }
	_Self & operator += (const _Self other) { if ((_data += other._data) >= _Key) _data -= _Key; return (*this); }
	_Self &	operator -= (const _Self other) { if ((_data += _Key - other._data) >= _Key) _data -= _Key; return (*this); }
	_Self & operator *= (const _Self other) { _data = _data * other._data % _Key; return (*this); }
	_Self operator + (const _Self other) const { return ModInt(*this) += other; }
	_Self operator - (const _Self other) const { return ModInt(*this) -= other; }
	_Self operator * (const _Self other) const { return ModInt(*this) *= other; }
};

#endif /* _TEMPLATE_MODINT */
