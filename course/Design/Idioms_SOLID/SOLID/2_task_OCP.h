//
//  2_task_OCP.h
//  Test2019
//
//  Created by Risukhin Denys on 9/15/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef __task_OCP_h
#define __task_OCP_h

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

// Base class for image exporting
class ImageExporter {
public:
    // Pure virtual function for exporting images
    virtual void exportImage(const std::string& imageData) const = 0;
    virtual ~ImageExporter() = default; // Virtual destructor

    // Move constructor
    ImageExporter(ImageExporter&& other) noexcept = default;

    // Move assignment operator
    ImageExporter& operator=(ImageExporter&& other) noexcept = default;

    // Disable copy constructor and copy assignment operator
    ImageExporter(const ImageExporter&) = delete;
    ImageExporter& operator=(const ImageExporter&) = delete;
};

// Concrete exporter for PNG format
class PNGExporter : public ImageExporter {
public:
    // Explicit constructor to avoid implicit conversions
    explicit PNGExporter() {}

    // Override exportImage method
    void exportImage(const std::string& imageData) const override {
        std::cout << "Exporting image data to PNG format: " << imageData << std::endl;
    }

    // Move constructor
    PNGExporter(PNGExporter&& other) noexcept = default;

    // Move assignment operator
    PNGExporter& operator=(PNGExporter&& other) noexcept = default;

    // Disable copy constructor and copy assignment operator
    PNGExporter(const PNGExporter&) = delete;
    PNGExporter& operator=(const PNGExporter&) = delete;
};

// Concrete exporter for JPEG format
class JPEGExporter : public ImageExporter {
public:
    // Explicit constructor to avoid implicit conversions
    explicit JPEGExporter() {}

    // Override exportImage method
    void exportImage(const std::string& imageData) const override {
        std::cout << "Exporting image data to JPEG format: " << imageData << std::endl;
    }

    // Move constructor
    JPEGExporter(JPEGExporter&& other) noexcept = default;

    // Move assignment operator
    JPEGExporter& operator=(JPEGExporter&& other) noexcept = default;

    // Disable copy constructor and copy assignment operator
    JPEGExporter(const JPEGExporter&) = delete;
    JPEGExporter& operator=(const JPEGExporter&) = delete;
};

// Concrete exporter for BMP format
class BMPExporter : public ImageExporter {
public:
    // Explicit constructor to avoid implicit conversions
    explicit BMPExporter() {}

    // Override exportImage method
    void exportImage(const std::string& imageData) const override {
        std::cout << "Exporting image data to BMP format: " << imageData << std::endl;
    }

    // Move constructor
    BMPExporter(BMPExporter&& other) noexcept = default;

    // Move assignment operator
    BMPExporter& operator=(BMPExporter&& other) noexcept = default;

    // Disable copy constructor and copy assignment operator
    BMPExporter(const BMPExporter&) = delete;
    BMPExporter& operator=(const BMPExporter&) = delete;
};

// Factory function to create appropriate exporter based on format
std::shared_ptr<ImageExporter> createExporter(const std::string& format) {
    if (format == "PNG") {
        return std::make_shared<PNGExporter>();
    } else if (format == "JPEG") {
        return std::make_shared<JPEGExporter>();
    } else if (format == "BMP") {
        return std::make_shared<BMPExporter>();
    } else {
        throw std::runtime_error("Unsupported format.");
    }
}

// Function to demonstrate exporting
void exportImage(const std::shared_ptr<ImageExporter>& exporter, const std::string& imageData) {
    exporter->exportImage(imageData);
}

int main() {
    try {
        // Create exporters for different formats
        auto pngExporter = createExporter("PNG");
        auto jpegExporter = createExporter("JPEG");
        auto bmpExporter = createExporter("BMP");

        // Export image data
        std::string sampleImageData = "Sample Image Data";
        exportImage(pngExporter, sampleImageData);
        exportImage(jpegExporter, sampleImageData);
        exportImage(bmpExporter, sampleImageData);

        // Testing move semantics for PNGExporter
        auto movedPNGExporter = std::move(pngExporter); // pngExporter is now empty
        exportImage(movedPNGExporter, "Moved PNG Image Data");

        // Test unsupported format
        try {
            auto unsupportedExporter = createExporter("GIF"); // This will throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Test using move semantics and exception handling
        try {
            auto newPNGExporter = createExporter("PNG");
            auto anotherPNGExporter = std::move(newPNGExporter); // Move constructor in action
            exportImage(anotherPNGExporter, "Another PNG Image Data");
            // Ensure newPNGExporter is empty
            if (!newPNGExporter) {
                std::cout << "newPNGExporter is empty after move." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception during move: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}

//Open-Closed Principle (OCP): The design allows adding new image exporters (formats) without modifying existing code.
    //C++14 Features:
    //Move Semantics: Efficiently manage resource transfers.
    //Explicit Constructors: Avoid unintended implicit conversions.
    //Exception Handling: Gracefully handle unsupported formats.
    //Tests:
    //Creation and usage of exporters for PNG, JPEG, and BMP formats.
    //Demonstration of move semantics.
    //Handling of unsupported formats with exceptions.

#endif /* __task_OCP_h */
