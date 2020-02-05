//
//  rand_2.h
//  Test2019
//
//  Created by Denys Risukhin on 2/3/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef rand_2_h
#define rand_2_h

#pragma mark - utility

std::string to_binary_string(int n)
{
    std::string result;
    do
    {
        result = ('0' + (n % 2)) + result;
        n = n / 2;
    } while (n > 0);
    
    return result;
}

std::string DecimalToBinaryString(int a)
{
    uint b = (uint)a;
    std::string binary = "";
    uint mask = 0x80u;
    
    while (mask > 0)
    {
        binary += ((b & mask) == 0) ? '0' : '1';
        mask >>= 1;
    }
    return binary;
}

int binaryToDecimal(std::string binaryString) {
    int value = 0;
    int indexCounter = 0;
    for(int i = binaryString.length()-1; i >= 0; i--)
    {
        if(binaryString[i] == '1')
        {
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    
    return value;
}

#pragma mark - randomizer

int getRandVal() {
    return (0 + rand() % 10) > 5 ? 1 : 0;
}

int (*p_getRandVal)() = nullptr;

#pragma mark - main logic

auto getValueFromChangedRange(int (*p_getRandVal)()) {
    const int maxVal = 100;
    
    std::string binaryMaxValue = DecimalToBinaryString(maxVal);
    const int maxBitsAmount = static_cast<int>(binaryMaxValue.size());
    
    std::string result;
    int resultValue;
    
    while(1) {
        result += std::to_string((*p_getRandVal)());
        
        if (result.size() == maxBitsAmount) {
            if (binaryToDecimal(result) <= maxVal) {
                resultValue = binaryToDecimal(result);
                break;
            } else {
                result = "";
                resultValue = 0;
            }
        }
    }
    return resultValue;
}


//test

//    srand(time(NULL));
//
//    p_getRandVal = &getRandVal;
//
//    std::cout << getValueFromChangedRange(p_getRandVal) << std::endl;



// это не удачная попытка принять указатель на функцию и вернуть лямбду
//typedef std::function<int> MyFunc;

//int changeRange(std::function<int> &func)
//{
//    return [&func]() {
//
//        for (int i = 0; i < 100; i++) {
//            if (func()) {
//
//            } else {
//
//            }
//        }
//
//        return 3;
//    };
//}

#endif /* rand_2_h */
