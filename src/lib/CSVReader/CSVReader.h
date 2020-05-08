#ifndef CSV_TO_SQL_CSVREADER_H
#define CSV_TO_SQL_CSVREADER_H

#include <string>
#include <vector>
#include <fstream>

/**
 * @brief Class CSVReader
 */
class CSVReader {
    std::ifstream file;     //!< stream to the file
    std::string delimiter;  //!< delimiter to be used to parse data (usually ",")
public:
    /**
     * @brief Constructor
     * @param filename path to file to be parsed
     * @param delimiter delimiter to be used to parse data
     */
    CSVReader(const std::string& filename, std::string delimiter);
    /**
     * @brief Destructor
     */
    ~CSVReader();
    /**
     * @brief Function to return data
     * @return vector of line vectors (each vector inside this vector contains all line columns)
     */
    std:: vector<std::vector<std::string>> getData();
};

/**
 * @brief Exepction class for not found file
 */
class FileNotFound {
    std::string filename;   //!< Filename not found
public:
    FileNotFound(const std::string &filename);
    const std::string &getFilename() const;
};

#endif //CSV_TO_SQL_CSVREADER_H
