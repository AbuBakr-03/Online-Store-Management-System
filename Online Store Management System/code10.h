#include <string>

#pragma once

int color_code = 1;

void system_color(int color);

class animation
{
public:
    void greeting();
    void load_animation();
    void loading();
};

class error
{
private:
    int e;
public:
    error();
    error(int e);
    int display();

};

class Specs
{
private:
protected:
    std::string IDFile;
    std::string ProcessorFile;
    std::string MemoryFile;
    std::string StorageFile;
    int PriceFile;
    int StockFile;
public:
    void setSpecs(std::string typeFile, std::string cameraFile, std::string simFile, std::string graphicsFile, std::string colorFile, std::string weightFile, std::string sizeFile);
    void getProducts();
    void searchproducts(std::string ID);
    void deleteproducts(std::string ID);
    void buyproducts(std::string ID);

};

class Desktop : public Specs
{
protected:
    std::string weightFile;
    std::string sizeFile;
    std::string empty = "N/A";
    std::string type = "Desktop";
public:
    void setDesktop();
};

class Desktop_Gaming : public Desktop
{
private:
public:
    void setDesktop_Gaming();
};

class ProArt : public Desktop
{
private:
public:
    void setProArt();
};

class Mobile : public Specs
{
protected:
    std::string camera;
    std::string sim;
    std::string empty = "N/A";
    std::string type = "Mobile";
public:
    void setMobile();
};

class ROG_phone : public Mobile
{
private:
public:
    void setROG_phone();
};

class Zen_phone : public Mobile
{
private:
public:
    void setZen();
};

class Laptop : public Specs
{
protected:
    std::string graphics;
    std::string color;
    std::string empty = "N/A";
    std::string type = "Laptop";
public:
    void setLaptop();
};

class For_Student : public Laptop
{
protected:
public:
    void setFor_Student();
};

class Vivobook : public For_Student
{
private:
public:
    void setVivobook();
};

class Chromebook : public For_Student
{
private:
public:
    void setChromebook();
};

class For_Gaming : public Laptop
{
protected:
public:
    void setFor_Gaming();
};

class ROG : public For_Gaming
{
private:
public:
    void setROG();
};

class TUF : public For_Gaming
{
private:
public:
    void setTUF();
};

class Webpage
{
private:
    Specs S;
    Desktop_Gaming Dg;
    ProArt P;
    ROG_phone Rp;
    Zen_phone Zp;
    Vivobook V;
    Chromebook C;
    ROG R;
    TUF T;
    std::string str;
    int c;
    animation a;
public:
    void display();
};

class cwebpage
{
private:
    int c;
    Specs s;
    std::string str;
    animation a;
public:
    void cdisplay();
};

class Asus_Account
{
protected:
    std::string username;
    std::string password;
    std::string username_from_file;
    std::string password_from_file;
    char choice;
public:
    void ForgotPassword();
};

class RegisterAccount : public Asus_Account
{
private:
public:
    void register_account();
};

class Specs;

class LoginAccount : public Asus_Account
{
private:
    cwebpage c;
    std::string staff = "staff";
    int stafflen = 5;
    int temp;
    animation a;
public:
    void login_account();
};

class Intro
{
private:
    RegisterAccount R;
    LoginAccount L;
    Asus_Account FP;
    int choice;
    char ch;
    animation a;
public:
    Intro();

};

int main();

