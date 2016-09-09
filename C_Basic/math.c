//
//  math.c
//  C_Basic
//
//  Created by YunTu on 15/8/29.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void testMathFunc() {
    /**
     *  modf(double x, double *ptr)
     *  功能:分解x，以得到x的整数部分和小数部分,ptr最后保留的是x的整数部分
     *  返回值:x的小数部分
     */
    
    double p = 0, q;
    q = modf(123.45, &p);
    printf("p = %f, q = %f\n", p, q);
    
#ifndef MAX
     double x = 10.0;
     printf("%lf\n", log10(x));
     printf("%lf\n", log(2.7));     // 计算以e为底的对数
    
    printf("\n\n");
    /*
        atan2(y, x):用来计算y/x的反正切值, 返回值范围 : (-pi/2,pi/2)
        不完全等于y/x, 因为atan2(y, x)中x可为0
     */
    printf("%f\n", atan2(1, sqrt(3)));    // pi/6
    printf("%f\n", atan2(1, 1));          // pi/4
    printf("%f\n", atan2(sqrt(3), 1));    // pi/3
    printf("%f\n", atan2(1, 0));          // pi/2
    printf("%f\n", atan2(1, -1));         // pi*3/2
    printf("%f\n", atan2(2, 0));          // pi/2

    printf("pi/6 = %f\n", M_PI/6);
    printf("pi/4 = %f\n", M_PI_4);
    printf("pi/3 = %f\n", M_PI/3);
    printf("pi/2 = %f\n", M_PI_2);
#endif
}