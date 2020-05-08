//
// Created by skidr on 03/04/2020.
//

#include "CSVReader.h"

#include <exception>
#include <utility>

CSVReader::CSVReader(const std::string& filename, std::string delimiter) {
    this->delimiter = std::move(delimiter);
    this->filename = filename;
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
    std::ifstream file(this->filename);

    if (!file.is_open())
        throw FileNotFound(filename);

    std::string line;
    getline(file, line);                  // skip header
    while (getline(file, line)) {
        data.push_back(parseString(line, delimiter));
    }

    file.close();
    return data;
}

CSVReader::~CSVReader() {

}

// Exception class
FileNotFound::FileNotFound(const std::string &filename) : filename(filename) {

}

const std::string &FileNotFound::getFilename() const {
    return filename;
}
