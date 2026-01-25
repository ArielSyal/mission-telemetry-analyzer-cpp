## Mission Telemetry Data Analyzer (C++)

### Overview
This project analyzes spacecraft telemetry data to compute sensor statistics
and detect anomalies based on predefined  thresholds

### Features
- CSV file parsing
- statistical analysis (min, max, average)
- anomaly detection
- terminal report output

### Technologies
- C++17
- Standard Library (iostream, vector, string, fstream)

### How to Run
```bash
g++ -std=c++17 src/*.cpp -o telemetry
./telemetry data/telemetry.csv
