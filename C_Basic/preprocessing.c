//
//  preprocessing.c
//  C_Basic
//
//  Created by YunTu on 15/9/14.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define NDEBUG  /*  不启用assert   */

/*
 启用assert
    #undef NDEBUG
 */

#include <assert.h>
/*
    我们把编辑的代码成为原文件，这是第一步，生成的文件后缀名为.c，这些原文件不能够直接运行，
    它们需要经过第二步编译，把源文件转换为以.obj为后缀名为后缀名的目标文件；目标文件
    经过第三步连接，最终生成以.exe为后缀名的可执行文件。
    
    预处理指令就是在程序编辑后编译前执行的指令。C语言提供有多重预处理功能，主要有宏定义、文件包含和条件编译等3种。
 */

#define M (x*x + 2*x)
#define TEN 10          /* 宏定义开始 */
/*
    在主函数中必须定义变量x,否则会编译出错,原因是红展开后程序中使用到变量x
 
 预编译的宏定义是宏代替一个字符串,只做简单置换，不做正确性检查，只有在编译已被宏展开后的源程序时，才会发现语法错误并报错
 */
void macroRange();
void marcoFunction();
void marcoMultiLine();
void conditionCompile();
void conditionCompile2();
void assertMacro();

void testExpression() {
    int sum , x = 2;
    
    sum = M;
    
    printf("sum = %d\n", sum);
    
    printf("TEN1 = %d\n", TEN);     // TEN1 = 10
    
    macroRange();
    marcoFunction();
    marcoMultiLine();
    conditionCompile();
    conditionCompile2();
    assertMacro();
}

#undef TEN              /* 宏定义结束 */

#define TEN 20

void macroRange() {
   printf("TEN2= %d\n", TEN);       // TEN1 = 20
}

#undef TEN

/***********
    宏函数
 #define 标识符(参数列表) 字符串
 ************/

#define PI 3.1415926
#define C(r) 2*PI*r
#define S(r) PI*r*r

//#define MAX(a, b) a>b?a:b --> upgrade
#define MAX(a, b) ((a)>(b)?(a):(b))
//#define MUL(a, b) (a*b) --> upgrade
#define MUL(a, b) ((a)*(b))

void marcoFunction() {
    int r = 5;
    printf("周长 = %f\n", C(r));
    printf("面积 = %f\n", S(5));
    
    int a = 3, b = 4, c = 5, d = 6;
    printf("%d", ++a);
    
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MAX(%d, %d) = %d\n", 1, 2, MAX(1, 2));
    
    printf("MUL(%d, %d) = %d\n", a, b, MUL(a, b));
    printf("MUL(%d, %d) = %d\n", a+b, c+d, MUL(a+b, c+d));
    
    printf("MAX = %d\n", MAX(++a, ++b));
}

#undef MAX

#define exchange(a, b) { \
    int t;\
    t = a;\
    a = b;\
    b = t;}

void marcoMultiLine() {
    int x = 10, y = 20;
    printf("交换前:x = %d, y = %d\n", x, y);
    
    exchange(x, y);
    
    printf("交换后:x = %d, y = %d\n", x, y);
}

/*
    文件包含
    include<> 和include""的区别:
 
    < >引用的是编译器的类库路径里面的头文件
    " "引用的是你程序目录的相对路径中的头文件, 如果没有，它还是会在对应的引用目录里面查找对应的头文件
 */

#pragma mark - 条件编译

/*
    条件编译:
形式一:
     #ifdef 标识符
         程序段1   (程序段可以使语句，也可以是命令行)
     #else
         程序段2
     #endif

 形式二:
     #ifndef 标识符
        程序段1   (程序段可以使语句，也可以是命令行)
     #else
        程序段2
     #endif

 形式一与形式二形式相同,内容相反, #else 都可以省略
 
 形式三:
     #if 表达式
        程序段1
     #else
        程序段2
     #endif
 形式三与前两种不同的是:此处需要先定义表达式，而前两种则需要定义宏
 
 
 #ifdef CPUSIZE16
    #define INTEGER 16
 #else
    #define INTEGER 32
 #endif
 
*/

#define MAX

#define MAXIMUM(x, y) (x>y)?x:y /*  宏定义求大数  */
#define MINIMUM(x, y) (x>y)?y:x /*  宏定义求大数  */

void conditionCompile() {
    int a = 10, b = 20;
#ifdef MAX
    printf("较大的数是:%d\n", MAXIMUM(a, b));
#else    
    printf("较小的数是:%d\n", MINIMUM(a, b));
#endif
    
#ifndef MIN
    printf("较小的数是:%d\n", MINIMUM(a, b));
#else 
    printf("较大的数是:%d\n", MAXIMUM(a, b);
    
#endif
    
#undef MAX
    
}

#define CHARACTER 1     /*  定义宏CHARACTER    */

/*
 CHARACTER 为1时把大写转换为小写, 为0时把小写转换为大写
 */

void conditionCompile2() {
    char c, str[20] = "Hello World";
    
    int i = 0;
    while ((c = str[i]) != '\0') {
        i++;
#if CHARACTER
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
#else
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
#endif
        printf("%c", c);
    }
    printf("\n");
    
#ifdef DEBUG
    printf("DEBUG已经定义:%d\n", DEBUG);
#endif
}
           

void assertMacro() {
    int a = 10, b = 20;
    assert(a == b);     // SIGABRT 终止信号
//    abort();    // 异常终止一个进程
    
#ifndef MAX
    printf("a+b = %d\n", a+b);
#endif
    
}

    #define __CONCAT(x,y)   x ## y
/*
 预处理运算符:
 # （单井号）    —— 字符串化运算符。
 ## （双井号 ）  —— 连接运算符
 #@            —— 字符化运算符。 (用于创建一个字符，类似 ## ，注： 非 ANSI-C中的特性，GCC不支持，VC可以)
 
#define Dump_Char(c)  #@c
void tests() {
printf("%c\n",Dump_Char(g)); //g
}
*/






