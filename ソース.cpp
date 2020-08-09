#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<regex>
#include<time.h>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
using namespace std;

//クラスの設定
struct Person {
private:
	string name;
	string gender;
	string birthday;
	string day1;
	int age;
	string tel;

public:
	void setName(const string& newName) { name = newName; }
	string getName() { return name; }
	void setGender(const string& newGender) { gender = newGender; }
	string getGender() { return gender; }
	void setBirthday(const string& newBirthday) { birthday = newBirthday; }
	string getBirthday() { return birthday; }
	void setDay1(const string& newDay1) { day1 = newDay1; }
	string getDay1() { return day1; }
	void setAge(const int& newAge) { age = newAge; }
	int getAge() { return age; }
	void setTel(const string& newTel) { tel = newTel; }
	string getTel() { return tel; }

};

//曜日を求める関数の設定
int requestDay(int year, int month, int day) {
	int E1 = 0;
	//以下年の設定
	if ((1900 <= year) && (year <= 2050)) {
	}
	else {
		E1 = -1;
	}

	//以下月の設定
	if ((1 <= month) && (month <= 12)) {
		
	}
	else {
		E1 = -1;
	}

	//以下日にちの設定
	if ((month == 1) | (month == 3) | (month == 5) | (month == 7) | (month == 8) | (month == 10) | (month == 12)) {
		if ((1 <= day) && (day <= 31)) {

		}
		else {
			E1 = -1;
		}
	}

	else if (month == 2) {
		if ((1 <= day) && (day <= 29)) {

		}
		else {
			E1 = -1;
		}
	}
	else {
		if ((1 <= day) && (day <= 30)) {

		}
		else {
			E1 = -1;
		}
	}

	int M2;
	int Y3;
	if ((month == 1) | (month == 2)) {
		M2 = month + 12;
		Y3 = year - 1;
	}
	else {
		M2 = month;
		Y3 = year;
	}

	//ツェラー公式
	int K = (day + ((26 * (M2 + 1)) / 10) + (Y3 % 100) + ((Y3 % 100) / 4) - (2 * (Y3 / 100)) + (Y3 / 400));

	int K2;
	if ((K % 7) < 0) {
		K2 = (K % 7) + 7;
	}

	else {
		K2 = K % 7;
	}

	if (E1 == -1) {
		return E1;
	}
	else {
		return K2;
	}
}

//並べ替える関数の設定
void sortvec(vector<int>v1, vector<Person>v2, int a) {
	ofstream outfile("profile2.csv", ios_base::out);
	//イテレータ
	sort(v1.begin(), v1.end());
	outfile << "名前" << ", " << "年齢" << ", " << "生年月日" << ", " << "生年月日の曜日" << ", " << "性別" << ", " << "電話番号" << endl;
	for (int s = 0; s < a; ++s) {
		for (int t = 0; t < a; ++t) {
			if (v1[s] == v2[t].getAge()) {
				cout << v2[t].getName() << "(" << v2[t].getAge() << ")　" << v2[t].getBirthday() << "　" << v2[t].getDay1() << "　" << v2[t].getGender() << "　" << v2[t].getTel() << endl;
				outfile << v2[t].getName() << ", " << v2[t].getAge() << ", " << v2[t].getBirthday() << ", " << v2[t].getDay1() << ", " << v2[t].getGender() << ", " << v2[t].getTel() << endl;
			}
			else {
				//処理をしない。
			}
		}
	}
	outfile.close();
}

void sortvecgreater(vector<int>v3, vector<Person>v4, int b) {
	ofstream outfile2("profile2.csv", ios_base::out);
	sort(v3.begin(), v3.end(), greater<>());
	outfile2 << "名前" << ", " << "年齢" << ", " << "生年月日" << ", " << "生年月日の曜日" << ", " << "性別" << ", " << "電話番号" << endl;
	for (int u = 0; u < b; ++u) {
		for (int w = 0; w < b; ++w) {
			if (v3[u] == v4[w].getAge()) {
				cout << v4[w].getName() << "(" << v4[w].getAge() << ")　" << v4[w].getBirthday() << "　" << v4[w].getDay1() << "　" << v4[w].getGender() << "　" << v4[w].getTel() << endl;
				outfile2 << v4[w].getName() << ", " << v4[w].getAge() << ", " << v4[w].getBirthday() << ", " << v4[w].getDay1() << ", " << v4[w].getGender() << ", " << v4[w].getTel() << endl;
			}
			else {
				//処理をしない。
			}
		}
	}
	outfile2.close();
}

