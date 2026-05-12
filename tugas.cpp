#include <iostream>
#include <vector>
using namespace std;

// ===== CLASS USER =====
class User
{
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    // Constructor
    User(string nama, string email)
    {
        this->nama = nama;
        this->email = email;
        id = generateId();
    }

    // Generate ID otomatis
    int generateId()
    {
        return ++globalId;
    }

    // Getter
    int getId()
    {
        return id;
    }

    string getNama()
    {
        return nama;
    }

    string getEmail()
    {
        return email;
    }
};

// Inisialisasi static variable
int User::globalId = 0;

// ===== CLASS MEMBER =====
class Member : public User
{
private:
    bool status;

public:
    // Constructor
    Member(string nama, string email)
        : User(nama, email)
    {
        status = true;
    }

    // Menampilkan profil
    void showProfile()
    {
        cout << "===== PROFILE MEMBER =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : "
             << (status ? "Aktif" : "Nonaktif")
             << endl;
    }

    // Getter status
    bool getStatus()
    {
        return status;
    }

    // Mengubah status
    void setStatus(bool s)
    {
        status = s;
    }
};

// ===== CLASS ADMIN =====
class Admin : public User
{
public:
    // Constructor
    Admin(string nama, string email)
        : User(nama, email) {}

    // Menampilkan semua member
    void showAllMember(vector<Member> &members)
    {
        cout << "\n===== DATA MEMBER =====" << endl;

        for (int i = 0; i < members.size(); i++)
        {
            cout << "ID     : " << members[i].getId() << endl;
            cout << "Nama   : " << members[i].getNama() << endl;
            cout << "Email  : " << members[i].getEmail() << endl;
            cout << "Status : "
                 << (members[i].getStatus() ? "Aktif" : "Nonaktif")
                 << endl;
            cout << "---------------------" << endl;
        }
    }

    // Mengaktifkan / menonaktifkan member
    void toggleActivationMember(Member &m)
    {
        m.setStatus(!m.getStatus());

        cout << "Status member berhasil diubah!" << endl;
    }
};

// ===== MAIN =====
int main()
{

    // Membuat object member
    Member m1("Budi", "budi@gmail.com");
    Member m2("Siti", "siti@gmail.com");

    // Membuat object admin
    Admin admin("Admin", "admin@gmail.com");

    // Menampilkan semua member
    vector<Member> daftarMember;
    daftarMember.push_back(m1);
    daftarMember.push_back(m2);

    admin.showAllMember(daftarMember);

    // Menampilkan profile member
    cout << endl;
    m1.showProfile();

    // Toggle status member
    cout << "\nMengubah status member...\n";
    admin.toggleActivationMember(m1);

    // Tampilkan lagi profile member
    cout << endl;
    m1.showProfile();

    return 0;
}