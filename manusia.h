#ifndef MANUSIA_H
#define MANUSIA_H

//member class manusia di file header manusia.h 
class Manusia 
{
public:
     //membuat member variabel class manusia
    string name;
    jantung varJantung;
    Manusia(string pName) : name(pName) {
        cout << name << " Hidup\n";
    }
    ~Manusia() {
        cout << name << " Mati\n";
    }
};
#endl //!MANUSIA_H