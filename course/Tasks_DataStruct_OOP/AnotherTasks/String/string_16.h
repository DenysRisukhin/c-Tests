//
//  string_16.h
//  Test2019
//
//  Created by Risukhin Denys on 1/18/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef string_16_h
#define string_16_h

//Sorting algorithms use comparison operators to decide whether the array should be rearranged in ascending or descending order. Heap sort, fast sort or merge sort, bubble sort, and insertion sort are several techniques.
//
//We'll sort strings in this article using a variety of techniques. We shall use the STL library function <algorithm> to sort the names by string length.

//1. By Bubble Sort :

// output:
//Enter Names: hey
//lets
//go
//on
//a
//trip
//with
//my
//family
//tomorrow
//
//Alphabetical order of Names :
//a
//family
//go
//hey
//lets
//my
//on
//tomorrow
//trip
//with

int main() {
    // Create a character array "Name" of size 10 and character value 15.

    // Create another array “arr” of data type string, and the value of '10' is set as a character value.
    char Name[10][15], arr[10];

    // User inputs x and y.
    int x, y;
    cout << "Enter Names: ";
    for (x = 0; x < 10; x++) {
        cin >> Name[x];
    }
    for (x = 1; x < 10; x++) {
        for (y = 1; y < 10; y++) {
            if (strcmp(Name[y - 1], Name[y]) > 0) {
                strcpy(arr, Name[y - 1]);
                strcpy(Name[y - 1], Name[y]);
                strcpy(Name[y], arr);
            }

        }
    }
    cout << "\nAlphabetical order of Names :\n";
    for (x = 0; x < 10; x++)
        cout << Name[x] << endl;
    cout << endl;
    return 0;
}

#endif /* string_16_h */
