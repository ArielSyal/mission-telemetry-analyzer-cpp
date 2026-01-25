#include "TelemetryAnalyzer.h"
#include <iostream>
#include <limits>

void TelemetryAnalyzer::analyze(const std::vector<TelemetryRecord>& records) {
    if (records.empty()) {
        std::cout << "No telemetry data available.\n";
        return;
    }

    double tempMin = std::numeric_limits<double>::max();
    double tempMax = std::numeric_limits<double>::lowest();
    double tempSum = 0;
    int tempAnomalies = 0;

    double voltMin = std::numeric_limits<double>::max();
    double voltMax = std::numeric_limits<double>::lowest();
    double voltSum = 0;
    int voltAnomalies = 0;

    double altMin = std::numeric_limits<double>::max();
    double altMax = std::numeric_limits<double>::lowest();
    double altSum = 0;
    int altAnomalies = 0;

    for (const auto& r : records) {
        tempMin = std::min(tempMin, r.temperature);
        tempMax = std::max(tempMax, r.temperature);
        tempSum += r.temperature;
        if (r.temperature < -20 || r.temperature > 80) tempAnomalies++;

        voltMin = std::min(voltMin, r.voltage);
        voltMax = std::max(voltMax, r.voltage);
        voltSum += r.voltage;
        if (r.voltage < 3.0 || r.voltage > 4.2) voltAnomalies++;

        altMin = std::min(altMin, r.altitude);
        altMax = std::max(altMax, r.altitude);
        altSum += r.altitude;
        if (r.altitude < 350 || r.altitude > 450) altAnomalies++;
    }

    std::cout << "\nMission Telemetry Report\n";
    std::cout << "Data points analyzed: " << records.size() << "\n\n";

    std::cout << "Temperature (C):\n";
    std::cout << "  Min: " << tempMin << "\n";
    std::cout << "  Max: " << tempMax << "\n";
    std::cout << "  Avg: " << tempSum / records.size() << "\n";
    std::cout << "  Anomalies detected: " << tempAnomalies << "\n\n";

    std::cout << "Voltage (V):\n";
    std::cout << "  Min: " << voltMin << "\n";
    std::cout << "  Max: " << voltMax << "\n";
    std::cout << "  Avg: " << voltSum / records.size() << "\n";
    std::cout << "  Anomalies detected: " << voltAnomalies << "\n\n";

    std::cout << "Altitude (km):\n";
    std::cout << "  Min: " << altMin << "\n";
    std::cout << "  Max: " << altMax << "\n";
    std::cout << "  Avg: " << altSum / records.size() << "\n";
    std::cout << "  Anomalies detected: " << altAnomalies << "\n";
}
