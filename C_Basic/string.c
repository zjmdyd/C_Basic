//
//  string.c
//  C_Basic
//
//  Created by YunTu on 15/8/29.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void testStringFunc() {
    char string[17];
    char *ptr;
    strcpy(string, "This is a string");
    ptr = strchr(string, 105);   //返回首次出现该字符(对应的ASCII码)的位置
    printf("%s\n", ptr);
}