#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

#include "code10.h"

void system_color(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

}

void animation::greeting() {
    char x = 178;

    for (int i = 0; i < 50; i++)
    {
        cout << x << x << x;
        cout << x << x << x;
        Sleep(5);
    }

    cout << " \t\t\t Welcome to ASUS " << endl;
    cout << " \t\t\t Welcome to ASUS " << endl;
    cout << " \t\t\t Welcome to ASUS " << endl;

    for (int i = 0; i < 50; i++)
    {
        cout << x << x << x;
        cout << x << x << x;
        Sleep(5);
    }
}

void animation::load_animation() {
    system_color(color_code);
    color_code++;
    greeting();

    system_color(color_code);
    color_code++;
    greeting();

    system_color(color_code);
    color_code++;
    greeting();

    system_color(color_code);
    system_color(color_code);
    color_code++;
    greeting();

    system_color(color_code);
    color_code++;
    greeting();
}

void animation::loading() {
    system_color(color_code);
    cout << " \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
    cout << "\t\t\t\t\t\t\tLOADING Please wait ..... : \n\n";

    char x = 178;
    for (int i = 0; i < 138; i++)
    {
        cout << x;
        Sleep(2);
    }
}

void Specs::setSpecs(string typeFile, string cameraFile, string simFile, string graphicsFile, string colorFile, string weightFile, string sizeFile)
{
    cout << "\nEnter ID (3 digits): ";
    cin >> IDFile;
    cout << "\nEnter processor: ";
    cin >> ProcessorFile;
    cout << "\nEnter memory: ";
    cin >> MemoryFile;
    cout << "\nEnter storage: ";
    cin >> StorageFile;
    cout << "\nEnter Price: ";
    cin >> PriceFile;
    cout << "\nEnter Stock: ";
    cin >> StockFile;
    ofstream write(IDFile + ".txt");
    write << "Product ID: " << IDFile << endl;
    write << "Product Type: " << typeFile << endl;
    write << "Processor: " << ProcessorFile << endl;
    write << "Memory: " << MemoryFile << endl;
    write << "Storage: " << StorageFile << endl;
    write << "Camera: " << cameraFile << endl;
    write << "SIM: " << simFile << endl;
    write << "Graphics: " << graphicsFile << endl;
    write << "Color: " << colorFile << endl;
    write << "Weight: " << weightFile << endl;
    write << "Size: " << sizeFile << endl;
    write << "Price: " << PriceFile << endl;
    write << "Stock: " << StockFile << endl;
    write.close();
    ofstream allwrite("listofallproducts.txt", ios::app);
    allwrite << IDFile << "\t" << typeFile << "\t" << ProcessorFile << "\t" << "    " << MemoryFile << "\t" << "  " << StorageFile << "\t" << cameraFile << "\t" << simFile << "\t" << graphicsFile << "\t" << colorFile << "\t" << weightFile << "\t" << sizeFile << "\t" << StockFile << "\t" << PriceFile << endl;
    allwrite << endl;
    allwrite.close();
    fstream price(IDFile + "price.txt", ios::app);
    price << PriceFile;
    price.close();
}

void Specs::getProducts()
{
    system("cls");
    cout << "Current Products Available" << endl;
    cout << "ID\t|Type\t|Processor\t|Memory\t|Storage\t|Price\t|Stock\t|Camera\t|SIM\t|Graphics\t|Color\t|Weight\t|Size " << endl;
    cout << endl;
    string line;
    ifstream read("listofallproducts.txt");
    while (getline(read, line)) {
        cout << line << endl;
    }
    read.close();
}

void Specs::searchproducts(string ID)
{
    string line;
    cout << endl;
    ifstream read(ID + ".txt");
    while (getline(read, line)) {
        cout << line << endl;
    }
    read.close();
    system("pause");
}

void Specs::deleteproducts(string ID)
{
    string temp = ID;
    temp += ".txt";
    const char* c = temp.c_str();
    string line;
    ofstream write;
    write.open("tempfile.txt");
    ifstream read("listofallproducts.txt");
    while (getline(read, line)) {
        if (ID != line.substr(0, 3))
        {
            write << line << endl;
        }
    }
    read.close();
    write.close();
    remove("listofallproducts.txt");
    rename("tempfile.txt", "listofallproducts.txt");
    remove(c);
    system("pause");
}

