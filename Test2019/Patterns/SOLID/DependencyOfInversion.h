//
//  DependencyOfInversion.h
//  Test2019
//
//  Created by Denys Risukhin on 1/1/21.
//  Copyright © 2021 DenysRisukhin. All rights reserved.
//

#ifndef DependencyOfInversion_h
#define DependencyOfInversion_h

//Dependency of Inversion principle
//High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g. interfaces).
//Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.

struct AwsCloud {
   void uploadToS3Bucket(string filepath) { /* ... */ }
};

struct FileUploader {
   FileUploader(AwsCloud& awsCloud);
   void scheduleUpload(string filepath);
};

// fix strp 1

struct Cloud {
   virtual ~Cloud() = default;
   virtual void uploadToS3Bucket(string filepath) = 0;
};

struct AwsCloud : public Cloud {
   void uploadToS3Bucket(string filepath) override { /* ... */ }
};

struct FileUploader {
   FileUploader(Cloud& cloud);
   void scheduleUpload(string filepath);
};

// fix step 2

struct Cloud {
   virtual ~Cloud() = default;
   virtual void upload(string filepath) = 0;
};

struct AwsCloud : public Cloud {
   void upload(string filepath) override { /* ... */ }
};

struct FileUploader {
   FileUploader(Cloud& cloud);
   void scheduleUpload(string filepath);
};



#endif /* DependencyOfInversion_h */
