#include<iostream>
#include<cmath>
using namespace std;
class PhanSo {
private:
	int TuSo;
	int MauSo;
public:
	PhanSo();
	PhanSo(int t, int m);
	PhanSo(const int& a);
	~PhanSo();
	void Nhap();
	void Xuat();
	void Set(int a, int b);
	int GetTu();
	int GetMau();
	void NghichDao();
	PhanSo RutGon();
	PhanSo PhepCong(PhanSo ps1);
	PhanSo PhepTru(PhanSo ps1);
	PhanSo PhepNhan(PhanSo ps1);
	PhanSo PhepChia(PhanSo ps1);
	int SoSanh(PhanSo ps1);
};
PhanSo::PhanSo() {
	TuSo = 0;
	MauSo = 1;
}
PhanSo::PhanSo(int t, int m) {
	TuSo = t;
	MauSo = m;
}
PhanSo::PhanSo(const int& a) {
	TuSo = a;
	MauSo = a;
}
PhanSo::~PhanSo() {
}
void PhanSo::Nhap() {
	cout << "\nNhap tu so:";
	cin >> TuSo;
	do {
		cout << "Nhap mau so:"<<endl;
		cin >> MauSo;
		if (MauSo == 0) {
			cout << "Xin nhap lai!";
		}
	} while (MauSo == 0);
}
void PhanSo::Xuat() {

	if (TuSo == 0)
		cout << TuSo;
	else if (MauSo == 1)
		cout << TuSo;
	else
		cout << TuSo << "/" << MauSo << endl;
}
void PhanSo::Set(int a, int b) {
	TuSo = a;
	MauSo = b;
}
int PhanSo::GetTu() {
	return this->TuSo;
}
int PhanSo::GetMau() {
	return this->MauSo;
}
void PhanSo::NghichDao() {
	int temp;
	temp = TuSo;
	TuSo = MauSo;
	MauSo = temp;
}
int UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (a!=b){
		if (a > b)
			a = a - b;
		else
			b = b - a;
		}
	return a;
}
PhanSo PhanSo::RutGon() {
	int uc = UCLN(TuSo, MauSo);
	TuSo = TuSo / uc;
	MauSo = MauSo / uc;
	return uc;
}
PhanSo PhanSo::PhepCong(PhanSo ps2) {
	return PhanSo(this->TuSo * ps2.MauSo + ps2.TuSo * this->MauSo, this->MauSo * ps2.MauSo);
}
PhanSo PhanSo::PhepTru(PhanSo ps2) {
	return PhanSo(this->TuSo * ps2.MauSo - ps2.TuSo * this->MauSo, this->MauSo * ps2.MauSo);
}
PhanSo PhanSo::PhepNhan(PhanSo ps2) {
	return PhanSo(this->TuSo * ps2.TuSo, this->MauSo * ps2.MauSo);
}
PhanSo PhanSo::PhepChia(PhanSo ps2) {
	return PhanSo(this->TuSo * ps2.MauSo, this->MauSo * ps2.TuSo);
}
int PhanSo::SoSanh(PhanSo ps2) {
	if ((this->TuSo / this->MauSo) > (ps2.TuSo / ps2.MauSo))
		return 1;
	else if ((this->TuSo / this->MauSo) < (ps2.TuSo / ps2.MauSo))
		return 0;
	else
		return -1;
}
int main() {
	PhanSo ps1, ps2, cong, tru, nhan, chia;
	cout << "\nNhap phan so 1:";
	ps1.Nhap();
	cout << "\nNha	p phan so 2:";
	ps2.Nhap();
	cout << "ps1=";
	ps1.Xuat();
	cout << "ps2=";
	ps2.Xuat();
	cong = ps1.PhepCong(ps2);
	cout << "\nCong =";
	cong.RutGon();
	cong.Xuat();
	tru = ps1.PhepTru(ps2);
	cout << "\nTru=";
	tru.RutGon();
	tru.Xuat();
	nhan = ps1.PhepNhan(ps2);
	cout << "\nNhan=";
	nhan.RutGon();
	nhan.Xuat();
	chia = ps1.PhepChia(ps2);
	cout << "\nChia=";
	chia.RutGon();
	chia.Xuat();
	cout << "\nSo sanh 2 phan so:";
	if (ps1.SoSanh(ps2) == 1)
		cout << "\nphanso1 nho hon phanso2";
	else if (ps1.SoSanh(ps2) == 0)
		cout << "\nphan so 1 lon hon phan so 2";
	else
		cout << "\nHai phan so bang nhau";
	cout << "\nNghich dao phan so 1:";
	ps1.NghichDao();
	ps1.Xuat();
	cout << "\nNghich dao phan so 2:";
	ps2.NghichDao();
	ps2.Xuat();
	return 0;
}