void Specs::buyproducts(string ID)
{
    string line, p;
    char a;
    cout << ":Product You want too buy:" << endl;
    ifstream read(ID + ".txt");
    while (getline(read, line)) {

        cout << line << endl;
    }
    read.close();
    ifstream red(ID + "price.txt");
    while (getline(red, p)) {
        cout << "Your bill is:" << p << endl;
    }
    red.close();
    cout << "Are you sure you want to buy this product(y/n) " << endl;
    cin >> a;
    if (a == 'y')

    {
        cout << "Purchase successfull!!" << endl;
    }
    else
    {
        exit(0);
    }
    system("pause");
}

void Desktop::setDesktop()
{
    cout << "Enter weight: ";
    cin >> weightFile;
    cout << "\nEnter size: ";
    cin >> sizeFile;
Specs: setSpecs(type, empty, empty, empty, empty, weightFile, sizeFile);
}

void Desktop_Gaming::setDesktop_Gaming()
{
Desktop: setDesktop();
}

void ProArt::setProArt()
{
Desktop: setDesktop();
}

void Mobile::setMobile()
{
    cout << "Enter Camera detail: ";
    cin >> camera;
    cout << "\nEnter SIM detail: ";
    cin >> sim;
Specs: setSpecs(type, camera, sim, empty, empty, empty, empty);
}

void ROG_phone::setROG_phone()
{
Mobile: setMobile();
}

void Zen_phone::setZen() {
Mobile: setMobile();
}

void Laptop::setLaptop()
{
    cout << "Enter Graphics detail:";
    cin >> graphics;
    cout << "\nEnter Color: ";
    cin >> color;
Specs: setSpecs(type, empty, empty, graphics, color, empty, empty);
}
void For_Student::setFor_Student() {
Laptop: setLaptop();
}

void Vivobook::setVivobook() {
For_Student: setFor_Student();
}

void Chromebook::setChromebook() {
For_Student: setFor_Student();
}

void For_Gaming::setFor_Gaming() {
Laptop: setLaptop();
}

void ROG::setROG() {
For_Gaming: setFor_Gaming();
}

void TUF::setTUF() {
For_Gaming: setFor_Gaming();
}

void Webpage::display()
{
    system("cls");
    cout << "Welcome, " << endl;
    cout << "1. view products" << endl;
    cout << "2. add products" << endl;
    cout << "3. delete products" << endl;
    cout << "4. search products" << endl;
    cout << "5. exit" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        system("cls");
        S.getProducts();
        break;
    case 2:
        system("cls");
        cout << "choose product type to add" << endl;
        cout << "1. Laptop" << endl;
        cout << "2. Desktop" << endl;
        cout << "3. Mobile" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            system("cls");
            cout << "choose laptop series" << endl;
            cout << "1. For Gaming" << endl;
            cout << "2. For Student" << endl;
            cin >> c;
            switch (c)
            {
            case 1:
                system("cls");
                cout << "choose gaming model" << endl;
                cout << "1. ROG" << endl;
                cout << "2. TUF" << endl;
                cin >> c;
                switch (c)
                {
                case 1:
                    system("cls");
                    a.loading();
                    system("cls");
                    R.setROG();
                    break;
                case 2:
                    system("cls");
                    a.loading();
                    system("cls");
                    T.setTUF();
                    break;
                default:
                    exit(0);
                }
                break;
            case 2:
                system("cls");
                cout << "choose student model" << endl;
                cout << "1. Vivobook" << endl;
                cout << "2. Chrome book" << endl;
                cin >> c;
                switch (c)
                {
                case 1:
                    system("cls");
                    a.loading();
                    system("cls");
                    V.setVivobook();
                    break;
                case 2:
                    system("cls");
                    a.loading();
                    system("cls");
                    C.setChromebook();
                    break;
                default:
                    exit(0);
                }
            }
            break;
        case 2:
            system("cls");
            cout << "choose desktop series" << endl;
            cout << "1. Desktop Gaming" << endl;
            cout << "2. ProArt" << endl;
            cin >> c;
            switch (c)
            {
            case 1:
                system("cls");
                a.loading();
                system("cls");
                Dg.setDesktop_Gaming();
                break;
            case 2:
                system("cls");
                a.loading();
                system("cls");
                P.setProArt();
                break;
            default:
                exit(0);
            }
            break;
        case 3:
            system("cls");
            cout << "choose Mobile model" << endl;
            cout << "1. ROG phone" << endl;
            cout << "2. Zen phone" << endl;
            cin >> c;
            switch (c)
            {
            case 1:
                system("cls");
                a.loading();
                system("cls");
                Rp.setROG_phone();
                break;
            case 2:
                system("cls");
                a.loading();
                system("cls");
                Zp.setZen();
                break;
            default:
                exit(0);
            }
        }
        break;
    case 3:
        system("cls");
        cin.ignore();
        cout << "Enter the ID: " << endl;
        getline(cin, str);
        system("cls");
        a.loading();
        system("cls");
        S.deleteproducts(str);
        break;
    case 4:
        system("cls");
        cin.ignore();
        cout << "Enter the ID: " << endl;
        getline(cin, str);
        system("cls");
        a.loading();
        system("cls");
        S.searchproducts(str);
        break;
    case 5:
        exit(0);
        break;
    default:
        exit(0);
    }
    cout << "Try again?(1)";
    cin >> c;
    if (c == 1) {
        a.loading();
        display();
    }
    else
        exit(0);
}

