//
//  OOP_1.h
//  Test2019
//
//  Created by Denys Risukhin on 2/17/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef OOP_1_h
#define OOP_1_h

//выравнивание ст-р
//https://www.youtube.com/watch?v=PlT4sgUkyi4
//https://habr.com/ru/post/142662/

//Выравнивание ст-р зависит от настроек компилятора или от платформы
//по умолчанию поля могут выравниваться т к процессору удобнее работать с типами длина которых кратная 2-ке
//но таже в настройках может быть указано что выравнивать не нужно
//
//данные расположены в памяти в таком порядке в котором мы их описали в ст-ре
//
//нужно перестраховываться что бы не получить разные размеры ст-ры на разных платформах
--------------------------
#pragma pack - (push, ...)   // установили размер выравнивания в ... байт
struct a {};
#pragma pack(pop)          // вернули предыдущую настройку.
--------------------------

// 1 выравнивание не происходит
struct a
{
    char m_a;
};

// 2 при добавлении переменных тип которых кратен 2-ке выравнивание происходит
struct a
{
    char m_a; // выравняется в 2 байта
    short m_b; // 2 байта
};

// 3
struct a  // 12 byte
{
    char m_a; // выравняется до 2-ух тоесть до ближайшего short
    short m_b; // 2 байта
    int  m_c;
    char m_d; // выравняется в 4 байта до ближайшего int
};

// 4
// 12 byte с віравниванием
// 10 byte без выравнивания
struct a
{
    char m_a; // выравняется до 2-ух тоесть до ближайшего short
    short m_b; // 2 байта
    short m_c;
    char m_d; // выравняется в 4 байта до ближайшего int
    int m_e;
};

// 5
#pragma pack(push, 1) // 1 - выравнивания не будет = 10
#pragma pack(push, 4) // 2 - выравнивание будет = 12 (но может зависеть от платформы)

struct a
{
    char m_a;
    short m_b;
    short m_c;
    char m_d;
    int m_e;
};
#pragma pack(pop)

// 6
#pragma pack(push, 4)
size = 8
struct a
{
    char m_a;
    int m_b;
};
#pragma pack(pop)

// 7
#pragma pack(push, 2)
size = 6
struct a
{
    char m_a;
    int m_b;
};
#pragma pack(pop)

// 8
#pragma pack(push, 4)
size = 8
struct Foo
{
    char a;
    short int value;
    int b;
};
#pragma pack(pop)

// сново ставим в 4 байта

// 9
struct Foo
{
    char ch;
    int value;
};

1 байт: ch
2 байт: пусто
3 байт: пусто
4 байт: пусто
5 байт: value[0]
6 байт: value[1]
7 байт: value[2]
8 байт: value[3]

// 10
struct Foo
{
    char ch;
    short id;
    int value;
};

1 байт: ch
2 байт: пусто
3 байт: id[0]
4 байт: id[1]
5 байт: value[0]
6 байт: value[1]
7 байт: value[2]
8 байт: value[3]

// 11
struct Foo
{
    char ch;
    short mid;
    short opt;
    int value;
};

1 байт: ch
2 байт: пусто
3 байт: id[0]
4 байт: id[1]
5 байт: opt[0]
6 байт: opt[1]
7 байт: пусто
8 байт: пусто
9 байт: value[0]
10 байт: value[1]
11 байт: value[2]
12 байт: value[3]

#endif /* OOP_1_h */




