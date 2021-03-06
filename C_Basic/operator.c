//
//  operator.c
//  C_Basic
//
//  Created by YunTu on 15/8/29.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>

void testOperator() {
    //在C系列中没有短路与, 逻辑与和短路与(java系列)
    int a = 10;
    if ((a > 10) & (a > 10 ? ++a : --a)) {    //按位与
        printf("a大于10\n");
    }else{
        printf("a小于10\n");
    }
    printf("a = %d\n", a);
    
    int b = 1 | 2;  // 按位或
    printf("b = %d\n", b);
    
    int c = (a < 10) & (a < 1);
    printf("c = %d\n", c);
    
    for (int i = 1; i < 5; i++) {
        int a = i << 16;
        printf("a = %d\n", a);
    }
    
    printf("or = %d\n", 1 | 4);
}

void testBitwiseOperator() {
    int i = 10;
    printf("%#X\n", i);         // 0X0000000A
    i = ~i;
    printf("%#X, %d\n", i, i);  // 0XFFFFFFF5   -11
    /**
     *  10 (二进制) --> 0000 1010
     *  0000 1010 (取反运算) --> 1111 0101 (十六进制)-->
     *  1111 0101 (十六进制) --> FFFFFFF5(因为是有符号数,第一位为符号位,1表示负数,所以此编码是负数的存储编码(补码))
     *  FFFFFFF5   (十进制) --> -11 (为什么是111原因见下)
     */
    
    i = -11;
    printf("%#X\n", i);         // 0XFFFFFFF5 --> 0X0000000B(源码的绝对值) 内存中负数用补码表示
    
    /**
     *  0XFFFFFFF5 --> 0X0000000B(源码的绝对值) 内存中负数用补码表示,取反加1得负数对应的绝对值
     *  0XFFFFFFF5 (二进制)        --> 1111 1111 1111 0101
     *  1111 1111 1111 0101 (取反) --> 0000 0000 0000 1010
     *  0000 0000 0000 1010 (加1)  --> 0000 0000 0000 1011  -->(十六进制)0X0000000B -->(十进制) |11| -->(去绝对值)-11
     *  0X0000000B (十六进制)       -->(十进制) |11| -->(去绝对值) -11
     */

    
    i = -10;
    printf("%#X\n", i);     // 0XFFFFFFF6 --> 1111 1111 1111 0110 内存中负数用补码表示
}

/**
 *  not运算的定义是把内存中的0和1全部取反。使用not运算时要格外小心，你需要注意整数类型有没有符号。如果not的对象是无符号整数（不能表示负数），那么得到的值就是它与该类型上界的差，因为无符号类型的数是用00到$FFFF依次表示的
 */
void testUnsignedBitwiseOperator() {
    unsigned short i = 10;
    printf("%#X\n", i);         // 0X0000000A
    i = ~i;
    printf("%#X, %d\n", i, i);  // 0XFFF5, 65525
    /**
     *  10 (二进制) --> 0000 1010
     *  0000 1010 (取反运算) --> 1111 0101
     *  1111 0101 (十六进制、十进制) --> F5, 65535 - 10 = 65525
     */
    
    
    i = -11;        // 无符号整形不应该存储负数的
    printf("%#X, %d\n", i, i);
    /**
     *  -11 (绝对值11的二进制)--> 0000 1011 
     *  0000 1011 (取反)--> 1111 0100 
     *  1111 0100 (加1)--> 1111 0101
     *  1111 0101 --> 65535 - 10 = 65525(因为是无符号短整形,所以直接按照此编码计算(个人理解))
     */
    
    i = -10;
    printf("%#X, %d\n", i, i);     // 0XFFF6, 65526 与上面的类似
}