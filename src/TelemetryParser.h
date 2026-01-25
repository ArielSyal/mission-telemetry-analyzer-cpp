#ifndef TELEMETRY_PARSER_H
#define TELEMETRY_PARSER_H

#include <string>
#include <vector>
#include "TelemetryRecord.h"

class TelemetryParser{
    public:
    static std::vector<TelemetryRecord> parseCSV(const std::string& filename);
};

#endif


