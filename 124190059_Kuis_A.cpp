#include <iostream>
#include <malloc.h>
#define true 1
#define false 0
using namespace std;

typedef string typeinfo;
typedef struct typenode *typeptr;
struct datadonor{
	typeinfo nama,status;
	int umur;
	char goldar;
};
struct typenode{
	datadonor data;
	typeptr next; 
};

typenode abc;
typeptr awal,akhir;
void buatlistbaru();
void sisipnode(datadonor dd);
int listkosong();
/*void hapusnode(typeinfo namah);
void bacamaju();
void bacamundur();
	*/

int main(){
	char jwb;
	int pilih,jml;
	buatlistbaru();
	
	do{
		system("cls");
		cout<<"Unit Pelayanan Transfusi Darah";
		cout<<"\n\nMENU :";
		cout<<"\n1. Input Data Donor \n2. Lihat Data Pendonor \n3. Cek Kandidat Pendonor \n4. Hapus Data Pendonor \n5. Keluar";
		cout<<"\nPilih : "; cin>>pilih;
		
		switch (pilih){
			case 1:
				system("cls");
				cout<<"Input Data Pendonor\n";
				cout<<"Jumlah Data : "; cin>>jml;
				
				for (int i = 0; i < jml; i++){
					cout<<"Data ke-"<<i+1;
					cout<<"\nNama Pendonor\t: "; cin.ignore(); getline(cin,abc.data.nama); 
					cout<<"Umur\t\t: "; cin>>abc.data.umur;
					cout<<"Golongan Darah\t: "; cin>>abc.data.goldar;
					if (abc.data.umur > 16 && abc.data.umur < 61){
						abc.data.status="Bisa Donor";
					}
					else{
						abc.data.status="Tidak Bisa Donor";
					}
					cout<<"Status\t\t: "<<abc.data.status;
					cout<<endl<<endl;
					sisipnode(abc.data);
				}
				break;
			case 2: 
				system("cls");
				cout<<"Data Pendonor :\n";
				
		}
		
		cout<<"Kembali ke Menu? (y/t)"; cin>>jwb;
	} while (jwb == 'y' || jwb == 'Y');
	
}

void buatlistbaru(){
	typeptr list;
	list=NULL;
	awal=list;
	akhir=list;
};

void sisipnode(datadonor dd){
	typeptr NB;
	
	NB=(typenode *) malloc(sizeof(typenode));
	NB->data=dd;
	NB->next=NULL;
	if (listkosong()){ 
		awal=NB;
		akhir=NB; 
	}
	else {  // Sisip di depan
		NB->next=awal;
		awal=NB; 
	}
};

int listkosong(){ 
	if(awal==NULL)
		return(true);
	else
		return(false); 
};

