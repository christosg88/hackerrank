#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of cities and stations
	size_t num_cities, num_stations;
	std::cin >> num_cities >> num_stations;

	// the indexes of the cities having a station
	std::vector<size_t> stations(num_stations);
	for (size_t i = 0; i < num_stations; i++)
		std::cin >> stations[i];

	// sort the indexes of stations
	std::sort(stations.begin(), stations.end());

	// initialize the max_distance with the maximum distance of the 0th city
	// and the first station, and the last city and the last station
	size_t max_distance = std::max(*stations.begin(), num_cities - *(stations.end() - 1) - 1);

	// now check the cities in-between gas stations
	for (size_t i = 0; i < num_stations - 1; i++)
	{
		size_t distance = (stations[i + 1] - stations[i]) / 2;
		if (distance > max_distance)
			max_distance = distance;
	}

	std::cout << max_distance << '\n';

	return 0;
}