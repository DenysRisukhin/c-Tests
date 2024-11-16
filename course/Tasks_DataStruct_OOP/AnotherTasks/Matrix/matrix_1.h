//
//  matrix_1.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef matrix_1_h
#define matrix_1_h

bool isFound(int** arr, int row, int column, int value)
{
    int curRow = 0;
    int curCol = column - 1;
    
    while (curRow < row && curCol >= 0)
    {
        if (arr[curRow][curCol] == value)
        {
            return true;
        }
        else if (arr[curRow][curCol] > value)
        {
            curCol--;
        }
        else
        {
            curRow++;
        }
    }
    
    return false;
}

//test
//
//    int row = 3;
//    int column = 4;
//    int searchingValue = 11;
//
//    int** arr = new int*[row];
//
//    for (int i = 0; i < row; i++)
//    {
//        arr[i] = new int[column];
//    }
//
//    int data = 0;
//
//    for (int r = 0; r < row; r++)
//    {
//        for (int c = 0; c < column; c++)
//        {
//            arr[r][c] = data++;
//        }
//    }
//
//    // init
//    for (int r = 0; r < row; r++)
//    {
//        cout << endl;
//
//        for (int c = 0; c < column; c++)
//        {
//            cout << arr[r][c] << ' ';
//        }
//    }
//
//    cout << endl << "result: " << isFound(arr, row, column, searchingValue) << endl;
//
//    for (int r = 0; r < row; r++) {
//        delete arr[r];
//    }
//
//    delete[] arr;

#endif /* matrix_1_h */
