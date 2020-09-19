/* Bunga Azizha Nurhaliza - 140810180016 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string enkrip(string plain, int key);
string dekrip(string cipher, int key);

int main(){
	string plain, keyword;
	int key,pil;
	cout<<" *-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n";
	cout<<"  TUGAS PRAKTIKUM KRIPTOGRAFI     \n";
	cout<<" *-*-*-*-*-*-*-*-*-*-*-*-*-*-* \n";
	cout<<"\n 1. Shift Chiper \n";
	cout<<" 2. Keluar ae dah gajadi \n";
	cout<<" \nPilih : ";
	cin>>pil;
    	switch (pil){
        case 1: {       
            cout<<"\tShift Chiper \n";
            cout<<"Tuliskan pesan: ";
            cin.ignore();
            getline(cin, plain);
            cout << "Enter key: ";
            cin >> key;
            int n;
            cout<<"\n\tMau Apa Gan ? \n";
            cout<<" 1. Enkripsi \n";
            cout<<" 2. Dekripsi \n";	
            cout<<" Pilih : ";
            cin>>n;
            if(n==1){
                cout<<"Hasil Enkripsi: "<<enkrip(plain, key)<<endl;
            }
            else if(n==2){
                cout<<"Hasil Dekripsi: "<<dekrip(plain, key)<<endl;
            }
        }break;
		case 2: {
			cout<<"Oke Terimakasih Bye!";
		}
	}

}

string enkrip(string plain, int key){
    string cipher = plain;

    for(int i = 0; i < plain.length(); i++){
        if(isupper(cipher[i]))
            cipher[i] = (((cipher[i] - 'A') + key + 26) % 26) + 'A';
        else if(islower(cipher[i]))
            cipher[i] = (((cipher[i] - 'a') + key + 26) % 26) + 'a';
        else if(isdigit(cipher[i]))
            cipher[i] = (((cipher[i] - '0') + key + 10) % 10) + '0';
    }
    return cipher;
}

string dekrip(string cipher, int key){
    string plain = cipher;

    for(int i = 0; i < cipher.length(); i++){
        if(isupper(cipher[i]))
            plain[i] = (((plain[i] - 'A' - key + (26 * (key/26))) % 26)) + 'A';
        else if(islower(cipher[i]))
            plain[i] = (((plain[i] - 'a' - key + (26 * (key/26))) % 26)) + 'a';
        else if(isdigit(cipher[i]))
            plain[i] = (((plain[i] - '0' - key + (10 * (key/10))) % 10)) + '0';
    }
    return plain;
}
