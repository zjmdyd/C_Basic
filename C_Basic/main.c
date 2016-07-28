//
//  main.c
//  C_Basic
//
//  Created by YunTu on 15/8/29.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>

extern int a;   // 声明全局变量(用来声明已经定义过而且能够访问的变量)(在这种情况就下extern关键字可以省略)
//int a;
extern int b;

void testExtern();
void testStatic();
void testMathFunc();
void testExpression();
void testTimeFunc();
void testRand();
void testArray();

int main(int argc, const char * argv[]) {
    
#ifndef MAX
    a = 10;
    b = 20;         // 此b与static.c中得b不一样,因为其被static关键字修饰,外部不可见
    testExtern();   // a = 10
    testStatic();   // b = 0;
    
    printf("\n\n");
    testMathFunc();
    
    testExpression();
    testRand();
#endif
    
    testArray();

    return 0;
}

int a;  //定义全局变量, 如果在extern.c中定义变量，则在此就不能再定义,否则出现重复定义,
int b;

/*
 强调:声明和定义是两码事
 
 static和extern的总结:
 1.extern可以用来声明一个全局变量，但是不能用来定义变量
 
 2.默认情况下，一个全局变量是可以供多个源文件共享的，也就说，多个源文件中同名的全局变量都代表着同一个变量
 
 3.如果在定义全局变量的时候加上static关键字，此时static的作用在于限制该全局变量的作用域，只能在定义该全局变量的文件中才能使用，跟其他源文件中的同名变量互不干扰
 
 */
