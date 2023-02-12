#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct WeatherData {
    int day;
    int temperature;
};

int main() {
    // Open the weather data file
    std::ifstream file("weather_data.txt");
    /*
    This code assumes that the weather data is stored in a text file 
    called weather_data.txt, with each line in the following format:
    <day> <temperature>
    Where <day> is the number of the day (an integer) 
    and <temperature> is the temperature in degrees (also an integer).
    */
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // Read the temperature data into a vector
    std::vector<WeatherData> data;
    while (file) {
        WeatherData entry;
        file >> entry.day >> entry.temperature;
        data.push_back(entry);
    }

    // Ask the user for the temperature range for a picnic
    int min_temperature, max_temperature;
    std::cout << "Enter the minimum temperature for a picnic: ";
    std::cin >> min_temperature;
    std::cout << "Enter the maximum temperature for a picnic: ";
    std::cin >> max_temperature;

    // Pick the best days for a picnic based on the temperature range
    std::cout << "The best days for a picnic are:\n";
    for (const auto& entry : data) {
        if (entry.temperature >= min_temperature && entry.temperature <= max_temperature) {
            std::cout << "Day " << entry.day << ": " << entry.temperature << " degrees\n";
        }
    }

    return 0;
}
