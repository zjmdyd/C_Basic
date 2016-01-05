//
//  time.c
//  C_Basic
//
//  Created by YunTu on 15/9/15.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

/**
 *  struct timeval {
 　　      time_t tv_sec;
 　　      suseconds_t tv_usec;
 　　};
    其中返回的timeval值为Epoch（00:00:00 1970-01-01 UTC）到创建struct timeval时的时间，tv_sec为秒数部分，tv_usec为微秒数部分（10的-6次方秒）。
    比如当前程序运行的tv_sec为1244770435，tv_usec为442388，即当前时间距Epoch时间1244770435秒，442388微秒。
 
 
 timespec
 
 struct timespec
 {
    time_t tv_sec;
    long int tv_nsec;
 };
 
 与struct timeval 不同，将结构体内成员微秒变换成纳秒
 
 */
#include <stdio.h>
#include <time.h>

void testTimeFunc() {
    time_t t;
    time_t a = time(&t);
    printf("a = %ld\nt = %ld\n", a, t);
}