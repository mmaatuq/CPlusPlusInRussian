//============================================================================
// Name        : BusStops2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
//10
//ALL_BUSES
//BUSES_FOR_STOP Marushkino
//STOPS_FOR_BUS 32K
//NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
//NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
//BUSES_FOR_STOP Vnukovo
//NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
//NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
//STOPS_FOR_BUS 272
//ALL_BUSES

//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
vector<string> BusesForStop(const map<string, vector<string>> &bus_storage,
		const string &stop) {
	vector<string> stops;
	for (auto &bus : bus_storage) {
		if (find(bus.second.begin(), bus.second.end(), stop)
				!= bus.second.end()) {
			stops.push_back(bus.first);
		}
	}
	return stops;
}

vector<string> BusesForStop(const map<string, vector<string>> &bus_storage,
		const string &stop, const string &org_bus) {
	vector<string> stops;
	for (auto &bus : bus_storage) {
		if (bus.first != org_bus
				&& find(bus.second.begin(), bus.second.end(), stop)
						!= bus.second.end()) {
			stops.push_back(bus.first);
		}
	}
	return stops;
}
//
//vector<string> AllBuses(const map<string, vector<string>> &bus_storage, const string &bus) {
//	vector<string> bus_stops;
//	auto &stops = bus_storage[bus];
//	for (auto &stop: stops) {
//		bus_stops.push_back(stop);
//	}
//	return bus_stops;
//}

int main() {
	map<string, vector<string>> bus_storage;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		string command;
		cin >> command;
		if (command == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			vector<string> stops(stop_count);
			for (auto &stop : stops) {
				cin >> stop;
			}
			bus_storage[bus] = stops;
		} else if (command == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			auto buses = BusesForStop(bus_storage, stop);
			if (buses.size() != 0) {
				for (auto &bus : buses) {
					cout << bus << " ";
				}
			} else {
				cout << "No stop";
			}
			cout << endl;
		} else if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			if (bus_storage.find(bus) == bus_storage.end()) {
				cout << "No bus" << endl;
			} else {
				for (auto &stop : bus_storage[bus]) {
					auto buses = BusesForStop(bus_storage, stop, bus);
					if (buses.size() == 0) {
						cout << "Stop " << stop << ":" << " no interchange"
								<< endl;
					} else {
						cout << "Stop " << stop << ": ";
						for (auto &bus : buses) {
							cout << bus << " ";
						}
						cout << endl;
					}
				}
			}

		} else {
			if (bus_storage.size() == 0) {
				cout << "No buses" << endl;
			} else {
				for (auto &bus : bus_storage) {
					auto stops = bus.second;
					cout << "Bus " << bus.first << ": ";
					for (auto &stop : stops) {
						cout << stop << " ";
					}
					cout << endl;
				}

			}
		}
	}
	return 0;
}
