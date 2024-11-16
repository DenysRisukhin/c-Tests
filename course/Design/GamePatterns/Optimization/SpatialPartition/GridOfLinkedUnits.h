//
//  GridOfLinkedUnits.h
//  Test2019
//
//  Created by Risukhin Denys on 2/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef GridOfLinkedUnits_h
#define GridOfLinkedUnits_h

class Unit
{
friend class Grid;
    
public:
    Unit(Grid* grid, double x, double y)
        : grid_(grid),
        , x_(x)
        , y_(y)
{}

void move(double x, double y);

private:
    double x_, y_;
    Grid* grid_;
    
    Unit* prev_;
    Unit* next_;
};

//Это даст нам возможность организовывать юниты в двусвязный список вместо массива.


class Grid
{
public:
    Grid()
    {
        // Очистка сетки.
        for (int x = 0; x < NUM_CELLS; x++)
        {
            for (int y = 0; y < NUM_CELLS; y++)
            {
                cells_[x][y] = NULL;
            }
        }
    }

    static const int NUM_CELLS = 10;
    static const int CELL_SIZE = 20;
    
private:
    Unit* cells_[NUM_CELLS][NUM_CELLS];
};



// Выходим на поле боя---------------------------------------

Unit(Grid* grid, double x, double y)
    : grid_(grid),
    x_(x),
    y_(y),
    prev_(NULL),
    next_(NULL)
    {
        grid_->add(this);
    }

void Grid::add(Unit* unit)
{
    // Определяем в какой ячейке сетки мы находимся.
    int cellX = (int)(unit->x_ / Grid::CELL_SIZE);
    int cellY = (int)(unit->y_ / Grid::CELL_SIZE);

    // Добавляем в начало списка найденной ячейки.
    unit->prev_ = NULL;
    unit->next_ = cells_[cellX][cellY];
    cells_[cellX][cellY] = unit;

    if (unit->next_ != NULL)
    {
        unit->next_->prev_ = unit;
    }
}

// Звон мечей---------------------------------------

void Grid::handleMelee()
{
    for (int y = 0; y < NUM_CELLS; y++)
    {
        for (int x = 0; x < NUM_CELLS; x++)
        {
            handleCell(cells_[x][y]);
        }
    }
}


void Grid::handleCell(Unit* unit)
{
    while (unit != NULL)
    {
        Unit* other = unit->next_;
        while (other != NULL)
        {
            if (unit->x_ == other->x_ &&
                unit->y_ == other->y_)
            {
                handleAttack(unit, other);
            }
            other = other->next_;
        }

        unit = unit->next_;
    }
}

// Идем в атаку---------------------------------------

void Unit::move(double x, double y)
{
    grid_->move(this, x, y);
}

void Grid::move(Unit* unit, double x, double y)
{
// Смотрим в какой ячейке находимся.
int oldCellX = (int)(unit->x_ / Grid::CELL_SIZE); 7.int oldCellY = (int)(unit->y_ / Grid::CELL_SIZE); 8.
// Смотрим в какую ячейку перемещаемся. 10. int cellX = (int)(x / Grid::CELL_SIZE);
 int cellY = (int)(y / Grid::CELL_SIZE); 12.
 unit->x_ = x;
 unit->y_ = y;

// если ячейка не меняется =- мы закончили
    if (oldCellX == cellX && oldCellY == cellY) return;
    // Убираем юнит из списка старой ячейки.
    if (unit->prev_ != NULL)
    {
        unit->prev_->next_ = unit->next_;
    }

    if (unit->next_ != NULL)
    {
        unit->next_->prev_ = unit->prev_;
    }

// Если это голова списка - удаляем ее.
    if (cells_[oldCellX][oldCellY] == unit)
    {
        cells_[oldCellX][oldCellY] = unit->next_; 34. }

    // Добавление обратно в сетку в новую ячейку. 37. add(unit);
    }



// На расстоянии вытянутой руки---------------------------------------

if (distance(unit, other) < ATTACK_DISTANCE)
{
    handleAttack(unit, other);
}

void Grid::handleUnit(Unit* unit, Unit* other)
{
    while (other != NULL)
    {
        if (distance(unit, other) < ATTACK_DISTANCE)
        {
            handleAttack(unit, other);
        }

        other = other->next_;
        
    }
}

void Grid::handleCell(int x, int y)
{
    Unit* unit = cells_[x][y];
    while (unit != NULL)
    {
        // Обработка остальных юнитов в ячейке. 9.handleUnit(unit, unit->next_);
        unit = unit->next_;
    }
}

void Grid::handleCell(int x, int y)
{
    Unit* unit = cells_[x][y];
    while (unit != NULL)
    {
        // Обработка остальных юнитов в ячейке.
        handleUnit(unit, unit->next_);
        // Теперь пробуем соседние ячейки.
        if (x > 0 && y > 0)
            handleUnit(unit, cells_[x - 1][y - 1]);
        
        if (x > 0)
            handleUnit(unit, cells_[x - 1][y]);

        if (y > 0)
            handleUnit(unit, cells_[x][y - 1]);
        
        if(x > 0 && y < NUM_CELLS - 1)
        {
            handleUnit(unit, cells_[x - 1][y + 1]);
        }
        
        unit = unit->next_;
    }
}



#endif /* GridOfLinkedUnits_h */
