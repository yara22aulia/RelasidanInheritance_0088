#include <iostream>
#include <vector>
#include <string>
using namespace std;

// penyertaan file header anak.h dan ibu.h
#include <iostream>
#include <vector>

int main()
{
    // deklarasi dan pemberian nilai variabel pointer untuk objek dari class ibu dan anak
    Ibu* varIbu = new Ibu("rani");
    Ibu* varIbu2 = new Ibu("sari");
    anak* varAnak1 = new anak("tono");
    anak* varAnak2 = new anak("tiara");
    anak* varAnak3 = new anak("dini");

    // pemanggilan dan pemberian argument pada prosedur tambahAnak()
    varIbu->tambahAnak(varAnak1);
    varIbu->tambahAnak(varAnak2);
    varIbu2->tambahAnak(varAnak3);

    // pemanggilan prosedur cetakAnak()
    varIbu->cetakAnak();
    varIbu2->cetakAnak();

};

void Ibu::tambahAnak(anak* pAnak) 
{
    daftar_anak.push_back(pAnak);
}

void Ibu::cetakAnak() {
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    for (auto& a : daftar_anak)
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

#endif