int main() {
	//コンテナの設定
	vector<string> vName;
	vector<string> vGender;
	vector<string> vBirthday;
	vector<string> vTel;

	//ファイルの読み込み
	ifstream datafile("profile.txt");
	string a, b, c, d;
	int i = 0;
	while (datafile >> a >> b >> c >> d) {
		vName.push_back(a);
		vGender.push_back(b);
		vBirthday.push_back(c);
		vTel.push_back(d);
		++i;
	}

	//コンテナの設定２
	vector<vector<string>>vBirthday2(i, vector<string>(3));

	//データの解析
	int l = 0;
	regex rx1(R"(/)");
	for (int k = 0; k < i; ++k) {
		l = 0;
		//イテレータの使用
		sregex_token_iterator it(vBirthday[k].begin(), vBirthday[k].end(), rx1, -1);
		sregex_token_iterator end;
		while (it != end) {
			vBirthday2[k][l] = *it++;
			++l;
		}
	}

	//コンテナの設定３
	vector<vector<int>>vBirthday3(i, vector<int>(3));
	vector<string>vday2;

	//文字列を整数に変換・誕生日の曜日を設定
	for (int m = 0; m < i; ++m) {
		for (int n = 0; n < 3; ++n) {
			int o = stoi(vBirthday2[m][n]);
			vBirthday3[m][n] = o;
		}
		int p = requestDay(vBirthday3[m][0], vBirthday3[m][1], vBirthday3[m][2]);
		vday2.emplace_back();

		switch (p) {
		case 0:
			vday2[m] = "土";
			break;
		case 1:
			vday2[m] = "日";
			break;
		case 2:
			vday2[m] = "月";
			break;
		case 3:
			vday2[m] = "火";
			break;
		case 4:
			vday2[m] = "水";
			break;
		case 5:
			vday2[m] = "木";
			break;
		case 6:
			vday2[m] = "金";
			break;
		default:
			cout << "データに誤りがあります。プログラムを終了します。\n";
			exit(0);
			break;
		}
	}

	//現在時刻の取得
	time_t now;

	struct tm localNow;
	time(&now);
	localtime_s(&localNow, &now);

	int NY = localNow.tm_year + 1900;
	int NM = localNow.tm_mon + 1;
	int ND = localNow.tm_mday;

	//年齢の取得・コンテナの設定４
	vector<int>vage;
	for (int q = 0; q < i; ++q) {
		vage.emplace_back();
		vage[q] = (((10000 * NY) + (100 * NM) + (ND)) - ((10000 * vBirthday3[q][0]) + (100 * vBirthday3[q][1]) + (vBirthday3[q][2]))) / 10000;
	}

	//クラスに設定
	vector<Person>vec;
	for (int r = 0; r < i; ++r) {
		vec.emplace_back();
		vec[r].setName(vName[r]);
		vec[r].setGender(vGender[r]);
		vec[r].setBirthday(vBirthday[r]);
		vec[r].setDay1(vday2[r]);
		vec[r].setAge(vage[r]);
		vec[r].setTel(vTel[r]);
	}

	//並べ替えと選択と出力
	cout << "若い順に並べ替えますか？そうならばyキーそうでないならばnキーを押してEnterを押してください。\n";
	string str1;
	cin >> str1;
	if (str1 == "y") {
		//若い順に並べ替え
		sortvec(vage, vec, i);
	}
	else if (str1 == "n") {
		cout << "高齢の順に並べ替えますか？そうならばyキーそうでないならばnキーを押してEnterを押してください。\n";
		string str2;
		cin >> str2;
		if (str2 == "y") {
			//高齢順に並べ替え
			sortvecgreater(vage, vec, i);
		}
		else if (str2 == "n") {
			cout << "そのまま出力します。\n";
			ofstream outfile3("profile2.csv", ios_base::out);
			outfile3 << "名前" << ", " << "年齢" << ", " << "生年月日" << ", " << "生年月日の曜日" << ", " << "性別" << ", " << "電話番号" << endl;
			for (int s = 0; s < i; ++s) {
				cout << vec[s].getName() << "(" << vec[s].getAge() << ")　" << vec[s].getBirthday() << "　" << vec[s].getDay1() << "　" << vec[s].getGender() << "　" << vec[s].getTel() << endl;
				outfile3 << vec[s].getName() << ", " << vec[s].getAge() << ", " << vec[s].getBirthday() << ", " << vec[s].getDay1() << ", " << vec[s].getGender() << ", " << vec[s].getTel() << endl;
			}
			outfile3.close();
		}
		else {
			cout << "不正な入力です。プログラムを終了します。\n";
			exit(0);
		}
	}
	else {
		cout << "不正な入力です。プログラムを終了します。\n";
		exit(0);
	}
}