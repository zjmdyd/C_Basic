//
//  average.c
//  commandLine
//
//  Created by YunTu on 15/3/16.
//  Copyright (c) 2015年 YunTu. All rights reserved.
//

#include <stdio.h>

void testE() {
    int a[] = {1.528086, -1.461649, 0.531508, 1.195894, -1.461649, -0.797263, 0.531508, -1.129456, -0.797263, -0.132878, -0.465070, -0.797263, 0.531508, -0.132878, 1.860279, 0.863701, -0.465070, 1.793842, 0.531508, 1.860279};
    
    int len = sizeof(a)/sizeof(int);
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }
    printf("average = %lf\n", sum/len);
    
    //十进制科学计数法
    float m = 2.0e3;   //e表示10的n次方(+表示正 -表示负, 默认、缺省情况下为正)
    printf("m = %f\n", m);  // m = 2000.000000
    
    //十六进制科学计数法
    float n = 0x2p2;    //p表示2的n次方,其余的同十进制科学计数法
    printf("n = %f\n", n);  // n = 8.000000
}
