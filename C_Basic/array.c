//
//  array.c
//  C_Basic
//
//  Created by ZJ on 1/5/16.
//  Copyright © 2016 YunTu. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>

void testArray() {
    printf("\n\n\n");
    int *a[3];
    int i = 2;
    a[0] = &i;
    printf("%lu, %lu, %d\n", sizeof(a), sizeof(*a), *a[0]);

    
    int *b= malloc(sizeof(int)*3);
    b[0] = 0;
    b[1] = 1;
    printf("%lu, %lu\n", sizeof(b), sizeof(*b));
    /*
     Byte *bytes = (Byte *)[characteristic.value bytes];
     int *a[3];
     int i = 2;
     a[0] = &i;
     NSLog(@"%lu, %lu", sizeof(a), sizeof(*a));
     NSLog(@"%lu", sizeof(bytes));
     NSLog(@"%lu, %0x, %0x, %0x", sizeof(bytes[0]), bytes[0], bytes[1], bytes[100]);
     */
    
//    int i = 5;
//    int a[i];
//    a[0] = 10;
//    printf("a[0] = %d\n", a[0]);
    
//    int i;
//     char *pch[6] = {"妹","妹","你","坐","船","头"};
//    for(i=0;i<6;i++){
//        printf("%s, ",pch[i]);
//    }
//    printf("\n");
//    for(i=5; i>=0; i--){
//        printf("%s\n",pch[i]);
//    }
    
//    int *p[] = (int *)malloc(sizeof(int)*8);
//    for (int i = 0; i < 8; i++) {
//        p[i] = &i;
//    }
//    printf("p = %p\n", p);
//    printf("%zd\n", sizeof(p));
//    printf("%zd\n", sizeof(*p));
}
