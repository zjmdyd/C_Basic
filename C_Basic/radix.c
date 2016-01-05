//
//  radix.c
//  C_Basic
//
//  Created by YunTu on 15/8/31.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void testRadix() {
    int i = 480;
    printf("i的十六进制 :%#X\n", i);     // i的十六进制 :0X20
    
    //十六进制转十进制
    char *str = "0x0010";
    unsigned long j = strtoul(str , 0, 16);
    printf("j = %ld", j);               // j = 16
    
    //十进制转十六进制
}

/*
 unsigned long strtoul(const char *nptr,char **endptr,int base);
 
 strtoul()会将参数nptr字符串根据参数base来转换成无符号的长整型数。参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制数等。当base值为0时会根据情况选择用哪种进制：如果第一个字符是'0'，就判断第二字符如果是‘x’则用16进制，否则用8进制；第一个字符不是‘0’，则用10进制。一开始strtoul()会扫描参数nptr字符串，跳过前面的空格字符串，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回。
 */