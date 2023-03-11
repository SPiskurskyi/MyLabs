#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
double Min(double* arr);

int main()
{
    while (true)
    {
        cout << "Show data - press 1" << endl;
        cout << "Write data - press 2" << endl;
        cout << "Exit - press 3" << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string name;
            double time[3];
            ifstream infile;
            infile.open("File.txt");
            if (!infile.is_open())
            {
                cout << "Cannot open file" << endl;
                return -1;
            }
            cout << setw(9) << "Name " << setw(15) << " 1-st time "<< setw(9) << " 2-nd time " 
                << setw(9) << " 3-rd time" << setw(9) << " Best result " 
                << setw(9) << "Avarage time" << "\n\n";
            while (!infile.eof())
            {
                infile >> name;
                infile >> time[0];
                infile >> time[1];
                infile >> time[2];
                if (!infile.eof())
                {
                    cout.width(9);
                    cout << name;
                    cout.width(10);
                    cout << time[0];
                    cout.width(11);
                    cout << time[1];
                    cout.width(11);
                    cout << time[2];
                    cout.width(11);
                    cout << Min(time);
                    cout.width(15);
                    cout << (time[0]+time[1]+time[2])/3;
                    cout << "\n\n";
                }
            }
            infile.close();
        }
        if (choice == 2)
        {
            string name;
            double time[3];
            cout << "Name - ";
            cin >> name;
            cout << "\nEnter first time - ";
            cin >> time[0];
            cout << "\nEnter secound time - ";
            cin >> time[1];
            cout << "\nEnter third time - ";
            cin >> time[2];
            fstream outfile("File.txt", ios::app);
            if (!outfile.is_open())
            {
                cout << "Cannot open file" << endl;
                return -1;
            }
            outfile.setf(ios::left);
            outfile.width(9);
            outfile << name << ' ';
            outfile.width(9);
            outfile << time[0] << endl;
            outfile.width(9);
            outfile << time[1] << endl;
            outfile.width(9);
            outfile << time[2] << endl;
            outfile.close();
        }
        if (choice == 3) break;
    }
}

double Min(double* arr)
{
    double min = arr[0];
    if (min > arr[1] && arr[1]!=0)
        min = arr[1];
    if (min > arr[2] && arr[2] != 0)
        min = arr[2];
    if (min != 0) {
        return min;
    }
    else cout << "Error";
}