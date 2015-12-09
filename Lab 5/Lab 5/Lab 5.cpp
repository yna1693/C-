// Lab 5.cpp : Defines the entry point for the console application.
//

#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include<string>

using namespace std;


BinaryTree<char> morse() {
	
	//Left tree from root
	BinaryTree<char> five('5');
	BinaryTree<char> four('4');
	BinaryTree<char> H('H',five, four);
	BinaryTree<char> V('V');
	V.attachRight('3');
	BinaryTree<char> S('S', H, V);
	BinaryTree<char> twoParent(' ');
	twoParent.attachRight('2');
	BinaryTree<char> F('F');
	BinaryTree<char> U('U', F, twoParent);
	BinaryTree<char> I('I', S, U);
	BinaryTree<char> R('R');
	R.attachLeft('L');
	BinaryTree<char> J('J');
	J.attachRight('1');
	BinaryTree<char> P('P');
	BinaryTree<char> W('W', P, J);
	BinaryTree<char> A('A', R, W);
	BinaryTree<char> E('E', I, A);

	//Right Tree from root
	BinaryTree<char> B('B');
	B.attachLeft('6');
	BinaryTree<char> X('X');
	BinaryTree<char> D('D', B, X);
	BinaryTree<char> C('C');
	BinaryTree<char> Y('Y');
	BinaryTree<char> K('K', C, Y);
	BinaryTree<char> N('N', D, K);
	BinaryTree<char> Z('Z');
	Z.attachLeft('7');
	BinaryTree<char> Q('Q');
	BinaryTree<char> G('G', Z, Q);
	BinaryTree<char> eightParent(' ');
	eightParent.attachLeft('8');
	BinaryTree<char> nineZeroParent(' ');
	nineZeroParent.attachLeft('9');
	nineZeroParent.attachRight('0');
	BinaryTree<char> O('O', eightParent, nineZeroParent);
	BinaryTree<char> M('M', G, O);
	BinaryTree<char> T('T', N, M);
	
	//Root Node
	BinaryTree<char> root(' ', E, T);



	return root;

}

char decode(vector<char> decodeArray) {
	
	BinaryTree<char> cur = morse();
	

	for (int i = 0; i < decodeArray.size(); i++) {
		if (decodeArray[i] == '.') {
			BinaryTree<char> left = cur.getLeftSubtree();
			cur = left;
		}
		else if (decodeArray[i] == '-') {
			BinaryTree<char> right = cur.getRightSubtree();
			cur = right;
		}
	}

	char result = cur.getRootData();

	return result;
	
}

int main()
{
	string code;
	string translatedCode;
	//vector <char> inputCodeArray;

	cout << "Please enter morse code to be translated: " << endl;

	do {
		cin >> code;
	}

	while (getline(cin, code) != NULL);
	{
		vector<char> input(code.begin(), code.end());
		for (int i = 0; i < input.size(); i++) {
			if (input [i] == '.' || input [i] == '-') 
				translatedCode = decode(input);
			else if(input [i] == -1)
				break;
		}
	}

	cout << translatedCode << endl;

	system("pause");
	return 0;
}

