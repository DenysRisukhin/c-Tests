//
//  Singleton.h
//  Test2019
//
//  Created by Denys Risukhin on 8/10/19.
//  Copyright © 2019 DenysRisukhin. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

// Singleton - обеспечивает существование единственного экземпляра клааса и глобальный доступ к нему
// Usage - когда класс взаимодействует с системой поддерживающей собственное глобальное состояние

// advantage
// - инициализация во время выполнения

// минусы
// - использоваие глобальных переменных
// - код менее понятен
// - усиливает связность. Управляя доступом к экземпляру вы управляете связностью

class SceneManager {
public:
    static SceneManager& instance() {
        static SceneManager* instance = new SceneManager();
        return *instance;
    }
    
private:
    SceneManager() {}
};

// example with class FileSystem & covertion FileSystem to Singleton

class FileSystem {
public:
    virtual ~FileSystem() {}
    virtual char* readFile(char* path) = 0;
    virtual void writeFile(char* path, char*) = 0;
};

class PSFileSystem;
class WiFiFileSystem;
// covert FileSystem to Singleton
class FileSystemSingleton {
public:
    static FileSystemSingleton& instance() {
#if platform == PS
    //    static FileSystemSingleton* instance = new PSFileSystem();
#else
    //    static FileSystemSingleton* instance = new WiFiFileSystem();
#endif
        static FileSystemSingleton* instance = new FileSystemSingleton();
        return *instance;
    }
    
    ~FileSystemSingleton() {}
    
//    virtual char* readFile(char* path) = 0;
//    virtual void writeFile(char* path, char*) = 0;
    
protected:
    FileSystemSingleton();
};

class PSFileSystem: public FileSystemSingleton {
public:
    char* readFile(char* path) { return path; }
    
    void writeFile(char* path, char*) {}
};

class WiFiFileSystem: public FileSystemSingleton {
public:
    char* readFile(char* path) { return path; }
    void writeFile(char* path, char*) {}
};



#endif /* Singleton_h */
