/*
 * stdTypes.h
 *
 *  Created on	: Nov 8, 2021
 *  Author		: Mahmoud Khaled
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

/*typedef <dataType> <newName>*/

typedef unsigned char           u8   ; //uint_8 // uint8_t
typedef unsigned short int      u16  ;
typedef unsigned long int       u32  ;
typedef unsigned long long int  u64  ;

typedef signed char             s8   ;
typedef signed short int        s16  ;
typedef signed long int         s32  ;
typedef signed long long int	s64  ;

typedef float                   f32  ;
typedef double                  f64  ;
typedef long double             f80  ;

#define NULL		(void*)0

#endif /* STDTYPES_H_ */
