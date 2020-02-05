//
//  Cities.h
//  Test2019
//
//  Created by Denys Risukhin on 1/6/20.
//  Copyright © 2020 DenysRisukhin. All rights reserved.
//

#ifndef Cities_h
#define Cities_h

//London
//Milan
//Stockholm
//Paris

//Paris
//Stockholm
//Milan

void setResultCityList(std::vector<std::string>& cities, std::vector<std::string>& resultCities, char& firstLatter, char& lastLetter, int& score) {
    for (auto iter = cities.begin(); iter != cities.end(); ) {
        
        // convert uppercase to lovercase
        if ((*iter)[0] >= 65 && (*iter)[0] <= 92) {
            firstLatter = (*iter)[0] + 32;
        }
        
        if (lastLetter == firstLatter) {
            // add to new vec
            resultCities.push_back((*iter));
            
            // update lastLetter
            auto wordSize = (*iter).size();
            lastLetter = (*iter)[wordSize - 1];
            
            // update score
            score += wordSize;
            
            // remove city from cur vec
            cities.erase(iter);
            
            // reinit
            iter = cities.begin();
            
        } else {
            iter++;
        }
    }
}

// create | open | write to file 'output'
void createOutPutFileWithResultData(std::vector<std::string>& resultCities) {
    
    std::ofstream("output.txt");
    std::ofstream fileOutPut;
    fileOutPut.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    
    //  try {
    fileOutPut.open("output.txt");
    
    if (!fileOutPut.is_open()) {
        std::cerr << "Error: File can't be opened \n";
        std::terminate();
        
        //throw myException("Error: File can't be opened \n", 1);
    }
    
    for (auto iter = resultCities.begin(); iter != resultCities.end(); iter++)
        fileOutPut << (*iter) << std::endl;
    
    fileOutPut.close();
}

void print(std::vector<std::string>& resultCities, int& score) {
    std::cout << std::endl;
    std::cout << "score: " << score << std::endl;
    
    for (const auto& city: resultCities) {
        std::cout << city << std::endl;
    }
    
    std::cout << std::endl;
}


void readDataFromFile(std::vector<std::string>& cities) {
    FILE *fileFoo;
    
    fileFoo = fopen("input.txt", "r");
    
    if (!fileFoo)
    {
        std::cerr << "Error: File can't be opened \n";
        std::terminate();
        //throw exception("Error: File can't be opened \n");
    }
    
    char buf[20];
    
    while (fscanf(fileFoo, "%s \n",  buf) != EOF) {
        cities.push_back(buf);
    }
    
    fclose(fileFoo);
}

// Test
//    std::vector<std::string> reandomData;
//    reandomData.push_back("London");
//    reandomData.push_back("Milan");
//    reandomData.push_back("Stockholm");
//    reandomData.push_back("Paris");
//
//    std::ofstream("input.txt");
//
//    std::ofstream file;
//
//    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
//
//    try {
//        file.open("input.txt");
//
//        if (!file.is_open())
//        {
//            std::cerr << "Error: File can't be opened \n";
//            std::terminate();
//
//            //throw myException("Error: File can't be opened \n", 1);
//        }
//
//        for (auto iter = reandomData.begin(); iter != reandomData.end(); iter++)
//        file << (*iter) << std::endl;
//
//        file.close();
//
//        std::vector<std::string> cities;
//        readDataFromFile(cities);
//
//        // check info from file
//        for (const auto& city: cities) {
//            std::cout << city << std::endl;
//        }
//
//        // init data
//        std::string city = cities[cities.size() - 1];
//        char lastLetter = city[city.size() - 1];
//        char firstLatter = ' ';
//        int score = city.size();
//
//        std::vector<std::string> resultCities;
//        // add first city to result vec
//        resultCities.push_back(cities[cities.size() - 1]);
//
//        // remove last city from cities vec
//        cities.pop_back();
//
//
//        setResultCityList(cities, resultCities, firstLatter, lastLetter, score);
//
//        print(resultCities, score);
//
//        createOutPutFileWithResultData(resultCities);
//    }
//    catch (std::exception &ex)
//    {
//        std::cout << "Block 1 catched" << ex.what() << std::endl;
//    }

#endif /* Cities_h */
