//
//  SingleResponsibility.h
//  Test2019
//
//  Created by Denys Risukhin on 1/1/21.
//  Copyright © 2021 DenysRisukhin. All rights reserved.
//

#ifndef SingleResponsibility_h
#define SingleResponsibility_h

// Single Responsibility principle (A class should have only one reason to change)
// class must have responsibility for one and only one purpose.

// https://platis.solutions/blog/2020/06/22/how-to-write-solid-cpp/


// ex 1:
struct PhotoUploader {
   PhotoUploader(Camera& camera, CloudProvider& cloudProvider);
   Image getImage();
   Image resizeImage(int x, int y, const Image& image);
   void uploadImage(Image& image);
};

// ex 2:
const string kPrefix = "user-";
struct UserManager {
   UserManager(Database& database) : db{database} {}
   void createUser(string username) {
       if (!username.startsWith(kPrefix)) {
           username = kPrefix + username;
       }
       db << "insert into users (name) values (?);" << username;
   }
   string getUsersReport() {
       vector<string> users;
       db << "select name from users" >> [&users](string user) {
           users.push_back(user.erase(0, kPrefix.length()) + ",");
       };
       return users;
   }
};

// ex 2 fix:
struct DatabaseManager {
   virtual ~DatabaseManager() = default;
   virtual void addUser(string username) = 0;
   virtual vector<string> getAllUsers() = 0;
};
struct MyDatabaseManager : public DatabaseManager {
   MyDatabaseManager(Database& database);
   void addUser(string username) override;
   vector<string> getAllUsers() override;
};

struct UsernameFormatter {
   virtual ~UsernameFormatter() = default;
   virtual string format(string username) = 0;
   virtual string getReadableName(string input) = 0;
};

#endif /* SingleResponsibility_h */
