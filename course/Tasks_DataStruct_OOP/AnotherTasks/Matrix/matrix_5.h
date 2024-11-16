//
//  matrix_5.h
//  Test2019
//
//  Created by Risukhin Denys on 11/23/23.
//  Copyright © 2023 DenysRisukhin. All rights reserved.
//

#ifndef matrix_5_h
#define matrix_5_h

bool isNewLocation(std::pair<int, int> location, const vector<pair<int, int>>& checkedLocations)
{
    bool isNewLocation = true;
    for (auto iter = checkedLocations.begin(); iter != checkedLocations.end(); iter++)
    {
        if (iter->first == location.first && iter->second == location.second)
        {
            return false;
        }
    }
    
    return true;
}

void checkNeightboars(int (*arr)[4],
                      int i,
                      int j,
                      int size,
                      vector<pair<int, int>>& whaterElements,
                      vector<pair<int, int>>& checkedLocations)
{
    if (i >= size || j >= size || i < 0 || j < 0)
    {
        return;
    }
    
    if (arr[i][j] == 0)
    {
        const std::pair<int,int> location = make_pair(i, j);
        bool isNewLoc = isNewLocation(location, checkedLocations);
        if (!isNewLoc)
        {
            return;
        }
        
        checkedLocations.push_back(location);
        whaterElements.push_back(location);

        checkNeightboars(arr, i, j+1, size, whaterElements, checkedLocations);
        checkNeightboars(arr, i, j-1, size, whaterElements, checkedLocations);
        checkNeightboars(arr, i+1, j, size, whaterElements, checkedLocations);
        checkNeightboars(arr, i-1, j, size, whaterElements, checkedLocations);
        
        // diagonal
        checkNeightboars(arr, i-1, j-1, size, whaterElements, checkedLocations);
        checkNeightboars(arr, i+1, j-1, size, whaterElements, checkedLocations);
        checkNeightboars(arr, i-1, j+1, size, whaterElements, checkedLocations);
        checkNeightboars(arr, i+1, j+1, size, whaterElements, checkedLocations);
    }
}

void waterDetection(int (*arr)[4], const int size)
{
    vector<pair<int, int>> whaterElements;
    vector<pair<int, int>> checkedLocations;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 0)
            {
                bool isNewLoc = isNewLocation(make_pair(i, j), checkedLocations);
                if (isNewLoc)
                {
                    checkNeightboars(arr, i, j, size, whaterElements, checkedLocations);
                    cout << "waterElements: " << whaterElements.size() << endl;
                    whaterElements.clear();
                }
                
            }
        }
    }
}

// test

//int main()
//{
//    const int size = 4;
//       int arr[size][size]
//       {
//           {0, 2, 1, 0},
//           {0, 1, 0, 1},
//           {1, 1, 0, 1},
//           {0, 1, 0, 1}
//       };
//
//    waterDetection(arr, size);
//
//    cout << endl;
//
//    return 0;
//}


#endif /* matrix_5_h */
