#include <iostream>
#include <vector>
using namespace std;

// Class induk
class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    // Constructor
    User(string pNama, string pEmail) {
        id = generateId();
        nama = pNama;
        email = pEmail;
    }

    // Function generate ID
    int generateId() {
        return ++globalId;
    }

    // Getter
    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};

// Inisialisasi static variable
int User::globalId = 0;

// Class turunan Member
class Member : public User {
private:
    bool status;

public:
    // Constructor
    Member(string pNama, string pEmail, bool pStatus)
        : User(pNama, pEmail) {
        status = pStatus;
    }

    // Function menampilkan profile
    void showProfile() {
        cout << "===== PROFILE MEMBER =====" << endl;
        cout << "ID      : " << id << endl;
        cout << "Nama    : " << nama << endl;
        cout << "Email   : " << email << endl;
        cout << "Status  : " << (status ? "Aktif" : "Nonaktif") << endl;
        cout << endl;
    }

    // Getter status
    bool getStatus() {
        return status;
    }

    // Setter status
    void setStatus(bool pStatus) {
        status = pStatus;
    }
};

// Class turunan Admin
class Admin : public User {
public:
    // Constructor
    Admin(string pNama, string pEmail)
        : User(pNama, pEmail) {}

    // Function menampilkan semua member
    void showAllMember(vector<Member*> daftarMember) {
        cout << "===== DAFTAR MEMBER =====" << endl;

        for (auto member : daftarMember) {
            cout << "ID      : " << member->getId() << endl;
            cout << "Nama    : " << member->getNama() << endl;
            cout << "Email   : " << member->getEmail() << endl;
            cout << "Status  : "
                 << (member->getStatus() ? "Aktif" : "Nonaktif")
                 << endl;
            cout << "-------------------------" << endl;
        }
    }

    // Function mengubah status member
    void toggleActivationMember(Member* member) {
        member->setStatus(!member->getStatus());
    }
};

int main() {

    // Membuat object member
    Member* member1 = new Member("Andi", "andi@gmail.com", true);
    Member* member2 = new Member("Budi", "budi@gmail.com", false);

    // Membuat object admin
    Admin* admin1 = new Admin("Admin", "admin@gmail.com");

    // Menyimpan member ke vector
    vector<Member*> daftarMember;
    daftarMember.push_back(member1);
    daftarMember.push_back(member2);

    // Menampilkan semua member
    admin1->showAllMember(daftarMember);

    // Mengubah status member2
    admin1->toggleActivationMember(member2);

    cout << "\nSetelah status diubah:\n" << endl;

    // Menampilkan ulang data member
    admin1->showAllMember(daftarMember);

    // Menampilkan profile member
    member1->showProfile();

    // Hapus object
    delete member1;
    delete member2;
    delete admin1;

    return 0;
}