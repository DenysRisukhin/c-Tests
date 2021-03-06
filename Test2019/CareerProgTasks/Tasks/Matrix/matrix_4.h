//
//  matrix_4.h
//  Test2019
//
//  Created by Denys Risukhin on 1/28/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef matrix_4_h
#define matrix_4_h

string checkMatrixType(int (*arr)[4], int size)
{
    int nulevkaCtr = 0;
    int edinichCtr = 0;
    int diagonalCtr = 0;
    
    int elementsAmount = size * size;
    
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (r == c)
            {
                if (arr[r][c] == 1)
                {
                    edinichCtr++;
                    
                    if (edinichCtr == size && nulevkaCtr == elementsAmount - size)
                    {
                        return "edinich";
                    }
                }
                
                // if (arr[r][c] > 1 || arr[r][c] > 0)
                if (arr[r][c] > 0)
                {
                    diagonalCtr++;
                }
            }
            
            if (nulevkaCtr == elementsAmount - size && diagonalCtr > 0)
            {
                return "diag";
            }
            
            if (arr[r][c] == 0)
            {
                nulevkaCtr++;
            }
        }
    }
    
    return nulevkaCtr == elementsAmount ? "nulevka" : "non";
}

//test
//    
//    const int size = 4;
//    int arr[size][size] {
//        {0, 0, 0, 0},
//        {0, 0, 0, 0},
//        {0, 0, 0, 0},
//        {0, 0, 0, 0}
//    };
//    
//    // print
//    for (int r = 0; r < size; r++)
//    {
//        cout << endl;
//        
//        for (int c = 0; c < size; c++)
//        {
//            cout << arr[r][c] << ' ';
//        }
//    }
//    
//    cout << endl;
//    
//    cout << checkMatrixType(arr, size) << endl;
    
#endif /* matrix_4_h */
