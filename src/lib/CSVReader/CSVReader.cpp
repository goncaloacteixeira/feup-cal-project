//
// Created by skidr on 03/04/2020.
//

#include "CSVReader.h"

#include <exception>
#include <utility>

CSVReader::CSVReader(const std::string& filename, std::string delimiter) {
    this->delimiter = std::move(delimiter);
    this->file = std::ifstream(filename);

    if (!this->file.is_open()) {
        throw FileNotFound(filename);
    }
}

std::vector<std::string> parseString(std::string s, std::string delimiter) {
    std::vector<std::string> line;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        line.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    line.push_back(s);
    return line;
}

std::vector<std::vector<std::string>> CSVReader::getData() {
    std::vector<std::vector<std::string>> data;

    std::string line;
    getline(this->file, line);                  // skip header
    while (getline(this->file, line)) {
        data.push_back(parseString(line, delimiter));
    }

    return data;
}

CSVReader::~CSVReader() {
    this->file.close();
}



// Exception class

FileNotFound::FileNotFound(const std::string &filename) : filename(filename) {

}

const std::string &FileNotFound::getFilename() const {
    return filename;
}
