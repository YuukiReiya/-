/*!
	@file	main.cpp
	@date	2019/06/05
	@author	番場 宥輝
	@brief	エントリーポイント
*/
#include <iostream>
#include "AbstractSample.h"
#include "InterfaceSample.h"

/*!
	@using	Inheritance::Abstract
	@brief	usingディレクティブ
*/
using namespace Inheritance::Abstract;

/*!
	@using	Inheritance::Entity
	@brief	usingディレクティブ
*/
using namespace Inheritance::Entity;

/*!
	@using	Inheritance::Interface
	@brief	usingディレクティブ
*/
using namespace Inheritance::Interface;

/*!
	@using	std
	@brief	usingディレクティブ
*/
using namespace std;

/*!
	@def	INHERITANCE
	@brief	継承
*/
#define INHERITANCE

/*!
	@def	INTERFACE
	@brief	インターフェイス
*/
#define INTERFACE

int main()
{
#pragma region 抽象クラス
#ifdef INHERITANCE
	//	インスタンス化
	Dog*dog;
	Cat*cat;
	dog = new Dog;
	cat = new Cat;

	//	ポインタ
	AbstractAnimals*animals[2] = { dog,cat };

	cout << "抽象クラスのテスト" << endl;

	//	名前表示
	for (auto it : animals) {
		cout << "動物名:";
		it->DisplayName();
	}

	//	更新処理
	//	今回は空処理なのでなにも行わない
	for (auto it : animals) {
		it->Update();
	}
	cout << endl;
#endif // INHERITANCE
#pragma endregion

#pragma region インターフェイス
#ifdef INTERFACE

	/*!
		@var	c_EnemyCount
		@brief	エネミー数
	*/
	static constexpr unsigned int c_EnemyCount = 100;
	ICharacter* player;
	ICharacter* enemys[c_EnemyCount];
	
	//	インスタンス化
	player = new Player;
	for (size_t i = 0; i < c_EnemyCount; ++i) { enemys[i] = new Enemy; }

	//	参照複製
	ICharacter* characters[c_EnemyCount + 1];
	characters[0] = player;
	for (size_t i = 0; i < c_EnemyCount; ++i) { characters[i + 1] = enemys[i]; }

	cout << "インターフェイスのテスト" << endl;

	//////////////////////////////////////////
	//	インターフェイスのメソッド呼び出し↓
	//////////////////////////////////////////

	//	アクション
	for (auto it : characters) { it->Action();	cout << endl; }

	//	移動
	for (auto it : characters) { it->Move(); cout << endl; }

	//	ジャンプ
	for (auto it : characters) { it->Jump(); cout << endl; }
#endif // INTERFACE
#pragma endregion


	system("pause");
	return 0;
}