#include <iostream>
#include <string>

#include "hat_helpers.hpp"

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
            cout << "-----------------------------------";
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [id](const Hat& hat) { return hat.get_id() == id; });
            cout << "-----------------------------------" << endl;
            break;
        }
        case 2: {
            string color;
            cout << "Enter the hat color: ";
            getline(cin >> ws, color);
            cout << "-----------------------------------";
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [&color](const Hat& hat) { return hat.get_color() == color; });
            cout << "-----------------------------------" << endl;
            break;
        }
        case 3: {
            string brand;
            cout << "Enter the hat brand: ";
            getline(cin >> ws, brand);
            cout << "-----------------------------------";
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [&brand](const Hat& hat) { return hat.get_brand() == brand; });
            cout << "-----------------------------------" << endl;
            break;
        }
        case 4: {
            int coolness_level;
            if (!read_integer("Enter the coolness level: ", coolness_level)) {
                return;
            }
            cout << "-----------------------------------";
            cout << "\nSearch results:\n";
            match_count = hat_collection.search(
                [coolness_level](const Hat& hat) {
                    return hat.get_coolness_level() == coolness_level;
                });
            cout << "-----------------------------------" << endl;
            break;
        }
    }

    if (match_count == 0) {
        cout << "No matching hats found.\n" << endl;
    } else {
        cout << match_count << (match_count == 1 ? " match found." : " matches found.") << endl;
    }
}

// Custom function for adding hats instead of having it be done inside of main()
void add_hats(CircularList<Hat>& hat_collection, int& next_id) {

    int count = 0;

    if (!read_integer("How many hats would you like to add? ", count) || count <= 0) {
        cout << "No hats added.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nAdding Hat #" << next_id << "\n";

        cout << "Enter the hat color: ";
        string color;
        getline(cin >> ws, color);

        cout << "Enter the hat brand: ";
        string brand;
        getline(cin >> ws, brand);

        int coolness_level;
        read_integer("Enter the hat coolness level: ", coolness_level);

        Hat new_hat(color, brand, coolness_level, next_id++);
        hat_collection.insert(new_hat);
    }
    cout << "\nSuccessfully added " << count << " hat(s)" << endl;
}
