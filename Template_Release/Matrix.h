/*
 *	Name : Matrix 矩阵
 *	Copyright : www.fateud.com
 *
 *	模板参数：
 *	Matrix <_Tp, _Sz>
 *		限定矩阵的数据类型 _Tp
 *		限定矩阵的数组大小 _Sz
 *
 *	成员函数：
 *	Matrix()
 *		高度为 _Sz，宽度为 _Sz 的矩阵
 *	Matrix(size_t h, size_t w)
 *		高度为 h，宽度为 w 的矩阵
 *	static basic(size_t n) : Matrix
 *		获得一个大小为 n x n 的基本矩阵，正对角线上皆为 1
 *	static basic(const Matrix& target) : Matrix
 *		获得一个边长与 target 高度相同的基本矩阵
 *
 *	职能：
 *	height() const : size_t
 *		获得矩阵的高度 h
 *	width() const : size_t
 *		获得矩阵的宽度 w
 *
 *	元素访问：
 *	at(size_t x, size_t y) : _Tp &
 *		矩阵中 [x, y] 处元素的引用
 *	at(size_t x, size_t y) const : const _Tp
 *		矩阵中 [x, y] 处元素的值
 *
 *	修改符：
 *	clear() : void
 *		将矩阵内所有元素重置为 0
 *
 *	运算符重载：
 *		支持普通操作：+, +=, *, *=
 *		支持乘方操作：^
 *
 */

#ifndef _TEMPLATE_MATRIX
#define _TEMPLATE_MATRIX 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <typename _Tp, size_t _Sz>
class Matrix {
// Name : Matrix 矩阵
// Copyright : www.fateud.com
public	:
	typedef Matrix<_Tp, _Sz>		_Self;
	typedef _Tp						value_type;
	typedef _Tp &					reference;
private	:
	size_t _h, _w;
	value_type _data[_Sz][_Sz];
public	:
	Matrix() : _h(_Sz), _w(_Sz) { clear(); }
	Matrix(size_t __h, size_t __w) : _h(__h), _w(__w) { clear(); }
	static _Self basic(size_t __n) { _Self __res(__n, __n); REP(i,__n) __res._data[i][i] = 1; return __res; }
	inline static _Self basic(const _Self& target) { return basic(target._h); }
	inline size_t height() const { return _h; }
	inline size_t width() const { return _w; }
	inline reference at(size_t x, size_t y) { return _data[x][y]; }
	inline const value_type at(size_t x, size_t y) const { return _data[x][y]; }
	inline void clear() { CLEAR(_data, 0x00); }
	_Self & operator += (const _Self other) { REP(i,_h) REP(j,_w) at(i,j) += other.at(i,j); return (*this); }
	_Self & operator *= (const _Self other) { _Self __res(_h, other._w); REP(i,__res._h) REP(j,__res._w) REP(k,_w) __res.at(i,j) += (*this).at(i,k) * other.at(k,j); *this = __res; return (*this); }
	_Self operator + (const _Self other) const { return _Self(*this) += other; }
	_Self operator * (const _Self other) const { return _Self(*this) *= other; }
	_Self operator ^ (uInt64 __k) { _Self n = *this, __res = basic(*this); while (__k) { if (__k & 1) __res *= n; n *= n, __k >>= 1; } return __res; }
};

#endif /* _TEMPLATE_MATRIX */
