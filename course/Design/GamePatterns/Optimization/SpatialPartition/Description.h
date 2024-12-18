//
//  Spatial_Partition.h
//  Test2019
//
//  Created by Risukhin Denys on 2/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Spatial_Partition_h
#define Spatial_Partition_h

//ПРОСТРАНСТВЕННОЕ РАЗБИЕНИЕ
//
//Эффективный поиск находящихся рядом объектов с помощью сохранения их в
//структуре данных с организацией на основе их местоположения
//
//Есть набор объектов, каждый из которых обладает позицией в пространстве. Объекты хранятся впространственной структуре данных, организованной на основе их позиций. Эта структура данных позволяет вам эффективно запрашивать объекты, находящиеся возле указанной позиции. Когда позиция
//объекта изменяется, позиционная структура данных обновляется и поиск
//можно продолжать.
//
//Это значит что вашей игре часто требуется отвечать на вопрос "Что за объекты находятся рядом?". Если чтобы ответить на это вопрос придется тратить слишком много времени на каждом кадре, такой поиск превратится в бутылочное горлышко
//для производительности нашей игры.
//
//Когда использовать
//
//Этот шаблон часто используется для хранения как живых, подвижных объектов, так
//и статичных декораций и геометрии игрового мира. Сложные игры обычно имеют сразу несколько структур пространственного разбиения для различных типов
//содержимого.
//Базовым требованием для этого шаблона является наличие набора объектов,
//каждый из которых обладает подобием позиции и вам приходится выполнять
//много запросов для поиска этих объектов, от чего может пострадать
//производительность вашей игры.
//
//
//Имейте в виду
//Пространственное разбиение существует для того чтобы заменить операции со сложностью O(n) или O(n2) на что-то более простое. Чем больше у вас объектов, тем полезнее такое решение. И наоборот, если n у вас мало - связываться с такими
//вещами не стоит.
//Так как этот шаблон предполагает организацию объектов по их местоположению, с объектами которые меняютсвою позицию, работать тяжелее. Вам нужно будет
//реорганизовы вать структуру данных чтобы отслеживать объекты на новы х позициях, что в свою очередь добавляет сложности и требует траты процессорного
//времени. Так что убедитесь в том что затраты окупятся.
//Представьте себе хэш-таблицу, в которой ключи хэшированных объектов могут произвольно меняться и вы сможете себе представить как это сложно.
//Пространственное разбиение требует и дополнительной памяти для хранения
//структуры данных.



void handleMelee(Unit* units[], int numUnits)
{
    for (int a = 0; a < numUnits - 1; a++)
    {
        for (int b = a + 1; b < numUnits; b++)
        {
            if (units[a]->position() == units[b]->position())
            {
                handleAttack(units[a], units[b]);
            }
        }
    }
}

//Каждая из структур данных для разбиения пространства чаще всего адаптируе т идею хорошо известных структур для одномерного пространства на большее количество измерений.
//
// Сетка - это разновидность блочной сортировки (bucket sort).
// BSP, k-мерное дерево(k-d tree) и Иерархия ограниченных объемов (Bounding volume hierarchy) - это разновидностьбинарных деревьев поиска (binary search trees).
// Квад-деревья и окта-деревья - это просто деревья (tries).

#endif /* Spatial_Partition_h */
