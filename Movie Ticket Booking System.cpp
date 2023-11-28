#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main()
{
    
    srand(time(0));

    string movies[5] = {"3 Idiots", "Hera Pheri", "Bhool Bhulaiyaa", "Hungama", "Dhamaal"};

    const int no_movies = 5, no_show_timings = 3;

    string showTimings[5][3] =
        {
            {"9:00 AM", "1:00 PM", "6:00 PM"},
            {"10:00 AM", "2:00 PM", "7:00 PM"},
            {"9:30 AM", "1:30 PM", "6:30 PM"},
            {"10:30 AM", "2:30 PM", "7:30 PM"},
            {"11:00 AM", "3:00 PM", "8:00 PM"}
		};

    int ticket_Prices[5][3] =
        {
            {100, 175, 250},
            {120, 190, 290},
            {130, 200, 320},
            {150, 230, 310},
            {140, 250, 320}
		};

    const int no_rows = 10, no_seats_per_row = 10;
    int seats[no_rows][no_seats_per_row];

    // seat availability 
    for (int i = 0; i < no_rows; i++)
    {
        for (int j = 0; j < no_seats_per_row; j++)
        {
            seats[i][j] = rand() % 2; // 0 or 1 (available or not available)
        }
    }

    //  total seats
    int total_seats = no_rows * no_seats_per_row;
    cout << "\n Total Seats: " << total_seats << endl;

    // select movie
    cout << "\n Movies:\n";
    for (int i = 0; i < no_movies; i++)
    {
        cout << i + 1 << ". " << movies[i] << endl;
    }

    // movie selection
    int selected_Movie;
    cout << "\n Select a movie (1-" << no_movies << "): ";
    cin >> selected_Movie;

    selected_Movie--;

    // Movie shows
    if (selected_Movie >= 0 && selected_Movie < no_movies)
    {
        cout << "\n1. Morning Show";
        cout << "\n2. Afternoon Show";
        cout << "\n3. Evening Show";

        // movie show time
        int selected_ShowTime;

        cout << "\n\n Select a show time (1-" << no_show_timings << "): ";
        cin >> selected_ShowTime;

        selected_ShowTime--;

        if (selected_ShowTime >= 0 && selected_ShowTime < no_show_timings)
        {
            // selected movie and show time
            cout << "\n You have selected the movie: " << movies[selected_Movie];
            cout << "\n Show time: " << showTimings[selected_Movie][selected_ShowTime];
            cout << "\n Ticket Price: INR" << ticket_Prices[selected_Movie][selected_ShowTime] << endl;

            // seat availability
            cout << "\n Seat Availability:\n";
            int available_seats = total_seats;

            // seat numbers
            cout << "      ";
            for (int k = 1; k <= no_seats_per_row; k++)
            {
                cout << k << " ";
            }
            cout << "\n";

            for (int i = 0; i < no_rows; i++)
            {
                cout << "Row " << (i + 1) << ": ";
                for (int j = 0; j < no_seats_per_row; j++)
                {
                    cout << (seats[i][j] ? "O" : "X") << " ";
                    if (seats[i][j] == 0)
                    {
                        available_seats--;
                    }
                }
                cout << endl;
            }

            cout << "\n Available Seats: " << available_seats << endl;

            // Seat selection and booking
            int num_seats;
            cout << "\n Enter the number of seats you want to book: ";
            cin >> num_seats;

            vector<int> selected_Seats;

            for (int i = 0; i < num_seats; ++i)
            {
                int selected_Row, selected_Seat;

                cout << "\n Select a row (1-" << no_rows << "): ";
                cin >> selected_Row;

                selected_Row--;

                if (selected_Row >= 0 && selected_Row < no_rows)
                {
                    cout << "\n Select a seat (1-" << no_seats_per_row << "): ";
                    cin >> selected_Seat;
                    selected_Seat--;

                    if (selected_Seat >= 0 && selected_Seat < no_seats_per_row && seats[selected_Row][selected_Seat] == 1)
                    {
                        // Book the seat
                        seats[selected_Row][selected_Seat] = 0;
                        selected_Seats.push_back(ticket_Prices[selected_Movie][selected_ShowTime]);
                        cout << "\n Seat " << (i + 1) << " (Row " << selected_Row + 1 << ", Seat " << selected_Seat + 1 << ") booked successfully!";
                    }
                    else
                    {
                        cout << "\n Invalid seat selection or seat already booked. Please try again.";
                        --i; // enter seat again
                    }
                }
                else
                {
                    cout << "\n Invalid row selection. Please try again.";
                    --i; // enter seat again
                }
            }

            // total cost
            int total_Cost = 0;
            for (int i = 0; i < selected_Seats.size(); i++)
            {
                total_Cost += selected_Seats[i];
            }

            cout << "\n\n Total Cost for " << num_seats << " seat(s): INR" << total_Cost << endl;

            // Payment option
            cout << "\n\n Payment Option:";
            cout << "\n 1. Credit Card";
            cout << "\n 2. Debit Card";
            cout << "\n 3. Google Pay UPI ID";
            cout << "\n Choose a payment option (1-3): ";
            int paymentOption;
            cin >> paymentOption;

            if (paymentOption >= 1 && paymentOption <= 3)
            {
                string paymentMethod;
                switch (paymentOption)
                {
                case 1:
                    paymentMethod = "Credit Card";
                    break;
                case 2:
                    paymentMethod = "Debit Card";
                    break;
                case 3:
                    paymentMethod = "Google Pay UPI ID";
                    break;
                }

                cout << "\n Enter your " << paymentMethod << " details: ";
                cin >> paymentMethod;
                
                // payment done
                
                cout << "\n Payment successful! Enjoy the movie.\n";
            }
            else
            {
                cout << "\n Invalid payment option. Exiting.\n";
            }
        }
        else
        {
            cout << "\n ERROR. Invalid show time. \n";
        }
    }
    else
    {
        cout << "\n ERROR. Invalid movie. \n";
    }

    return 0;
}

