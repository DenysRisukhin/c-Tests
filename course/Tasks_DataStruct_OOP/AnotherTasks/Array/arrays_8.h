//
//  arrays_8.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_8_h
#define arrays_8_h

int closestToValue(const int* ints, int size, const int val)
{
    if (size <= 0 || ints == nullptr)
    {
        // Handle invalid input
        std::cerr << "Invalid input: Array is empty or null." << std::endl;
        return 0; // You may want to choose a specific value for invalid cases
    }

    int closestValue = INT_MAX;
    int closesDistance = abs(ints[0] - val);

    for (int id = 0; id < size; id++)
    {
        int curClosestValue = abs(ints[id] - val);
        if (closesDistance > curClosestValue)
        {
            closestValue = ints[id];
            closesDistance = curClosestValue;
        }
    }

    return closestValue;
}

//int main()
//{
//    
//    int array[] = {5, -3, 3, 4, 7};
//    
//    
//    int arraySize = sizeof(array) / sizeof(array[0]);
//    
//    const int val = -2;
//    int result = closestToValue(array, arraySize, val);
//    
//    std::cout << "Closest to value: " << result << std::endl;
//}
#endif /* arrays_8_h */
