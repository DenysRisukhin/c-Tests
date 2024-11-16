//
//  arrays_9.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_9_h
#define arrays_9_h

// we should handle negative ints by ads for current Zero Target.

int closestToZero(const int* ints, int size)
{
    if (size <= 0 || ints == nullptr) {
        // Handle invalid input
        std::cerr << "Invalid input: Array is empty or null." << std::endl;
        return 0; // You may want to choose a specific value for invalid cases
    }

    int closestValue = INT_MAX;
    int closestDistance = std::abs(ints[0]);

    for (int i = 1; i < size; ++i)
    {
        // let's handle the sign '-'
        int currentDistance = std::abs(ints[i]);

        const bool isCurrentDistanceSmaller = closestDistance > currentDistance;
        const bool isPositiveAndSameClosesDistanceValue = currentDistance == closestDistance && ints[i] > 0;

        // Update closest value if the current value is closer or has the same distance but is positive
        if (isCurrentDistanceSmaller || isPositiveAndSameClosesDistanceValue)
        {
            closestValue = ints[i];
            closestDistance = currentDistance;
        }
    }

    return closestValue;
}

//int main() {
//    
//    // test 1
//    int arr[]{-1, 2, -3, 0, 3, 5};
//    // test 2
//    //int arr[]{};
//    int size = sizeof(arr)/sizeof(int);
//    
//    cout << getClosestToZero(arr, size);

#endif /* arrays_9_h */
