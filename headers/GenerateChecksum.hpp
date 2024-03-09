#pragma once

#include <iostream>
#include <fstream>

namespace nihil::nstd {
    uint32_t generateChecksum(const std::string file_path);
}