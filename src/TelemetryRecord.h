#ifndef TELEMETRY_RECORD_H
#define TELEMETRY_RECORD_H

#include <string>

struct TelemetryRecord {
    std::string timestamp;
    double temperature;
    double voltage;
    double altitude;
};

#endif


