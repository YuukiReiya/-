/*!
	@file	EntryPoint.cpp
	@date	2019/06/16
	@author	番場 宥輝
	@brief	エントリーポイント
*/
#include <iostream>
#include "Singleton/SingletonSample.h"
#include "Singleton/Sample1.h"
#include "Singleton/Sample2.h"
#include "Adapter/AdapterSample.h"
#include "FactoryMethod/FactoryMethodSample.h"
#include "Visitor/VisitorSample.h"

/*!
	@using	std
	@brief	usingディレクティブ
*/
using namespace std;

/*!
	@using	GoF
	@brief	usingディレクティブ
*/
using namespace GoF;

/*!
	@def	SINGLETON
	@brief	シングルトンのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
//#define SINGLETON

/*!
	@def	ADAPTER
	@brief	アダプターのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
#define ADAPTER

/*!
	@def	FACTORY_METHOD
	@brief	ファクトリーメソッドのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
#define FACTORY_METHOD

/*!
	@def	VIVITOR
	@brief	ビジターのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
#define VISITOR

//NOTE:	プログラムのエントリーポイント(メイン関数)
int main()
{

#pragma region シングルトン
#ifdef SINGLETON
	cout << endl;
	cout << "↓シングルトンのサンプルコード↓" << endl;

	//NOTE:	シングルトンのアクセスは長くなりがち
	//			
	//		ex) GoF::Singleton::CSingleton::GetInstance().GetCount()
	//			これでようやくGetCountを呼び出せる。
	//
	//		そこで!!
	//		usingやtypedefを使った別名やアドレス参照で参照用の変数を用意しておくと楽になる

	//1.using
	using usingSingeton = GoF::Singleton::CSingleton;
	usingSingeton::GetInstance().GetCount();		//	呼び出し方の例なのでダミー処理としてゲッターを呼び出している

	//2.typedef
	typedef GoF::Singleton::CSingleton typedefSingleton;
	typedefSingleton::GetInstance().GetCount();		//	呼び出し方の例なのでダミー処理としてゲッターを呼び出している

	//3.アドレス参照
	auto& singleton = GoF::Singleton::CSingleton::GetInstance();//型推論使っているけど"GoF::Singleton::CSingleton"これでもよし
	singleton.GetCount();							//	呼び出し方の例なのでダミー処理としてゲッターを呼び出している
	//※アドレス参照はコンストラクタ周りををしっかり理解しないと、ヒューマンエラーで複製出来てしまうことに注意!!

	//	↑どれでも好きなのをどうぞ↑
	//	※今回はアドレス参照をします。

	//	シングルトンのカウンタを確認
	cout << "最初のカウンタ:" << singleton.GetCount() << endl;//	値は"0"

	singleton.AddCount();
	cout << "Add後のカウンタ:" << singleton.GetCount() << endl;//	値は"1"

	//	Singleton::CSample1と2の別ファイルに跨っているプログラムにも作用するか確認
	Singleton::CSample1*pSingletonSample1 = new Singleton::CSample1;	//コンストラクタで加算しているので加算されているはず...
	cout << "サンプル1生成後のカウンタ:" << singleton.GetCount() << endl;//	値は"2"

	Singleton::CSample2*pSingletonSample2 = new Singleton::CSample2;		//デストラクタで加算しているのでまだ加算されないはず...
	cout << "サンプル2生成後のカウンタ:" << singleton.GetCount() << endl;//	値は"2"

	delete pSingletonSample1;
	cout << "サンプル1破棄後のカウンタ:" << singleton.GetCount() << endl;//	値は"2"
	
	delete pSingletonSample2;//ここで加算されるはず
	cout << "サンプル2破棄後のカウンタ:" << singleton.GetCount() << endl;//	値は"3"

#endif // SINGLETON
#pragma endregion

#pragma region アダプター
#ifdef ADAPTER
	//参考:https://riptutorial.com/ja/cplusplus/example/24704/%E3%82%A2%E3%83%80%E3%83%97%E3%82%BF%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3

	cout << endl;
	cout<< "↓アダプターのサンプルコード↓" << endl;
	//	変数を別に定義(理由は後述)
	Adapter::CPlayer*pAdapterPlayer = new Adapter::CPlayer;
	cout << "PlayerのアイテムID:" << pAdapterPlayer->GetItemCode() << endl;

	//	アダプターでダウンキャスト
	Adapter::CItemCollector*pItemCollector = new Adapter::CPlayerAdapter;
	

	//	これで"Player"側では宣言していないけど"GetItem"関数を呼んだことになる
	//	※上記のように変数を別で定義してしまった場合は当然、インスタンスが違うので値は別になる
	//	　ex)pAdapterPlayer->GetItemCode() ≠ pItemCollector->GetItemCode();
	pItemCollector->GetItem();
	cout << "PlayerのアイテムID:" << pAdapterPlayer->GetItemCode() << endl;

	//	メモリ開放
	delete pItemCollector;
	delete pAdapterPlayer;
#endif // ADAPTER
#pragma endregion

#pragma region ファクトリーメソッド
#ifdef FACTORY_METHOD
	cout << endl;
	cout << "↓ファクトリーメソッドのサンプルコード↓" << endl;

	//	宣言
	FactoryMethod::AbstractFileData *txt, *csv, *md;

	//txt = new FactoryMethod::TextFileData;
	//csv = new FactoryMethod::CsvFileData;
	//md  = new FactoryMethod::MdFileData;

	//NOTE:ファクトリーメソッドを使用することで、
	//	上記コードが、下記コードへ書き換えることが出来る。
	//	(動作は同じ)
	//NOTE:"new"を使ってインスタンス生成すると型名(型)が変わったときに全て編集しないとダメなのを防げる
	//ex)	下記のような書き換えの必要がなくなる
	//		txt = FactoryMethod::TextFileData; → = FactoryMethod::CsvFileData;
	//		csv = FactoryMethod::TextFileData; → = FactoryMethod::CsvFileData;
	//		md  = FactoryMethod::TextFileData; → = FactoryMethod::CsvFileData;
	
	
	auto fileFactory = new FactoryMethod::CFileFactory;
	txt = fileFactory->Create("resource/sample.txt");
	csv = fileFactory->Create("resource/sample.csv");
	md = fileFactory->Create("resource/sample.md");

	//	表示
	cout << "インスタンスからアクセス" << endl;
	cout << txt->GetData() << endl;
	cout << csv->GetData() << endl;
	cout << md->GetData() << endl;

	cout << endl << "ファクトリからアクセス" << endl;
	//NOTE:	Factoryが生成したインスタンスを保持しているため、
	//		Factoryにアクセスしインスタンスを求めることも可能。
	cout << fileFactory->GetFileData()[0]->GetData() << endl;//.txtサンプルと同じ
	cout << fileFactory->GetFileData()[1]->GetData() << endl;//.csvサンプルと同じ
	cout << fileFactory->GetFileData()[2]->GetData() << endl;//.mdサンプルと同じ

#endif // FACTORY_METHOD
#pragma endregion

#pragma region ビジター
#ifdef VISITOR

	//Visitor::RangeInObject* rio = new Visitor::RangeInObject;
	//Visitor::CPlayer* pVisitorPlayer = new Visitor::CPlayer;
	//Visitor::CEnemy* pVisitEnemy = new Visitor::CEnemy;
	//Visitor::CItem* pVisitorItem = new Visitor::CItem;

	//	"プレイヤー" : "敵"
	//rio->VisitPlayer(pVisitorPlayer);



#endif // VISITOR
#pragma endregion



	//	改行を挿入しとく
	cout << endl;
	system("pause");
	return 0;
}