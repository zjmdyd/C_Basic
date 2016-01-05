//
//  extern.c
//  Extern_Static
//
//  Created by YunTu on 15/4/21.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>

extern int a;  // 声明全局变量

void testExtern() {
    printf("extern.c中的a = %d\n", a);
}


