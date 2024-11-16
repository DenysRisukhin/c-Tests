//
//  arithmetic_4.h
//  Test2019
//
//  Created by Denys Risukhin on 1/21/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arithmetic_4_h
#define arithmetic_4_h

int getNumberSum(int number)
{
    int result = 0;
    int ctr = 0;
    
    while (number != 0)
    {
        result += number % 10;
        number /= 10;
        ctr++;
        
        if (number == 0)
        {
            if (ctr == 1)
            {
                break;
            }
            
            number = result;
            result = 0;
            ctr = 0;
        }
    }
    
    return result;
}

//test
//
//int number;
//printf("Input number: "); // 128
//scanf("%d", &number);
//printf("%d", getNumberSum(number));
//cout << endl;

#endif /* arithmetic_4_h */
