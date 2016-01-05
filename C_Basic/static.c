//
//  static.c
//  Extern_Static
//
//  Created by YunTu on 15/4/22.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>

static int b;

void testStatic(){
    printf("static.c中的b = %d\n", b);
}