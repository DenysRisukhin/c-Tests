//
//  arrays_1.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_1_h
#define arrays_1_h

void merge(int* arrA, int sizeA, int* arrB, int sizeB, int* arrC, int sizeC) {
    int ctr = 0;
    int ctrA = 0;
    int ctrB = 0;
    
    while (ctr < sizeC)
    {
        if (arrA[0] < arrB[0])
        {
            if (ctr < sizeA)
            {
                arrC[ctr++] = arrA[ctrA++];
            }
            else
            {
                arrC[ctr++] = arrB[ctrB++];
            }
        }
        else
        {
            if (ctr < sizeB)
            {
                arrC[ctr++] = arrB[ctrB++];
            }
            else
            {
                arrC[ctr++] = arrA[ctrA++];
            }
        }
    }
}

void merge(int* arrA, int sizeA, int* arrB, int sizeB, int* arrC, int sizeC)
{
    int copyId = 0;
    for (int id = 0; id < sizeC; id++)
    {
        if (id < sizeA)
        {
            *(arrC + id) = *(arrA + id);
        }
        else
        {
            *(arrC + id) = *(arrB + copyId);
            copyId++;
        }
    }
}

//Test
//
//    int arrB[]{6, 7, 8, 9, 10};
//    int arrA[]{1, 2, 3, 4, 5};
//    auto sizeA = sizeof(arrA)/sizeof(int);
//    auto sizeB = sizeof(arrB)/sizeof(int);
//    auto sizeC = sizeA + sizeB;
//    int arrC[sizeC];
//
//    merge(arrA, sizeA, arrB, sizeB, arrC, sizeC);
//
//    for (int i = 0; i < sizeC; i++) {
//        cout << arrC[i] << ' ';
//    }

#endif /* arrays_1_h */
