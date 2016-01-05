//
//  enumeration.c
//  C_Basic
//
//  Created by YunTu on 15/8/29.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

enum Status {
    CLOSE,
    OPEN
};

#include <stdio.h>

void testMacro() {
    
    enum Status a = CLOSE;
    printf("a = %d", a);
}