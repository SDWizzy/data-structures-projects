#include <iostream>
#include <string>
#include "hat_helpers.hpp"

using namespace std;

int main() {
    // hat collection
    CircularList<Hat> hat_collection;
    // hat carousel
    HatCarousel carousel(hat_collection);

    int next_id = 1;
    int choice = 0;

    cout << "Welcome to the Hat Collection Manager!" << endl;

    do {
		cout << "\nMenu:\n"
			<< "1. Add a hat\n"
			<< "2. Display all hats\n"
			<< "3. Search for hats\n"
			<< "4. Remove a hat\n"
            << "6. View hat caroussel\n"
			<< "7. Exit\n";

		if (!read_integer("Enter your choice (1-5): ", choice)) {
			break;
        }
        switch (choice) {
        case 1:
            add_hats(hat_collection, next_id);
            break;

        case 2:
            cout << "-----------------------------------" << endl;
            cout << "Current Collection:" << endl;
            hat_collection.display();
            cout << "-----------------------------------" << endl;
            break;

        case 3:
            prompt_hat_search(hat_collection);
            break;

        case 4: {
            cout << "\nEnter the details of the hat you wish to remove\n";
            cout << "Color: ";
            string color;
            getline(cin >> ws, color);

            cout << "Brand: ";
            string brand;
            getline(cin >> ws, brand);

			int coolness_level;
			read_integer("Coolness level: ", coolness_level);

			Hat target_hat(color, brand, coolness_level);
			hat_collection.remove(target_hat);
            cout << "Removal completed.\n";
            break;
            }

        case 6:
            carousel.run();
            break;


        case 7:
            cout << "Exiting program.\n";
            break;
            
        default:
            cout << "Invalid selection. Please choose a number from 1 through 5.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}

