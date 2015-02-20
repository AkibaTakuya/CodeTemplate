/*
 *	Name : Matrix ����
 *	Copyright : www.fateud.com
 *
 *	ģ�������
 *	Matrix <_Tp, _Sz>
 *		�޶�������������� _Tp
 *		�޶�����������С _Sz
 *
 *	��Ա������
 *	Matrix()
 *		�߶�Ϊ _Sz�����Ϊ _Sz �ľ���
 *	Matrix(size_t h, size_t w)
 *		�߶�Ϊ h�����Ϊ w �ľ���
 *	static basic(size_t n) : Matrix
 *		���һ����СΪ n x n �Ļ����������Խ����Ͻ�Ϊ 1
 *	static basic(const Matrix& target) : Matrix
 *		���һ���߳��� target �߶���ͬ�Ļ�������
 *
 *	ְ�ܣ�
 *	height() const : size_t
 *		��þ���ĸ߶� h
 *	width() const : size_t
 *		��þ���Ŀ�� w
 *
 *	Ԫ�ط��ʣ�
 *	at(size_t x, size_t y) : _Tp &
 *		������ [x, y] ��Ԫ�ص�����
 *	at(size_t x, size_t y) const : const _Tp
 *		������ [x, y] ��Ԫ�ص�ֵ
 *
 *	�޸ķ���
 *	clear() : void
 *		������������Ԫ������Ϊ 0
 *
 *	��������أ�
 *		֧����ͨ������+, +=, *, *=
 *		֧�ֳ˷�������^
 *
 */

#ifndef _TEMPLATE_MATRIX
#define _TEMPLATE_MATRIX 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <typename _Tp, size_t _Sz>
class Matrix {
// Name : Matrix ����
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
