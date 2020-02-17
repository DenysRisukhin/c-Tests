#pragma mark - init

void initVec(vector<int>& numbers, const int size)
{
    numbers.reserve(size);
    numbers.resize(size);
    
    for (auto& number: numbers)
    {
        number = 1 + rand() % 9;
    }
}

void initMap(map<int, int>& numbersMap, const int size)
{
    for (int i = 0; i < size; i++)
    {
        numbersMap.emplace(i, 1 + rand() % 9);
    }
}

#pragma mark - remove

void removeFromVec(vector<int>& numbers)
{
    int ctr = 0;
    int elemAmount = 0 + rand() % 14;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        int elemIdx = 0 + rand() % numbers.size() - 1;
        
        for(auto pos = numbers.begin(); pos != numbers.end();)
        {
            if((*pos) == numbers[elemIdx])
            {
                if (ctr > elemAmount)
                {
                    break;
                }
                
                pos = numbers.erase(pos);
                ctr++;
            }
            else
            {
                ++pos;
            }
        }
    }
}

void removeFromMap(map<int, int>& myMap)
{
    int ctr = 0;
    int elemAmount = 0 + rand() % 14;
    
    for (int i = 0; i < myMap.size(); i++)
    {
        int elemIdx = 0 + rand() % myMap.size() - 1;
        
        for(auto pos = myMap.begin(); pos != myMap.end();)
        {
            if(pos->second == elemIdx)
            {
                if (ctr > elemAmount)
                {
                    break;
                }
                
                pos = myMap.erase(pos);
                ctr++;
            }
            else
            {
                ++pos;
            }
        }
    }
}

#pragma mark - print

void printVec(vector<int>& numbers)
{
    for (auto& number: numbers)
    {
        cout << number << ' ';
    }
    
    cout << endl;
}

void printMap(map<int, int>& myMap)
{
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << endl;
}

#pragma mark - synchronization

void synchronization(map<int, int>& numbersMap, vector<int>& numbers)
{
    bool isFound = false;
    
    for (auto posVec = numbers.begin(); posVec != numbers.end();)
    {
        isFound = false;
        
        for (auto pos = numbersMap.begin(); pos != numbersMap.end(); ++pos)
        {
            
            if ((*posVec) == pos->second)
            {
                isFound = true;
                break;
            }
        }
        
        if (!isFound)
        {
            posVec = numbers.erase(posVec);
        }
        else
        {
            ++posVec;
        }
    }
    
    // clear map
    for (auto pos = numbersMap.begin(); pos != numbersMap.end();)
    {
        pos = numbersMap.erase(pos);
    }
    
    // init map
    for (int i = 0; i < numbers.size(); i++)
    {
        numbersMap[i] = numbers[i];
    }
}



int main()
{
    // vec
    srand(time(nullptr));
    
    const int size = 20;
    
    vector<int> numbers;
    
    initVec(numbers, size);
    
    printVec(numbers);
    
    removeFromVec(numbers);
    
    printVec(numbers);
    
    cout << endl;
    
    // map
    map<int,int> numbersMap;
    initMap(numbersMap, size);
    
    printMap(numbersMap);
    
    removeFromMap(numbersMap);
    
    printMap(numbersMap);
    
    cout << "last step:" << endl;
    
    printVec(numbers);
    
    printMap(numbersMap);
    
    synchronization(numbersMap, numbers);
    
    cout << "result\n";
    
    printVec(numbers);
    printMap(numbersMap);
    
    return 0;
}

