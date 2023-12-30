#include <iostream>
#include <string>
#include <algorithm> // for sorting

using namespace std;

const int numCharities = 3;

void setupDonationSystem(string charityNames[], double donationTotals[]) {
    cout << "Enter the name of Charity 1: ";
    getline(cin, charityNames[0]);

    cout << "Enter the name of Charity 2: ";
    getline(cin, charityNames[1]);

    cout << "Enter the name of Charity 3: ";
    getline(cin, charityNames[2]);

    // Resetting totals to zero
    for (int i = 0; i < numCharities; ++i) {
        donationTotals[i] = 0;
    }

    cout << "Donation system is set up." << endl;
}

void recordDonation(string charityNames[], double donationTotals[]) {
    int choice;
    double shoppingBill;

    cout << "Enter the charity choice (-1 to show totals, 1, 2, or 3 to donate): ";
    cin >> choice;

    cin.ignore();

    if (choice == -1) {
        cout << "Totals so far in descending order:" << endl;
        pair<double, string> totalsWithNames[numCharities];

        for (int i = 0; i < numCharities; ++i) {
            totalsWithNames[i] = {donationTotals[i], charityNames[i]};
        }

        sort(totalsWithNames, totalsWithNames + numCharities, greater<pair<double, string> >());

        for (int i = 0; i < numCharities; ++i) {
            cout << totalsWithNames[i].second << ": $" << totalsWithNames[i].first << endl;
        }

        // Calculate and output grand total
        double grandTotal = donationTotals[0] + donationTotals[1] + donationTotals[2];
        cout << "GRAND TOTAL DONATED TO CHARITY: $" << grandTotal << endl;
        return;
    }

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
        return;
    }

    cout << "Enter the customer's shopping bill: $";
    cin >> shoppingBill;

    double donation = shoppingBill * 0.01;

    // Assign the donation to the selected charity and update total donations
    donationTotals[choice - 1] += donation;
    cout << "Donated to " << charityNames[choice - 1] << ": $" << donation << endl;
}

int main() {
    string charityNames[numCharities];
    double donationTotals[numCharities];

    setupDonationSystem(charityNames, donationTotals);

    bool continueDonations = true;

    while (continueDonations) {
        recordDonation(charityNames, donationTotals);

        cout << "Continue donations? (0 for no, 1 for yes): ";
        int continueChoice;
        cin >> continueChoice;

        continueDonations = continueChoice == 1;
        
        cin.ignore();
    }

    return 0;
}

