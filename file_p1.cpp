// file_p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
//in function 1 vector va 1 keyword gerefte va neshan midahad ke in word dar vector vojood darad ya na
bool exist(string key, vector <string> keys)
{
	bool exst = 0;
	for (int i = 0; i < keys.size(); i+=2)    //bayad index zouj faqat barresi shavand
	{
		if (key == keys[i]) exst = 1;
	}
	return exst;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void makefile(string name) //in tabe da qesmat use estefade mishavad
{
	ifstream file(name);
	if (!file.is_open())
	{
		ofstream f(name);

	}

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Fexist(string word, vector <string> files) //vector ra chek mikond k nam file tekrari nbashad
{
	bool exst = 0;
	for (int i = 0; i < files.size(); i++)
	{
		if (word == files[i]) exst = 1;
	}
	return exst;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// in function 1 vector va 1 keyword grfte  va index keyword ra pas midehad.  agr key word far vec nbood -1 ra midahad.

int get_index(string key, vector <string> keys)
{
	int index = -1;
	for (int i = 0; i < keys.size(); i+=2) //bayad index zouj faqat barresi shavand
	{
		if (key == keys[i]) index =i;
	}
	return index;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//in function 1 keyword va vector grfte va data ra midehad

string get_data(string key, vector <string> keys)
{
	int index = get_index(key, keys);
	if (index == -1) return "was not found.";
	return keys[index + 1]; //data ye har keyword khaneye baAdi vector ast.
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//in function 1 keyword va vector va data migirad   va data &  keyword ra be vector ezafe mikond.

void set_data(string key, string data, vector <string> & keys)
{
	bool exst = exist(key, keys);
	if (exst == 1) //update data
	{
		int index_of_key = get_index(key, keys);
		keys[index_of_key + 1] = data;
	}
	if (exst == 0) //add data and keyword
	{
		keys.push_back(key);
		keys.push_back(data);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void hazf(string key, vector <string>& keys)
{
	int i = get_index(key, keys);
	keys[i] = "";
	keys[i + 1] = "";

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	bool use = 0;//ebteda bayad file entekhab shavad
	cout <<endl<<endl<< "> ";
	string esmfile;//esm file k bahash kar mikonim
	string word;//kalamati ke karbar vared mikond
	string klid;//estefade dar SET
	string dade;//estefade dar SET
	string kedat;//estefade dar USE baraye copy
	vector <string> files;//zakhire esm file ha
	vector <string> keydata;//in vector mohtaviat 1 file ra dar khod darad.
	while (cin >> word)
	{
		if (word == "EXIT") exit(0);
		if (word == "SET") {
			if (use == 0) cout << endl <<" ebteda bayad az dastoor \" USE \" estefade shavad.^_^" << endl << "> ";
			cin >> word; //khandan (
			cin >> word; //khandan klid
			klid = word;
			cin >> word; //khandan )
			cin >> word; //khandan (
			cin >> word; //khandan dade
			dade = word;
			cin >> word; //khandan )
			set_data(klid, dade, keydata); //estefade az tabe set data
			ofstream ofs;
			ofs.open(esmfile);
			for (int i = 0; i<keydata.size(); i++) {//neveshtan tak tak klid ha va dade ha az vector va copy dar file
				ofs << keydata[i] << endl;
			}
			cout << endl << esmfile << "> ";


		}
		if (word == "GET") {
			if (use == 0) cout << endl << " ebteda bayad az dastoor \" USE \" estefade shavad.^_^" << endl << "> ";
			cin >> word; //khandan (
			cin >> word;
			cout << endl << get_data(word, keydata)<<endl<< esmfile << "> ";//estefade az tabe get_data baraye return data
			cin >> word; //khandan )
		}

		if (word == "EXIST") {
			if (use == 0) cout << endl << " ebteda bayad az dastoor \" USE \" estefade shavad.^_^" << endl<<"> ";
			cin >> word; //khandan (
			cin >> word;
			cout <<endl<< exist(word, keydata) << endl << esmfile << "> ";//estefade az tabe exist baraye return 0 ya 1


		}
		if(word == "DELETE")
		{
			if (use == 0) cout << endl << " ebteda bayad az dastoor \" USE \" estefade shavad.^_^" << endl << "> ";
			cin >> word; //khandan (
			cin >> word;
			hazf (word, keydata);//HAZF KRDN KEY VA DATA
			ofstream ofs;
			ofs.open(esmfile);
			for (int i = 0; i<keydata.size(); i++) {//neveshtan tak tak klid ha va dade ha az vector va copy dar file
				ofs << keydata[i] << endl;
			}
			cout << endl << esmfile << "> ";
		}


		if (word == "USE") {
			fcloseall();//bastan tamame file ha
			keydata.clear();//pak kardan kolle vector
			cin >> word;
			esmfile = word;

			if (Fexist(word, files) == 1) {

				cout << endl << endl << word << "> ";
			}
			if (Fexist(word, files) == 0) {
				files.push_back(word);
				makefile(word);
				cout << endl << endl << word << "> ";
			}


			ifstream ifs;
			ifs.open(word);

			while (ifs >> kedat) {//khandan tak tak klid ha va dade ha az file va copy dar vector
				keydata.push_back(kedat);
			}
			use = 1;
		}
	}
    return 0;
}

