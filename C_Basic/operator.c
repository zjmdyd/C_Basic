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
        printf("a大于10");
    }else{
        printf("a小于10");
    }
    printf("a = %d", a);
    
    int b = 1 | 2;  // 按位或
    printf("b = %d", b);
    
    int c = (a < 10) & (a < 1);
    printf("c = %d", c);
    
    for (int i = 1; i < 5; i++) {
        int a = i << 16;
        printf("a = %d", a);
    }
    
    printf("or = %d", 1 | 4);
}