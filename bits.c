/* 
 * CS:APP Data Lab 
 * 
 * <Wang, Chen 16307110064>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    /*
     * This question is the binary version of De Morgan's laws.
     * De Morgan's laws can be states as follows:
     * P AND Q = NOT(NOT P OR NOT Q)
     * */
    return ~(~x | ~y);
}

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /*
     * First shift right the given integer corresponding
     * number of bits according to the specified n;
     * And then use a switch to wipe off the redundant
     * bits on the left.
     * */
    int initialMask = 0xFF;
    int hexadecimalBias = n;
    int binaryBias = hexadecimalBias << 3;
    int biasedMask = initialMask << binaryBias;
    int result = x & biasedMask;
    result = result >> binaryBias;
    result = result & initialMask;
    return result;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    /*
     * The core of the algorithm is to generate a specified mask to
     * wipe out the ones on the left end left by the arithmetic shift
     * !!n is used to generate a whole one mask if 0 is get by input.
     * Then the single digit mask is shifted according to the specified shifting
     * digit to generate the final mask.
     * */
    int baseMask = !!n;
    int leftBiasedSingleOne = baseMask << (32 + (~n + 1));
    int mask = leftBiasedSingleOne + (~1 + 1);
    int result = x >> n;
    result = result & mask;
    return result;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /*
     * Use different masks to add the ONEs from a smaller scope though the global scope
     * First in the char level (i.e. each four bits) and then gradually double the scope
     * until all the sums come into the same scope.
     * */
    int charLevelMaskBase_Byte = 0x11;
    int charLevelMaskBase_Short = (charLevelMaskBase_Byte << 8) + charLevelMaskBase_Byte;
    int charLevelMask = (charLevelMaskBase_Short << 16) + charLevelMaskBase_Short;
    int byteLevelMaskBase_Byte = 0x0F;
    int byteLevelMaskBase_Short = (byteLevelMaskBase_Byte << 8) + byteLevelMaskBase_Byte;
    int byteLevelMask = (byteLevelMaskBase_Short << 16) + byteLevelMaskBase_Short;
    int shortLevelMaskBase_Short = 0xFF;
    int shortLevelMask = (shortLevelMaskBase_Short << 16) + shortLevelMaskBase_Short;
    int intLevelMask = (0xFF << 8) + 0xFF;
    int sum;
    sum = (x & charLevelMask) + ((x >> 1) & charLevelMask) + ((x >> 2) & charLevelMask) + ((x >> 3) & charLevelMask);
    sum = (sum & byteLevelMask) + ((sum >> 4) & byteLevelMask);
    sum = (sum & shortLevelMask) + ((sum >> 8) & shortLevelMask);
    sum = (sum & intLevelMask) + ((sum >> 16) & intLevelMask);
    return sum;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    /*
     * The sign bits of any number and its opposite number other than ZERO has
     * at least one 1, while the sign bits of both zero and its opposite number
     * is 0. This function works under this phonomenen.
     * */
    int oppositeOfX = ~x + 1;
    int result = (x >> 31) | (oppositeOfX >> 31);
    result = result + 1;
    return result;
}

/*
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    /*
     * The minimum two's complement integer is 0x80000000
     * */
    return 0x80 << 24;
}

/*
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /*
     * Determin whether an integer remains the same when
     * only specified digits of numbers are used to denote
     * the number.
     * */
    int bias = 32 + (~n + 1);
    int result = !(x ^ ((x << bias) >> bias));
    return result;
}

/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /*
     * In the case of a negative number, a ONE will be added to
     * the shifted number iff the negative number has a remainder
     * during the shifting process.
     * */
    int remainder = x << (32 + (~n + 1));
    int remainderExists = !!remainder;
    int sign = (x >> 31) & remainderExists;
    int shiftedNumber = x >> n;
    int biasForNeg = shiftedNumber + (sign & (!!n));
    return biasForNeg;
}

