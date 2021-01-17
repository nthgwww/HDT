#include<iostream>
#include<cmath>
using namespace std;
class SoPhuc {
private:
	int PhanThuc;
	int PhanAo;
public:
	SoPhuc();
	SoPhuc(int t, int a);
	SoPhuc(const int& a);
	~SoPhuc();
	void Nhap();
	void Xuat();
	float getPhanThuc();
	void setPhanThuc(float thuc);
	float getPhanAo();
	void setPhanAo(float ao);
	SoPhuc Cong(SoPhuc sp1);
	SoPhuc Tru(SoPhuc sp1);
	SoPhuc Nhan(SoPhuc sp1);
	SoPhuc Chia(SoPhuc sp1);
	float TinhModule();
	float SoSanh(SoPhuc sp1);
};
SoPhuc::SoPhuc() {
	PhanThuc = 0;
	PhanAo = 0;
}
SoPhuc::SoPhuc(int t, int a) {
	PhanThuc = t;
	PhanAo = a;
}
SoPhuc::SoPhuc(const int& a) {
	PhanThuc = a;
	PhanAo = a;
}
SoPhuc::~SoPhuc() {
}
void SoPhuc::Nhap(){
	cout << "\nNhap phan thuc: ";
	cin >> PhanThuc;
	cout << "Nhap phan ao: ";
	cin >> PhanAo;
}
void SoPhuc::Xuat() {
	if (PhanAo >= 0) 
		cout<< "(" << PhanThuc << "+" << PhanAo << "i)" << endl;
	else
		cout << "(" << PhanThuc << PhanAo << "i)" << endl;
}
float SoPhuc::getPhanThuc() {
	return PhanThuc;
}
void SoPhuc::setPhanThuc(float thuc) {
	PhanThuc = thuc;
}
float SoPhuc::getPhanAo() {
	return PhanAo;
}
void SoPhuc::setPhanAo(float ao) {
	PhanAo = ao;
}
SoPhuc SoPhuc::Cong(SoPhuc sp2) {
	SoPhuc cong;
	cong.PhanThuc = PhanThuc + sp2.PhanThuc;
	cong.PhanAo = PhanAo + sp2.PhanAo;
	return cong;
}
SoPhuc SoPhuc::Tru(SoPhuc sp2) {
	SoPhuc tru;
	tru.PhanThuc = PhanThuc - sp2.PhanThuc;
	tru.PhanAo = PhanAo - sp2.PhanAo;
	return tru;
}
SoPhuc SoPhuc::Nhan(SoPhuc sp2) {
	SoPhuc nhan;
	nhan.PhanThuc = PhanThuc * sp2.PhanThuc - PhanAo * sp2.PhanAo;
	nhan.PhanAo = PhanThuc * sp2.PhanAo + PhanAo * sp2.PhanThuc;
	return nhan;
}
SoPhuc SoPhuc::Chia(SoPhuc sp2) {
	SoPhuc chia;
	chia.PhanThuc = (PhanThuc * sp2.PhanThuc + PhanAo * sp2.PhanAo) / (sp2.PhanThuc * sp2.PhanThuc + sp2.PhanAo * sp2.PhanAo);
	chia.PhanAo = (PhanAo * sp2.PhanThuc - PhanThuc * sp2.PhanAo) / (sp2.PhanThuc * sp2.PhanThuc + sp2.PhanAo * sp2.PhanAo);
	return chia;
}
float SoPhuc::TinhModule() {
	return sqrt(pow(this->getPhanThuc(), 2) + pow(this->getPhanAo(), 2));
}
float SoPhuc::SoSanh(SoPhuc sp2) {
	if (TinhModule() > sp2.TinhModule())
		return 1;
	else if (TinhModule() < sp2.TinhModule())
		return 0;
	else
		return -1;
}
int main() {
	SoPhuc sp1, sp2, tong, hieu, tich, thuong;
	cout << "Nhap so phuc 1: ";
	sp1.Nhap();
	cout << "Nhap so phuc 2: ";
	sp2.Nhap();
	cout << "Cac so phuc vua nhap: ";
	cout << "\nSo phuc 1: ";
	sp1.Xuat();
	cout << "So phuc 2: ";
	sp2.Xuat();
	tong = sp1.Cong(sp2);
	cout << "Tong hai so phuc vua nhap: ";
	tong.Xuat();
	hieu = sp1.Tru(sp2);
	cout << "Hieu hai so phuc vua nhap: ";
	hieu.Xuat();
	tich = sp1.Nhan(sp2);
	cout << "Tich hai so phuc vua nhap: ";
	tich.Xuat();
	thuong = sp1.Chia(sp2);
	cout << "Thuong hai so phuc vua nhap: ";
	thuong.Xuat();
	cout << "Module cac so phuc vua nhap: " << endl;
	cout << "Module so phuc 1: " << sp1.TinhModule();
	cout << "\nModule so phuc 2: " << sp2.TinhModule();
	cout << "\nSo sanh hai so phuc vua nhap: ";
	if (sp1.SoSanh(sp2) == 1)
		cout << "So phuc 1 lon hon so phuc 2" << endl;
	else if (sp1.SoSanh(sp2) == 0)
		cout << "So phuc 1 nho hon so phuc 2" << endl;
	else
		cout << "Hai so phuc bang nhau" << endl;

	system("pause");
	return 0;
}