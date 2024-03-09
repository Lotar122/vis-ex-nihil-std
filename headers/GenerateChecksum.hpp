#pragma once

#include <iostream>
#include <fstream>

namespace nihil::nstd {
    uint32_t generateChecksum(const std::string file_path) {
        std::ifstream file(file_path, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << file_path << std::endl;
            return 0;
        }

        // Initialize checksum
        uint32_t checksum = 0;

        // Process the file byte by byte
        char byte;
        while (file.get(byte)) {
            checksum += static_cast<uint8_t>(byte);
        }

        file.close();

        return checksum;
    }
}