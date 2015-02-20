/*
 *	Name : 64-bit Unsigned Auto-modulo Integer 64λ�޷�����ȡģ����
 *	Copyright : www.fateud.com
 *
 *	ģ�������
 *	ModInt <_Key>
 *		�޶�ģֵ _Key��a �� b (mod _Key)��Ĭ��Ϊ 1000000007
 *
 *	��Ա������
 *	ModInt()
 *		��ʼ����Ϊ 0
 *	ModInt(uInt64 data)
 *		��ʼ����Ϊ data �� m ȡģ�Ľ��
 *
 *	Ԫ�ط��ʣ�
 *	get(void) const �� uInt64
 *		��ô洢��ֵ
 *
 *	�޸ķ���
 *	set(const uInt64 data) �� ModInt &
 *		�޸Ĵ洢��ֵΪ data
 *
 *	��������أ�
 *		֧����ͨ������+, +=, -, -=, *, *=, =
 *		֧�ֶ�ȡ���ݣ�*
 *
 */

#ifndef _TEMPLATE_MODINT
#define _TEMPLATE_MODINT 1

#ifndef _TEMPLATE_STANDARD
#include <standard.h>
#endif 	/* _TEMPLATE_STANDARD */

template <uInt64 _Key = 1000000007ull>
class ModInt {
// Name : ModInt 64λ�޷�����ȡģ����
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
