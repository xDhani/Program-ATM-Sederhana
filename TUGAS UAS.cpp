#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

void sret(){
	cout<<"========================================="<<endl;
}
void atm(){
	system("cls");
	sret();
	cout<<"                   ATM                   "<<endl;
	sret();
}
void menu(){
	cout<<"1. Daftar Nasabah                        "<<endl<<endl;
	cout<<"2. Cek Data Nasabah                      "<<endl<<endl;
	cout<<"3. Cek Saldo Nasabah                     "<<endl<<endl;
	cout<<"4. Setor Tunai Nasabah                   "<<endl<<endl;
	cout<<"5. Tarik Tunai Nasabah                   "<<endl<<endl;
}

int main(){
	string nama[100];int data[100000][3]; int x = 0; int t = 0;
	int pilihopening, z; 
	string ulang;
	int pin,cdata, setor;  int tarik; int tariktunai;
	do{
		awal:
		atm(); cout<<endl;
		menu();
		sret();
		cout<<"Masukan Pilihan : ";cin>>pilihopening;
	
		switch(pilihopening){
			case 1:
				atm();
				cout<<"              Daftar Nasabah             "<<endl;
				cout<<endl;
				cout<<"Masukan Nama Panggilan Anda              "<<endl;
				cin>>nama[x];
				cout<<"Masukan Umur Anda                        "<<endl;
				cin>>data[x][0];
				if(data[x][0] < 18){
					cout<<"Maaf Anda Belum Cukup Umur               "<<endl;
					sleep(2);
					goto awal;
				}else{
					cout<<"Masukan Nomor Pin Anda                   "<<endl;
					cin>>data[x][1];
					cout<<endl;
					sret();
					atm();
					cout<<"Nama Anda : "<<nama[x]<<endl;
					cout<<"Umur Anda : "<<data[x][0]<<endl;
					cout<<"Nomor Pin : "<<data[x][1]<<endl;
		  			cout<<endl;
					cout<<"Rekening Anda Telah Di Buat              "<<endl;
					x+=1;
					sleep(2);
					goto awal;
				}
				break;
			case 2:
				atm();
				cout<<"            Cek Data Nasabah             "<<endl;
				cout<<endl;
				cout<<"Masukan Nomor Pin Anda                   "<<endl;
				cin>>cdata;
				for(int k = 0; k < 100000; k++){
					for(int l = 0; l < 3; l++){
						if(cdata == data[k][l]){
							cout<<"========================================="<<endl;
							cout<<"Nama Rekening Anda    : "<<nama[k]<<endl;
							cout<<"Umur Anda             : "<<data[k][0]<<endl;
							cout<<"Nomor Pin Anda        : "<<data[k][1]<<endl;
							cout<<"========================================="<<endl;
							z+=1;
							break;
						}	
					}
				}
				if(z==0){
					cout<<endl;
					cout<<"Nomor Pin Anda Belum Terdaftar           "<<endl;
					break;
					sleep(2);
					goto awal;
				}
				break;
			case 3:
				atm();
				cout<<"            Cek Saldo Nasabah            "<<endl;
				cout<<endl;
				cout<<"Masukan Nomor Pin Anda                   "<<endl;
				cin>>pin; cout<<endl;
				cout<<"========================================="<<endl;
				for(int m = 0; m < 100000; m++){
					for(int n = 0; n < 3; n++){
						if(pin == data[m][n]){
							z++;
							cout<<"Saldo Anda Rp. "<<data[m][2]<<endl;
							sleep(2);
							goto awal;
							break;
						}	
					}
				}
				if (z == 0){
					cout<<endl;
					cout<<"Nomor Pin Anda Belum Terdaftar           "<<endl;
					sleep(2);
					goto awal;
				}
				break;
			case 4:
				atm();
				cout<<"           Setor Tunai            "<<endl;
				cout<<endl;
				cout<<"Masukan Pin Anda : ";
				cin>>setor;
				for(int i = 0; i < 100000; i++){
					for(int j = 0;j <3; j++){
						if(setor == data[i][j]){
							z++;
							cout<<"Masukan Saldo Anda : "; cin>>data[i][2];
							cout<<"Saldo Sudah Di Masukan"<<endl;
							sleep(2);
							goto awal;
							break;
						}
					}
				}
				if (z == 0){
					cout<<endl;
					cout<<"Nomor Pin Anda Belum Terdaftar           "<<endl;
					sleep(2);
					goto awal;
				}
				break;
			case 5:
				system("cls");
				atm();
				cout<<"Masukan Pin Anda : "; cin>>tarik;
				for(int i = 0; i < 100000; i++){
					for(int j = 0; j < 3;j++){
						if(tarik == data[i][j]){
							cout<<"Mau Tarik Berapa : "; cin>>tariktunai;
							if(tariktunai >= data[i][2]){
								z++;
								cout<<"Saldo Anda Tidak Cukup"<<endl;
								sleep(2);
								goto awal;
							}else{
								data[i][2] -= tariktunai;
								cout<<"Anda Sudah Melakukan Tarik Tunai"<<endl;
								sleep(2);
								goto awal;
								break;
							}
						}
					}
				}
					if (z == 0){
					cout<<endl;
					cout<<"Nomor Pin Anda Belum Terdaftar           "<<endl;
					sleep(2);
					goto awal;
				}
				break;
		}
		cout<<"========================================="<<endl;
		cout<<"Kembali Ke Menu? (y/n)                   "<<endl;
		cout<<"========================================="<<endl;
		cin>>ulang;
	}while(ulang == "y");
}
