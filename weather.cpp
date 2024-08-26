#include <iostream>
#include <vector>
using namespace std;

class WeatherData {
private:
    vector<float> temperatures;
    vector<float> humidities;
    vector<float> pressures;

public:
    void recordData(float temp, float humidity, float pressure) {
        temperatures.push_back(temp);
        humidities.push_back(humidity);
        pressures.push_back(pressure);
    }

    float calculateAverage(vector<float>& data) {
        float sum = 0;
        for (float value : data) {
            sum += value;
        }
        return sum / data.size();
    }

    void displayAverage() {
        cout << "Average Temperature: " << calculateAverage(temperatures) << "°C" << endl;
        cout << "Average Humidity: " << calculateAverage(humidities) << "%" << endl;
        cout << "Average Pressure: " << calculateAverage(pressures) << " hPa" << endl;
    }
};

int main() {
    WeatherData weather;
    int n;

    cout << "Enter the number of data points: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        float temp, humidity, pressure;
        cout << "Enter temperature (°C), humidity (%), and pressure (hPa) for data point " << i + 1 << ": ";
        cin >> temp >> humidity >> pressure;
        weather.recordData(temp, humidity, pressure);
    }

    weather.displayAverage();

    return 0;
}
