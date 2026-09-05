#include <iostream>
#include "hat.hpp"
#include "circularlinkedlist.hpp"

using namespace std;

// Helper function to double check user entered an integer and not something else
bool read_integer(const string& prompt, int& value) {

    // Keep repeating until return exits the function
    while (true) {

        // Print the question
        cout << prompt;

        if (cin >> value) {
            return true;
        }
        
        if (cin.eof()) {
            return false;
        }
        
        /* Input has failed */
        cout << "Please enter a whole number.\n";   
        /* Reset cin's error state to read again */
        cin.clear();    

        // Discard rest of the line
        string discarded;
        getline(cin, discarded);
    }
}

void prompt_hat_search(const CircularList<Hat>& hat_collection) {
    int field_choice;

    while (true) {
        cout << "\nSearch hats by:\n"
             << "1. ID\n"
             << "2. Color\n"
             << "3. Brand\n"
             << "4. Coolness level\n";

        if (!read_integer("Enter your choice (1-4): ", field_choice)) {
            return;
        }

        if (field_choice >= 1 && field_choice <= 4) {
            break;
        }

        cout << "Please choose a number from 1 through 4.\n";
    }

    size_t match_count = 0;

    switch (field_choice) {
        case 1: {
            int id;
            if (!read_integer("Enter the hat ID: ", id)) {
                return;
            }
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [id](const Hat& hat) { return hat.get_id() == id; });
            break;
        }
        case 2: {
            string color;
            cout << "Enter the hat color: ";
            getline(cin >> ws, color);
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [&color](const Hat& hat) { return hat.get_color() == color; });
            break;
        }
        case 3: {
            string brand;
            cout << "Enter the hat brand: ";
            getline(cin >> ws, brand);
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [&brand](const Hat& hat) { return hat.get_brand() == brand; });
            break;
        }
        case 4: {
            int coolness_level;
            if (!read_integer("Enter the coolness level: ", coolness_level)) {
                return;
            }
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [coolness_level](const Hat& hat) {
                    return hat.get_coolness_level() == coolness_level;
                });
            break;
        }
    }

    if (match_count == 0) {
        cout << "No matching hats found.\n";
    } else {
        cout << match_count << (match_count == 1 ? " match found.\n" : " matches found.\n");
    }
}

int main() {
    // hat collection
    CircularList<Hat> hat_collection;

    cout << "Welcome to the hat collection simulator. \nEnter the amount of hats you have:";
    int hat_amount;
    cin >> hat_amount;
    for (int i = 0; i < hat_amount; i++) {

        cout << "Editing hat " << i + 1 << " \nEnter the hat color:";
        string hat_color;
        getline(cin >> ws, hat_color);
        cout << "Enter the hat brand:";
        string hat_brand;
        getline(cin >> ws, hat_brand);
        cout << "Enter the hat coolness level:";
        int hat_coolness_level;
        cin >> hat_coolness_level;
        Hat hat(hat_color, hat_brand, hat_coolness_level, i + 1);
        hat_collection.insert(hat);

    }

    hat_collection.display();
    prompt_hat_search(hat_collection);

    return 0;
}
