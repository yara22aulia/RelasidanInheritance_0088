#ifndef JANTUNG_H
#define JANTUNG_H

//membuat class jantung di file header jantung.h
class jantung 
{
public:
    //membuat constructor dan destructor class jantung
    jantung() {
        cout << "jantung dibuat\n";
    }

    ~jantung() {
        cout << "jantung dihapus\n";
    }
};

#endif