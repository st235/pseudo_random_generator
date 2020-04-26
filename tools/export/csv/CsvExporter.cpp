#include "CsvExporter.h"

#include <iomanip>

namespace tools {

CsvExporter::CsvExporter(const std::string& file_name, int columns_count): _columns_count(columns_count) {
    _fstream.open(file_name + ".csv");

    if (!_fstream) {
        throw std::runtime_error("cannot open file to write data");
    }
}

void CsvExporter::addRow(const std::string columns[]) {
    for (int i = 0; i < _columns_count; i++) {
        _fstream << columns[i];

        if (i != _columns_count - 1) {
            _fstream << ",";
        }
    }

    _fstream << std::endl;
}

CsvExporter::~CsvExporter() {
    _fstream.close();
}

}  // namespace tools
