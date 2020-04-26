#ifndef PSEUDO_RANDOM_GENERATOR_CSVEXPORTER_H
#define PSEUDO_RANDOM_GENERATOR_CSVEXPORTER_H

#include <fstream>
#include <cstdint>

namespace tools {

class CsvExporter {
private:
    std::ofstream _fstream;
    uint32_t _columns_count;

public:
    CsvExporter(const std::string& file_name, int columns_count);
    ~CsvExporter();

    void addRow(const std::string columns[]);
};

}


#endif //PSEUDO_RANDOM_GENERATOR_CSVEXPORTER_H
