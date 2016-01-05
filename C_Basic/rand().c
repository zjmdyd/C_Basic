//
//  rand().c
//  ZJCommand
//
//  Created by MCONE on 14-11-17.
//  Copyright (c) 2014年 MCONE. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testRand() {
    printf("max = %f\n", RAND_MAX+1.0);
    
    //未设置随机数种子
    for (int i = 0; i < 10; i++) {
        printf("%d ", rand()%10);
    }
    printf("\n\n");
    
    //设置随机数种子
    srand((int)time(0));
    for (int i = 0; i < 10; i++) {
        printf("%d ", rand()%10);
    }
    int i = 0;
    printf("\n&i = %p\n", &i);
    
    ushort us[3];
    double a = erand48(us);
    printf("a = %lf\n", a);
    for (int i = 0; i < sizeof(us) / sizeof(ushort); i++) {
        printf("us[%d] = %d\n", i, us[i]);
    }
}
/*
 
 10 * rand() / ( RAND_MAX + 1.0 )
 
 10*(1~100) / (100+1.0)
 === 0 ~ 9
 */
