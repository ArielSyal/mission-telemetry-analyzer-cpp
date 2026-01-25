#ifndef TELEMETRY_ANALYZER_H
#define TELEMETRY_ANALYZER_H

#include <vector>
#include "TelemetryRecord.h"

class TelemetryAnalyzer {
public:
    static void analyze(const std::vector<TelemetryRecord>& records);
};

#endif
