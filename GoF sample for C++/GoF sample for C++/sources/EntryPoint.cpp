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
#include "AbstractFactory/AbstractFactorySample.h"
#include "TemplateMethod/TemplateMethodSample.h"
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
#define SINGLETON

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
	@def	ABSTRACT_FACTORY
	@brief	アブストラクトファクトリーのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
#define ABSTRACT_FACTORY

/*!
	@def	ITERATOR
	@brief	イテレータのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
#define ITERATOR

/*!
	@def	TEMPLATE_METHOD
	@brief	テンプレートメソッドのサンプルコード
	@detail	コメントアウトでON/OFF切り替えが可能
*/
#define TEMPLATE_METHOD

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

#pragma region アブストラクトファクトリー
#ifdef ABSTRACT_FACTORY

	cout << endl;
	cout << "↓アブストラクトファクトリーのサンプルコード↓" << endl;
	AbstractFactory::CPlayer* pAbstractFactoryPlayer = new AbstractFactory::CPlayer;
	AbstractFactory::CFriend* pAbstractFactoryFriend = new AbstractFactory::CFriend;
	AbstractFactory::CMobEnemy* pAbstractFactoryMobEnemy = new AbstractFactory::CMobEnemy;
	AbstractFactory::CBossEnemy* pAbstractFactoryBossEnemy = new AbstractFactory::CBossEnemy;

	//	移動処理
	pAbstractFactoryPlayer->Move();
	cout << endl;
	pAbstractFactoryFriend->Move();
	cout << endl;
	pAbstractFactoryMobEnemy->Move();
	cout << endl;
	pAbstractFactoryBossEnemy->Move();
	cout << endl;


	//	攻撃処理
	pAbstractFactoryPlayer->Attack();
	cout << endl;
	pAbstractFactoryFriend->Attack();
	cout << endl;
	pAbstractFactoryMobEnemy->Attack();
	cout << endl;
	pAbstractFactoryBossEnemy->Attack();
	cout << endl;

	//	ダメージ処理
	pAbstractFactoryPlayer->Damage();
	cout << endl;
	pAbstractFactoryFriend->Damage();
	cout << endl;
	pAbstractFactoryMobEnemy->Damage();
	cout << endl;
	pAbstractFactoryBossEnemy->Damage();
	cout << endl;

	//	インスタンスの削除はイテレータの後!!

#endif // ABSTRACT_FACTORY
#pragma endregion

#pragma region イテレータ
#ifdef ITERATOR
	cout << endl;
	cout << "↓イテレータのサンプルコード↓" << endl;

	//アブストラクトファクトリーのサンプルコードコードを使う
#ifdef ABSTRACT_FACTORY

	vector<AbstractFactory::ICharacter*>pCharacters;

	//	キャラクターの派生クラスを可変長リストに詰め込む
	pCharacters.push_back(pAbstractFactoryPlayer);		//	プレイヤー
	pCharacters.push_back(pAbstractFactoryFriend);		//	仲間
	pCharacters.push_back(pAbstractFactoryMobEnemy);	//	モブ
	pCharacters.push_back(pAbstractFactoryBossEnemy);	//	ボス

	//	キャラクターの移動
	for (auto it : pCharacters) {
		it->Move();
		cout << endl;
	}

	//	キャラクターの攻撃
	for (auto it : pCharacters) {
		it->Attack();
		cout << endl;
	}

	//	キャラクターのダメージ
	for (auto it : pCharacters) {
		it->Damage();
		cout << endl;
	}

	//	メモリ開放
	delete pAbstractFactoryPlayer;
	delete pAbstractFactoryFriend;
	delete pAbstractFactoryMobEnemy;
	delete pAbstractFactoryBossEnemy;
#else
	//	インスタンス
	vector<AbstractFactory::ICharacter*>pCharacters;
	pCharacters.push_back(new AbstractFactory::CPlayer);
	pCharacters.push_back(new AbstractFactory::CFriend);
	pCharacters.push_back(new AbstractFactory::CMobEnemy);
	pCharacters.push_back(new AbstractFactory::CBossEnemy);

	//	キャラクターの移動
	for (auto it : pCharacters) {
		it->Move();
		cout << endl;
	}

	//	キャラクターの攻撃
	for (auto it : pCharacters) {
		it->Attack();
		cout << endl;
	}

	//	キャラクターのダメージ
	for (auto it : pCharacters) {
		it->Damage();
		cout << endl;
	}

#endif // ABSTRACT_FACTORY
	//	要素開放
	pCharacters.clear();
#endif // ITERATOR
#pragma endregion

#pragma region テンプレートメソッド
#ifdef TEMPLATE_METHOD
	cout << endl;
	cout << "↓テンプレートメソッドのサンプルコード↓" << endl;

	//	関数テンプレートのサンプル
	TemplateMethod::FuncSample();
	
	//	クラステンプレート
	//	一時的に自己定義
	TemplateMethod::CTemplate<TemplateMethod::SBase>*pTemplateClass = new TemplateMethod::CTemplate<TemplateMethod::SBase>();
	pTemplateClass->Func();

	//	メンバ関数テンプレートの利用
	pTemplateClass->MemberFunc<int>(10);

	//	メンバ変数テンプレートの利用
	//NOTE:今回は"SBase"を継承しているのでメンバ型は"SBase"
	TemplateMethod::SBase tmp;//セットする値
	pTemplateClass->SetValue(tmp);
	auto getValue = pTemplateClass->GetValue();

	//int型なら以下
	//int tmp = 99;//セットする値
	//pTemplateClass->SetValue(tmp);
	//auto getValue = pTemplateClass->GetValue();//99が取れるはず...

	//	エイリアステンプレートのサンプル
	cout << "IntArray4型のg_IA4の中身" << endl;
	for (auto it: TemplateMethod::g_IA4)
	{
		//Iteratorパターンのおさらい
		cout  <<it << endl;
	}

	//===========================================================
	//	クラステンプレートの継承利用
	//===========================================================
	TemplateMethod::CInstance* pTemplateMethodInst = new TemplateMethod::CInstance;
	pTemplateMethodInst->Func();
	TemplateMethod::CInt* pTemplateMethodInt = new TemplateMethod::CInt;
	pTemplateMethodInt->Func();

#endif // TEMPLATE_METHOD
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