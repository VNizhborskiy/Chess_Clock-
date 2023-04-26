#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std::chrono;
using namespace std;

int us_choice;

void Timer(int minutes1, int seconds1, int minutes2, int seconds2, char symb_min1, char symb_sec1, char symb_min2, char symb_sec2, int increment) {
    system("cls");
    int x = 1; // счетчик для _khbit() 
    int i = 1; // счетчк для increment
    char ch; // Enter пользователя до начала игры
    // Рисование нулей
    if (minutes1 < 10)
    {
        symb_min1 = '0';
    }
    else if (minutes1 >= 10)
    {
        symb_min1 = '\0';
    }
    if (seconds1 < 10)
    {
        symb_sec1 = '0';
    }
    else if (seconds1 >= 10)
    {
        symb_sec1 = '\0';
    }
    if (minutes2 < 10)
    {
        symb_min2 = '0';
    }
    else if (minutes2 >= 10)
    {
        symb_min2 = '\0';
    }
    if (seconds2 < 10)
    {
        symb_sec2 = '0';
    }
    else if (seconds2 >= 10)
    {
        symb_sec2 = '\0';
    }
    // 
    
    cout << "                                        ";
    cout << symb_min1 << minutes1 << ":" << symb_sec1 << seconds1;
    cout << "                                        ";
    cout << symb_min2 << minutes2 << ":" << symb_sec2 << seconds2;
    cout << "\n\n                                                       Type + to start... \n";
    cin >> ch;
    
    if (ch == '+')
    {
        system("cls");
        if (increment != 0)
        {
            i += 1;
        }
        while (true)
        {
            // Рисование нулей
            if (minutes1 < 10)
            {
                symb_min1 = '0';
            }
            else if (minutes1 >= 10)
            {
                symb_min1 = '\0';
            }
            if (seconds1 < 10)
            {
                symb_sec1 = '0';
            }
            else if (seconds1 >= 10)
            {
                symb_sec1 = '\0';
            }
            if (minutes2 < 10)
            {
                symb_min2 = '0';
            }
            else if (minutes2 >= 10)
            {
                symb_min2 = '\0';
            }
            if (seconds2 < 10)
            {
                symb_sec2 = '0';
            }
            else if (seconds2 >= 10)
            {
                symb_sec2 = '\0';
            }
            //
            cout << "                                        ";
            cout << symb_min1 << minutes1 << ":" << symb_sec1 << seconds1;
            cout << "                                        ";
            cout << symb_min2 << minutes2 << ":" << symb_sec2 << seconds2;
            if (minutes1 == 0 && seconds1 == 0) {
                cout << "                                        ";
                cout << "\nPlayer 1 Time over\n\n";
                break;
            }
            if (minutes2 == 0 && seconds2 == 0) {
                cout << "                                        ";
                cout << "\nPlayer 2 Time over\n\n";
                break;
            }
            this_thread::sleep_for(0.999s);
            if (_kbhit())
            {
                x++;
                i++;
                _getch();

            }
            if (x % 2 != 0 && seconds1 != -1)
            {
                
                if (i > 1 && x > 1)
                {
                    seconds2 += increment;
                    i = 1;
                    system("cls");
                    continue;
                    
                }
                seconds1--;
            }
            else if (x % 2 == 0 && seconds2 != -1)
            {

                
                if (i > 1 && x > 1)
                {
                    seconds1 += increment;
                    i = 1;
                    system("cls");
                    continue;
                
                }
                seconds2--;
            }
            // Проверки
            if (seconds1 == -1 && minutes1 != 0 && x % 2 != 0)
            {
                minutes1--;
                seconds1 = 59;

            }

            else if (seconds2 == -1 && minutes2 != 0 && x % 2 == 0)
            {
                minutes2--;
                seconds2 = 59;
            }
            //
            switch (seconds1)
            {
            case 60:
                seconds1 = 0;
                minutes1++;
                break;
            case 61:
                seconds1 = 1;
                minutes1++;
                break;
            case 62:
                seconds1 = 2;
                minutes1++;
                break;
            case 63:
                seconds1 = 3;
                minutes1++;
                break;
            case 64:
                seconds1 = 4;
                minutes1++;
                break;
            case 65:
                seconds1 = 5;
                minutes1++;
                break;
            }
            switch (seconds2)
            {
            case 60:
                seconds2 = 0;
                minutes2++;
                break;
            case 61:
                seconds2 = 1;
                minutes2++;
                break;
            case 62:
                seconds2 = 2;
                minutes2++;
                break;
            case 63:
                seconds2 = 3;
                minutes2++;
                break;
            case 64:
                seconds2 = 4;
                minutes2++;
                break;
            case 65:
                seconds2 = 5;
                minutes2++;
                break;
            }
            system("cls");
        }

    }
}

void presets() {
    cout << "Presets: \n";
    cout << 
        "Type 1 - Bullet 1+0 \n"
        "Type 2 - Bullet 2+1 \n"
        "Type 3 - Blitz 3+0 \n"
        "Type 4 - Blitz 3+2 \n"
        "Type 5 - Rapid 10+0 \n";
        "Type 6 - Classical 30+0 \n";
    cin >> us_choice;
    switch (us_choice)
    {
    case 1: 
        Timer(1, 0, 1, 0, '\0', '\0', '\0', '\0', 0);
        break;
    case 2:
        Timer(2, 0, 2, 0, '\0', '\0', '\0', '\0', 1);
        break;
    case 3:
        Timer(3, 0, 3, 0, '\0', '\0', '\0', '\0', 0);
        break;
    case 4:
        Timer(3, 0, 3, 0, '\0', '\0', '\0', '\0', 2);
        break;
    case 5:
        Timer(10, 0, 10, 0, '\0', '\0', '\0', '\0', 0);
        break;
    case 6:
        Timer(30, 0, 30, 0, '\0', '\0', '\0', '\0', 0);
        break;
    }
}

void new_custom_time() {
    string name;
    int minutes1_cst, seconds1_cst, minutes2_cst, seconds2_cst, increment_cst;
    cout << "                                        ";
    cout << "Custom Time \n";

    cout << "Enter Time: ";
    cout << "\nMinutes: ";
    cin >> minutes1_cst;
    minutes2_cst = minutes1_cst;
    cout << "\nSeconds: ";
    cin >> seconds1_cst;
    seconds2_cst = seconds1_cst;
    cout << "\nIncrement: ";
    cin >> increment_cst;
    Timer(minutes1_cst, seconds1_cst, minutes2_cst, seconds2_cst, '\0', '\0', '\0', '\0', increment_cst);


}

void start() {
    cout << "Please choose game mode: \n";
    cout << "Type 1 -- to choose preset (For Ex Blitz 3+0) \n";
    cout << "Type 2 -- to set up your own time \n";
    cin >> us_choice;
    switch (us_choice)
    {
        case 1:
            system("cls");
            presets();
            break;
        case 2:
            system("cls");
            new_custom_time();
            break;
    }
}


int main()
{
    start();   
}

// 26.04.2023