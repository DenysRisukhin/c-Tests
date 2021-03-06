//
//  matrix_2.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef matrix_2_h
#define matrix_2_h

int rotate(int** arr, const int size)
{
    int cycleCount = 0;
    
    for (int layer = 0; layer < size / 2; ++layer )
    {
        int first = layer;
        int last = size - 1 - layer;
        
        for (int j = first; j < last; ++j)
        {
            int offset = j - first;
            int top = arr[first][j];
            
            arr[first][j] = arr[last - offset][first];
            arr[last - offset][first] = arr[last][last - offset];
            arr[last][last - offset] = arr[j][last];
            arr[j][last] = top;
            
            cycleCount++;
        }
    }
    return cycleCount;
}

//test
//    
//    int row = 5;
//    int column = 5;
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
//    // init
//    for (int r = 0; r < row; r++)
//    {
//        for (int c = 0; c < column; c++)
//        {
//            arr[r][c] = data++;
//        }
//    }
//    
//    // print
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
//    rotate(arr, 5);
//    
//    cout << endl;
//    
//    // print
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
//    for (int r = 0; r < row; r++) {
//        delete arr[r];
//    }
//    
//    delete[] arr;

#endif /* matrix_2_h */
