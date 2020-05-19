//
// Created by Yao Huang on 2020-05-19.
//

#include <iostream>

#include "boost/filesystem.hpp"
#include "boost/math/common_factor.hpp"

using namespace boost::filesystem;

int getGCD() {
    int gcd = boost::math::gcd(12,8);
    return gcd;
}

int checkFileSystem() {
    boost::filesystem::path path(".");
    bool result = boost::filesystem::is_directory(path);
    return result;
}
