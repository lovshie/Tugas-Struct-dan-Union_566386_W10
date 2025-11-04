#include <iostream>
using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

studentType mahasiswa[20];
void readData(studentType mahasiswa[20]);
void nilaiMahasiswa(studentType mahasiswa[20]);
void cariNilaiTertinggi(studentType mahasiswa[20]);
void listMahasiswa(studentType mahasiswa[20]);

int main() {
    readData(mahasiswa);
    nilaiMahasiswa(mahasiswa);
    listMahasiswa(mahasiswa);
    cariNilaiTertinggi(mahasiswa);

    return 0;
}

void readData(studentType mahasiswa[20]){
    int size = 20;
    for(int i = 0; i<20; i++){
        cout << "Data mahasiswa ke-" << i+1 << endl;
        cout << "Masukkan nama depan mahasiswa : ";
        cin >> mahasiswa[i].studentFName;
        cout << "Masukkan nama belakang mahasiswa : ";
        cin >> mahasiswa[i].studentLName;
        if(mahasiswa[i].testScore >= 0 && mahasiswa[i].testScore <= 100){
            cout << "Masukkan nilai mahasiswa :";
            cin >> mahasiswa[i].testScore;
        }
        else{
            cout << "Nilai tidak valid.";
            break;
        }
    }
}

void nilaiMahasiswa(studentType mahasiswa[20]){
    for(int i=1; i <=20; i++){
        if(mahasiswa[i-1].testScore>=80){
            mahasiswa[i-1].grade = 'A';
        }
        else if(mahasiswa[i-1].testScore>=60){
            mahasiswa[i-1].grade = 'B';
        }
        else{
            mahasiswa[i-1].grade = 'C';
        }
    }
}

void cariNilaiTertinggi(studentType mahasiswa[20]){
    int nilaiTertinggi = 0;
    for(int i=0; i<20; i++){
        if(mahasiswa[i].testScore > nilaiTertinggi){
            nilaiTertinggi = mahasiswa[i].testScore;
        }
    }
    for(int i=0; i<20; i++){
        if(mahasiswa[i].testScore == nilaiTertinggi){
            cout << endl << "Mahasiswa dengan nilai tertinggi adalah ";
            cout << mahasiswa[i].studentLName << ", " << mahasiswa[i].studentFName;
            cout << " dengan nilai " << mahasiswa[i].testScore;
        }
    }
}

void listMahasiswa(studentType mahasiswa[20]){
    cout << endl << "Data Mahasiswa Teknologi Informasi UGM : " << endl;
    for(int i=0; i<20; i++){
        cout << i+1 << ". ";
        cout << mahasiswa[i].studentLName << ", " << mahasiswa[i].studentFName << " dengan nilai ";
        cout << mahasiswa[i].testScore << " grade " << mahasiswa[i].grade << endl;
    }
}
