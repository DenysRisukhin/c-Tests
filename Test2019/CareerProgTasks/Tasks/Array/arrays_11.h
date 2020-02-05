//
//  arrays_11.h
//  Test2019
//
//  Created by Denys Risukhin on 1/22/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef arrays_11_h
#define arrays_11_h

#pragma mark - 16.10

class Person
{
public:
    Person(): m_birthYear(0), m_deathYear(0) {}
    
    Person(int birthYear, int deathYear)
    : m_birthYear(birthYear), m_deathYear(deathYear)
    {
        // do nothing
    }
    
    int getBirthYear() const { return m_birthYear; }
    int getDeathYear() const { return m_deathYear; }
    
private:
    int m_birthYear;
    int m_deathYear;
};

// Big O(RP)
// R - the range of the years (100 years for our case)
// P - human amount
int getBestYear()
{
    int minYear = 1900;
    int maxYear = 2000;
    
    Person personsList[]{
        Person(1912, 1915), Person(1920, 1990), Person(1910, 1998), Person(1901, 1972), Person(1910, 1998),
        Person(1923, 1982), Person(1913, 1998), Person(1990, 1998), Person(1983, 1999), Person(1975, 1994)
    };
    
    int maxAliveCtr = 0;
    int maxAliveYear = minYear;
    
    for (int year = minYear; year <= maxYear; year++)
    {
        int aliveCtr = 0;
        
        for (const auto& person: personsList)
        {
            if (person.getBirthYear() <= year && year <= person.getDeathYear())
            {
                aliveCtr++;
            }
            
        }
        
        if (aliveCtr > maxAliveCtr)
        {
            maxAliveCtr = aliveCtr;
            maxAliveYear = year;
        }
    }
    
    return maxAliveYear;
}


#endif /* arrays_11_h */
