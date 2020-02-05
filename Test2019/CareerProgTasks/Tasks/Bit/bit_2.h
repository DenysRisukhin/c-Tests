//
//  bit_2.h
//  Test2019
//
//  Created by Denys Risukhin on 2/2/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef bit_2_h
#define bit_2_h

#pragma mark - getBit

// сдигаем 1 на pos бит.
// & над числом value сбросит все биты кромк pos
// затем результат сравниваем с 0 (если знач не 0 то возвр 1, иначе 0)
int getBit(int value, int pos) {
    return ((value & (1 << pos)) != 0);
}

#pragma mark - setBit

// сдигаем 1 на pos бит.
// | над числом value сбросит только значение бита pos
// все остальные биты остаются неизменными
int setBit(int value, int pos) {
    return value | (1 << pos);
}

#pragma mark - clearBit

// противоположноость setBit  с 108
// 1 создается инверсия
// 2 & с числом value - сбрасывается только pos бит, а остальные не меняются
int clearBit(int value, int pos) {
    int mask = ~(1 << pos);
    return value & mask;
}

#pragma mark - updateBit

// что бы присвоить pos-биту значение v:
// 1 с помощью маски сбрасываем бит pos
// 2 затем нужное значение v сдвигается влево на pos битов
// 3 создается число у которого pos бит равен v, а все остальные биты 0
// 4 | для 2-ух чисел обновляет pos бит,если бит v = 1 и оствляет его 0 в противном случае
int updateBit(int num, int pos, bool bitIs1) {
    int value = bitIs1 ? 1 : 0;
    int mask = ~(1 << pos);
    return (num & mask) | (value << pos);
}

//test getBit
//    cout << getBit(5, 0) << endl;
//    cout << getBit(5, 1) << endl;
//    cout << getBit(5, 2) << endl;
//    cout << endl;

#endif /* bit_2_h */
