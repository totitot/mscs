
#include "OpenHashTable.h"
#include "CloseHashTable.h"
#include <typeinfo>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(int argc, char* argv[]){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

	OpenHashTable oht;
	CloseHashTable cht;
	vector<string> good_str = {
								 "X9rwO"
								,"iCG7e"
								,"w4Bgn"
								,"n2nbK"
								,"YVvWe"
								,"zW9HY"
								,"hd5We"
								,"1Zfkv"
								,"g5z8J"
								,"DGvzD"
								,"JGqMd"
								,"lAQml"
								,"wV1tZ"
								,"JvoUr"
								,"SSxb9"
								,"CuRaK" };

	vector<string> bad_str = {
								 "6fO2E"
								,"P2XqF"
								,"7orQB"
								,"v7d8E"
								,"KIuxy"
								,"VoNbo"
								,"1z5Pw"
								,"lcAtL"
								,"CxII6"
								,"h17W2"
								,"sNKmM"
								,"UebOV"
								,"dDrZL"
								,"UIbmM"
								,"W4mPj"
								,"f14LC" };

	for(auto a : good_str){
		auto element = make_pair(a,dis(gen));
		cht.add(element);
		oht.add(element);
	}
	for(auto a : good_str){
		cout << "Open table: key " << a << (oht.find(a)? " " :" not ") << "found." << endl;;
	}
	for(auto a : bad_str){
		cout << "Open table: key " << a << (oht.find(a)? " " :" not ") << "found." << endl;;
	}
	for(auto a : good_str){
		cout << "Open table: key " << a << (oht.remove(a)? " " :" not ") << "removed." << endl;;
	}
	for(auto a : good_str){
		cout << "Open table: key " << a << (oht.find(a)? " " :" not ") << "found." << endl;;
	}
	for(auto a : good_str){
		cout << "Close table: key " << a << (cht.find(a)? " " :" not ") << "found." << endl;;
	}
	for(auto a : bad_str){
		cout << "Close table: key " << a << (cht.find(a)? " " :" not ") << "found." << endl;;
	}
	for(auto a : good_str){
		cout << "Close table: key " << a << (cht.remove(a)? " " :" not ") << "removed." << endl;;
	}
	for(auto a : good_str){
		cout << "Close table: key " << a << (cht.find(a)? " " :" not ") << "found." << endl;;
	}

	return 0;
}
