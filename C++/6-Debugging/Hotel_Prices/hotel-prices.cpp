#include <iostream>
#include <vector>

class HotelRoom {
private:
    int num_bedrooms;
    int num_bathrooms;

public:
    HotelRoom(int num_bedrooms, int num_bathrooms) : num_bedrooms(num_bedrooms), num_bathrooms(num_bathrooms) {
    }

    virtual int get_price() {
        return 50 * num_bedrooms + 100 * num_bathrooms;
    }
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int num_bedrooms, int num_bathrooms) : HotelRoom(num_bedrooms, num_bathrooms) {
    }

    int get_price() override {
        return HotelRoom::get_price() + 100;
    }
};

using namespace std;

int main() {
    int num_rooms;
    std::cin >> num_rooms;
    std::vector<HotelRoom *> rooms;
    for (int i = 0; i < num_rooms; ++i) {
        std::string room_type;
        int num_bedrooms;
        int num_bathrooms;
        std::cin >> room_type >> num_bedrooms >> num_bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(num_bedrooms, num_bathrooms));
        }
        else {
            rooms.push_back(new HotelApartment(num_bedrooms, num_bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    std::cout << total_profit << "\n";

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}
