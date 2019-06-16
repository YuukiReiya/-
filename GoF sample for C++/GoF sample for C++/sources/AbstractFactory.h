/*!
	@author	番場宥輝
	@brief	Abstract Factory
	@detail	生成パターン①
*/
#pragma once



#pragma region 	<事始め>

	//制作中に、こんなことはありませんでしたか？
	//1.キャラクタークラスが武器クラスを保持し生成を行っている...
	//ex)
	//	class Player
	//	{
	//	 public:
	//	 // 武器生成
	//	 void CreateWeapon();		//装備を作成
	//	 void CreateWeapon(int id);	//IDに応じた装備を作成

	//	 //	base movement
	//	 void Move()override;
	//	 void Attack()override;
	//	 ・
	//	 ・
	//	 ・
	//	 }

	//2.武器クラスの関数に主人公と敵のキャラクター情報を保持するオーバーロードメソッドが出来てしまった...
	//ex)
	//	class Weapon
	//	{
	//	 public:
	//	 // 装備する
	//	 void equip(Player& p){ p.weapon = this; }
	//	 void equip(Enemy& e){ e.weapon = this; }
	//	 }

	//↑こういったコードは無駄が多く、修正が効きにくいのでやめましょう！
	//良いコードとは理解しやすく修正しやすい、かつ柔軟な対応ができるコードです。
#pragma endregion

#pragma region <問題点>

	//上記のコード(ex)はなぜダメなんだかわかりますか？
	//
	//1. 
	//・プレイヤーに武器生成関数の定義を持たせてしまうと、プレイヤーの武器を任意で変えることが出来ない。
	//→柔軟性×
	//・↑上記の対策として引数を渡させることで柔軟性は回避することができます。
	//  が、敵を作るときも同じ関数を宣言定義する必要が出てきます。
	//  よって一つの関数を直すことになると全てに対して変更を加えないといけなくなります。
	//→保守性×
	//・コードが煩雑になりやすく、長文になると理解しにくく、ヒューマンエラーを起こしがちです。
	//→可読性×

	//2.
	//・キャラクターが増えていく毎にオーバーロードを増やさなければいけません。
	//  これも変更をすべてに対して加えなければならなくなるのでよくありません。
	//  →保守性×
#pragma endregion

#pragma region <メリット・デメリット>
//<メリット>
//	・クラス同士の依存関係の切り離しと保守性(カプセル化)の強化
//	→キャラクター側のコードを何一つ変えることなく、武器の生成を行うことが出来る
//		(生成する武器側のコードのみを編集するようになるため)
//	・柔軟性の向上
//	→キャラクターに依存しなくなるのでたくさん増やすことが出来る
//<デメリット>
//	・プロジェクトが肥大化しやすい
//	・ファイル(ソース)数が増大する
#pragma endregion

#pragma region 概要

#pragma endregion


namespace GoF {
	namespace AbstractFactory {

#pragma region 武器

		//	武器のインターフェイス
		__interface IWeapon
		{
			void create();//生成処理(サンプルではダミー)
			const char*getWeaponName();
		};

		//	ビームライフル
		class CBeamRifle:public IWeapon
		{
		public:
			CBeamRifle() = default;
			~CBeamRifle() = default;

			void IWeapon::create() {};
			inline const char* IWeapon::getWeaponName() { return "ビームライフル"; }
		private:
		};

		//	頭部バルカン
		class CHeadBalkan:public IWeapon
		{
		public:
			void IWeapon::create() {};
			inline const char*IWeapon::getWeaponName() { return "頭部バルカン"; }
		private:

		};

		//	ビームサーベル
		class CBeamSaber:IWeapon
		{
		public:
			void IWeapon::create() {}
			inline const char*IWeapon::getWeaponName() { return "ビームサーベル"; }
		private:

		};

#pragma endregion

#pragma region ファクトリー
		//	抽象クラス
		class CAbstractFactory abstract
		{
		public:
			CAbstractFactory(IWeapon*main, IWeapon*sub, IWeapon*meel):
				pMain(pMain),pSub(sub),pMeel(meel) {}
			~CAbstractFactory() = default;
			virtual void Create()abstract;
		private:
			IWeapon*pMain;
			IWeapon*pSub;
			IWeapon*pMeel;
		};

		//	連邦軍の武器セット
		class CFederalArmySet
		{
		public:
		};

		//	ジオンの武器セット
#pragma endregion

#pragma region キャラ

		//	キャラクターのインターフェイス
		__interface ICharacter
		{
			//	装備する
			void equip(CAbstractFactory*);

			//TODO: サンプルなのでコメントアウトしときます。
			//		実際の制作では持たせた方がいいかも…
			//void attack();
			//void move();
		};

		//	ガンダムクラス
		class CGundam:public ICharacter
		{
		public:
			CGundam() = default;
			~CGundam() = default;

			void ICharacter::equip(CAbstractFactory* factory) {factory.};
		private:
			IWeapon*m_pMainWeapon;	//主兵装
			IWeapon*m_pSubWeapon;	//副兵装
			IWeapon*m_pMeleeWeapon;	//近接武器
		};

		//	ジムクラス
		class CGM
		{

		};
#pragma endregion

	}
}