/*
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    /*
     * This is the formula for the two's complement integer
     * denotion.
     * */
    return (~x + 1);
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    /*
     * The result is 1 when the sign bit is 0 but
     * the number is not 0
     * */
    int signBit = (x >> 31) & 0x1;
    int isZero = !x;
    return !(signBit | isZero);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    /*
     * The question is devided into two parts:
     * If x and y have different signs, then the
     * result is instantly reachable;
     * If x and y have the same sign, then  the result can
     * be got by operating y minus x.
     * */
    int xSignFull = x >> 31;
    int ySignFull = y >> 31;
    int isDifferentSign = xSignFull ^ySignFull;
    int differentSignCase = xSignFull & (!ySignFull);
    int sameSignCase = !((y + (~x + 1)) >> 31);
    return (differentSignCase & isDifferentSign) | (sameSignCase & (!isDifferentSign));
}

/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

    /*
     * To find out where the most significant ONE is,
     * dichotomy is used to simplify the code and to fin the result
     * in the shortest lines. Each time the range is devided, the result,
     * the logCount variable adds the result whether there is nor not ONEs
     * in the corresponding range.
     * */

    int testMark;
    int shiftOperand;
    int shrinkedResult;
    int logCount = 0;


    testMark = !!(x >> 16);
    shiftOperand = testMark << 4;
    shrinkedResult = x >> shiftOperand;
    logCount += shiftOperand;


    testMark = !!(shrinkedResult >> 8);
    shiftOperand = testMark << 3;
    shrinkedResult = shrinkedResult >> shiftOperand;
    logCount += shiftOperand;


    testMark = !!(shrinkedResult >> 4);
    shiftOperand = testMark << 2;
    shrinkedResult = shrinkedResult >> shiftOperand;
    logCount += shiftOperand;


    testMark = !!(shrinkedResult >> 2);
    shiftOperand = testMark << 1;
    shrinkedResult = shrinkedResult >> shiftOperand;
    logCount += shiftOperand;


    testMark = !!(shrinkedResult >> 1);
    shiftOperand = testMark;
    logCount += shiftOperand;


    return logCount;
}

/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    /*
     * Xor is used to negate the highest bit;
     * Comparision is used to determine whether a
     * number is NaN
     * */
    int oneOnLeftEnd = 1 << 31;
    int fullOneExceptSignBit = ~oneOnLeftEnd;
    int exponentAndFractionBits = uf & fullOneExceptSignBit;
    if (exponentAndFractionBits > 0x7F800000)
        return uf;
    else
        return uf ^ oneOnLeftEnd;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    /*
     * The component of the float number is
     * 1 sign bit + 8 exponent bits + 23 fraction bits.
     * Sign bit can be get easily by quering the original sign bit;
     * exponent bit queries the highest bit position in the int;
     * fraction is the remainders after removing the 1 at the highest position;
     * 0 is the exception and residuals needs caring about.
     * */

    unsigned int signBit = 0U;
    unsigned int exponentBits = 31U;
    unsigned int fractionBits;
    unsigned int zero = 0x0U;
    unsigned int signBitMask = 0x80000000U;
    if (x == zero) return zero;
    if (x & signBitMask) {
        signBit = 0x80000000u;
        x = -x;
    }
    while (!(x & signBitMask)) {
        exponentBits--;
        x <<= 1;
    }
    fractionBits = ((x & 0x7FFFFFFFU) >> 8);
    if (((x & 0x1FFU) == 0x180) || ((x & 0xFFU) > 0x80))
        fractionBits += 1;
    return (signBit | ((exponentBits + 127) << 23)) + fractionBits;
}

/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

    /*
     * The core is to add the exponent part by one;
     * exceptions are when the number is NaN,
     * and when the exponent part is 0.
     * */
    unsigned int exponentBitsMask;
    unsigned int exponentAndFractionMask;
    unsigned int signBitMask;
    unsigned int exponentBitOne;
    unsigned int exponentBits;
    unsigned int signBit;
    unsigned int result;

    exponentBitsMask = 0x7F800000U;
    exponentAndFractionMask = 0x7FFFFFFFU;
    signBitMask = 0x80000000U;
    exponentBitOne = 0x800000U;
    exponentBits = uf & exponentBitsMask;
    signBit = (signBitMask & uf);

    if ((uf & exponentAndFractionMask) >= exponentBitsMask)
        result = uf;
    else if (exponentBits == 0)
        result = (uf << 1) | signBit;
    else result = uf + exponentBitOne;
    return result;
}