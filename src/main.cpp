#include <iostream>
#include "TelemetryParser.h"
#include "TelemetryAnalyzer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./telemetry <path_to_csv>\n";
        return 1;
    }

    auto records = TelemetryParser::parseCSV(argv[1]);
    TelemetryAnalyzer::analyze(records);

    return 0;
}
