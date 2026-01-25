#include "TelemetryParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<TelemetryRecord> TelemetryParser::parseCSV(const std::string& filename){
    std:: vector<TelemetryRecord> records;
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return records;
    }

    std::string line;
    std::getline(file,line); //skips header

    while (std::getline(file,line)){
        std::stringstream ss(line);
        std::string token;
        TelemetryRecord record;
        
        std::getline(ss,record.timestamp, ',');
        
        std::getline(ss,token, ',');
        record.temperature = std::stod(token);
        
        std::getline(ss, token, ',');
        record.voltage = std::stod(token);

        std::getline(ss, token, ',');
        record.altitude = std::stod(token);

        records.push_back(record);

    }

    return records;

    }
