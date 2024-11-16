//
//  matrix_3.h
//  Test2019
//
//  Created by Denys Risukhin on 1/27/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef matrix_3_h
#define matrix_3_h

void updateMatrix(int (*arr)[4], int size)
{
    vector<int> row;
    vector<int> column;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 0)
            {
                row.push_back(i);
                column.push_back(j);
            }
        }
    }
    
    if (!row.empty())
    {
        for(auto r: row)
        {
            for (int c = 0; c < size; c++)
            {
                arr[r][c] = 0;
            }
        }
    }
    
    if (!column.empty())
    {
        for(auto c: column)
        {
            for (int r = 0; r < size; r++)
            {
                arr[r][c] = 0;
            }
        }
    }
}

//test
//
//    const int size = 4;
//    int arr[size][size] {
//        {0, 7, 3, 5},
//        {2, 4, 0, 5},
//        {0, 3, 0, 3},
//        {1, 9, 3, 5}
//    };
//
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
//    updateMatrix(arr, size);
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

#endif /* matrix_3_h */