void cwebpage::cdisplay()
{
    system("cls");
    cout << "Welcome, " << endl;
    cout << "1. view products" << endl;
    cout << "2. search products" << endl;
    cout << "3. buy products" << endl;
    cout << "4. exit" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
        system("cls");
        a.loading();
        system("cls");
        s.getProducts();
        break;
    case 2:
        system("cls");
        a.loading();
        system("cls");
        cin.ignore();
        cout << "Enter the ID: " << endl;
        getline(cin, str);
        s.searchproducts(str);
        break;
    case 3:
        system("cls");
        a.loading();
        system("cls");
        cin.ignore();
        cout << "Enter the ID: " << endl;
        getline(cin, str);
        s.buyproducts(str);
        break;
    case 4:
        exit(0);
        break;
    default:
        exit(0);
    }
}

void Asus_Account::ForgotPassword()
{
    system("cls");
    cout << "FORGOT PASSWORD PAGE" << endl;
    cout << "Enter username: " << endl;
    cin >> username;
    ifstream read(username + ".txt");
    getline(read, username_from_file);
    getline(read, password_from_file);
    if (username_from_file == username)
    {
        cout << "Here is your password, " << username << endl;
        cout << password_from_file << endl;
    }
    else
    {
        cout << "Account does not exist";
    }
}

void RegisterAccount::register_account()
{
    system("cls");
    cout << "REGISTER PAGE" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "\nEnter password: ";
    cin >> password;
    ofstream write(username + ".txt");// "abubakr"+".txt"= abubakr.txt
    write << username << endl;
    write << password << endl;
    write.close();
    cout << "You have been successfully registered" << endl;
    main();
}

class Specs;

void LoginAccount::login_account()
{
    system("cls");
    cout << "LOGIN PAGE" << endl;
    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;
    ifstream read(username + ".txt");
    getline(read, username_from_file);
    getline(read, password_from_file);
    if (username_from_file == username && password_from_file == password)
    {

        temp = username.size() - stafflen;
        if (username.substr(temp) == staff)
        {
            a.loading();
            system("cls");
            Webpage w;
            w.display();
        }
        else
        {
            a.loading();
            system("cls");
            c.cdisplay();
        }


    }
    else
    {
        cout << "Wrong username/password, forgot password? (y/n): " << endl;
        cin >> choice;
        if (choice == 'y')
        {
        Asus_Account:ForgotPassword();
        }
        else
            login_account();
    }
}

Intro::Intro()
{
    system("cls");
    cout << "Welcome to ASUS Website, please enter in your credentials to continue browsing through the website" << endl;
    cout << "\t\t\t\t\t\t\t1. Login \n\n";
    cout << "\t\t\t\t\t\t\t2. Register \n\n";
    cout << "\t\t\t\t\t\t\t3. Exit \n\n";
    cout << "\t\t\t\t\t\t\tEnter your choice : ";
    cin >> choice;
    system("cls");
    a.loading();
    system("cls");
    switch (choice)
    {
    case 1:
        L.login_account();
        break;
    case 2:
        R.register_account();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid, would you like to try again? (y/n)" << endl;
        cin >> ch;
        if (ch == 'y')
        {
            Intro();
        }
        else
            exit(0);
        break;
    }

}

int main()
{
    try
    {
        system("cls");
        animation object;
        object.load_animation();
        system("cls");
        Intro i;
    }
    catch (error e)
    {
        system("cls");
        cout << "Invalid choice:Try Again " << endl << endl;
    }
    _getch();
    return 0;
}
