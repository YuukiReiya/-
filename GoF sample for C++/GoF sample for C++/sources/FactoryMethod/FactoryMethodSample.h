/*!
	@fExtention	FactoryMethodSample.h
	@date	2019/06/16
	@author	番場 宥輝
	@brief	ファクトリーメソッドのサンプルコード
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

namespace GoF {
	namespace FactoryMethod {

#pragma region 説明

		//	最小構成

		/*!
			@class	CTarget
			@brief	生成する対象クラス
		*/
		class CTarget
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CTarget() {}

			/*!
				@brief	デストラクタ
			*/
			~CTarget() {}

		private:

		};

		/*!
			class	CFactoryMethod
			@brief	対象クラスを生成するファクトリクラス	
		*/
		class CFactoryMethod
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CFactoryMethod() = default;

			/*!
				@brief	デストラクタ
			*/
			~CFactoryMethod() = default;

			/*!
				@fn		Execute
				@brief	実行処理
			*/
			inline CTarget*Execute() { return new CTarget; }

		protected:



		private:

		};
#pragma endregion


#pragma region サンプル

		//	列挙型
		//NOTE:決定表を用いた賢いswitch文に使う。
		//	　 (string型を列挙型に紐づける)
		enum EFileExtentions {
			txt,	//	.txt
			csv,	//	.csv
			md,		//	.md
		};

#pragma region 抽象クラス
		//	読み取ったデータを格納する抽象クラス
		//
		//NOTE:読み取るデータの拡張子に合わせて個別に処理を追加出来るように抽象クラスを用意
		//	　※今回はサンプルなので特に個別な処理を実装はしない
		class AbstractFileData abstract
		{
		public:
			/*!
				@brief		引数付きコンストラクタ
				@param[in]	格納データ
			*/
			AbstractFileData(std::string data) {
				m_Data = data;
			}

			//格納データの取得
			std::string GetData() { return m_Data; }

		protected:
			std::string m_Data;//読み取ったデータを入れる変数
		};

		//	ファイルの読み取りを行う抽象クラス
		//
		//NOTE:読み取るファイルの種類によって専用の処理を加えられるように抽象クラスを用意
		//	　 ※今回はサンプルなので専用の処理を実装しない
		class AbstractFileReader abstract
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			AbstractFileReader() = default;

			/*!
				@brief	デストラクタ
			*/
			~AbstractFileReader() = default;

			/*!
				@fn			Create
				@brief		具象クラスのRead関数の呼び出し
				@param[in]	読み込むファイル名
				@return		読み込んだデータを格納したデータ型

				NOTE:	純粋仮想関数でラッピングしているので、
						継承先の処理に依存させず、結合度を下げている。
			*/
			AbstractFileData* Create(std::string fileName) {
				return Read(fileName);
			};

		protected:
			/*!
				@fn		Read
				@brief	ファイル読み込み
			*/
			virtual AbstractFileData* Read(std::string fileName)abstract;
		};

		//	ファクトリの抽象クラス
		class AbstractFactory abstract
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			AbstractFactory() = default;

			/*!
				@brief	デストラクタ
			*/
			~AbstractFactory() = default;

			/*!
				@fn			Create
				@brief		読み込みデータをメンバ変数にストック
				@param[in]	読み込むファイルパス
				@return		読み込んだデータ
			*/
			inline AbstractFileData* Create(std::string fileName) {
				auto fileData = CreateFileData(fileName);
				m_fileData.push_back(fileData);
				return fileData;
			}

			/*!
				@fn		GetFileData
				@brief	ストックしたデータの取得
				@return	ストックしたデータ
			*/
			inline std::vector<AbstractFileData*>GetFileData() { return m_fileData; }
		private:
			/*!
				@var	m_fileData
				@brief	ファイルの読み取り情報
			*/
			std::vector<AbstractFileData*>m_fileData;

		protected:
			/*!
				@fn		Destroy
				@brief	破棄処理
			*/
			void Destroy() { m_fileData.clear(); }

			/*!
				@fn			AddFileData
				@brief		データをストック
				@param[in]	データ
			*/
			void AddFileData(AbstractFileData*data) {
				m_fileData.push_back(data);
			};

			/*!
				@fn			CreateFileData
				@brief		"Create"関数の中身
				@detail		純粋仮想関数
				@param[in]	読み込むファイルパス
			*/
			virtual AbstractFileData*CreateFileData(std::string fileName)abstract;
		};

#pragma endregion

#pragma region 具象クラス

		//------------------------------------------
		//データ格納クラス
		//------------------------------------------
		//".txt"拡張子のファイルデータ格納クラス
		class TextFileData
			:public AbstractFileData
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			TextFileData() = default;

			/*!
				@brief		引数付きコンストラクタ
				@param[in]	格納データ
			*/
			TextFileData(std::string data) :AbstractFileData(data) {}

			/*!
				@brief	デストラクタ
			*/
			~TextFileData() = default;

			//必要に応じて".txt"専用の処理を記述可能
			//※今回は特に入れないです...
			//void ChangeEncodeUTF8() {}//UTF8に変換
			//void ChangeEncodeSJIS() {}//SIFT-JISに変換

			//NOTE:専用処理を入れた場合は使用側でキャストもしくは、
			//	   抽象クラスで仮想宣言をしないと使えないし、カプセル化しようね。
			//ex) virtual void Action() abstract;
		};

		//".csv"拡張子のファイルデータ格納クラス
		class CsvFileData
			:public AbstractFileData
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CsvFileData() = default;

			/*!
				@brief		引数付きコンストラクタ
				@param[in]	格納データ
			*/
			CsvFileData(std::string data) :AbstractFileData(data) {}

			/*!
				@brief	デストラクタ
			*/
			~CsvFileData() = default;

			//必要に応じて".xlsx"専用の処理を記述可能
			//※今回は特に入れないです...
			//void ConvertXlsx() {}//形式を.xlsxに変換

			//NOTE:専用処理を入れた場合は使用側でキャストもしくは、
			//	   抽象クラスで仮想宣言をしないと使えないし、カプセル化しようね。
			//ex) virtual void Action() abstract;
		private:

		};

		//".md"拡張子のファイルデータ格納クラス
		class MdFileData
			:public AbstractFileData
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			MdFileData() = default;

			/*!
				@brief		引数付きコンストラクタ
				@param[in]	格納データ
			*/
			MdFileData(std::string data) :AbstractFileData(data) {}

			/*!
				@brief	デストラクタ
			*/
			~MdFileData() = default;

			//必要に応じて".md"専用の処理を記述可能
			//※今回は特に入れないです...
			//void DestnationOfText() {}//テキスト形式に置換

			//NOTE:専用処理を入れた場合は使用側でキャストもしくは、
			//	   抽象クラスで仮想宣言をしないと使えないし、カプセル化しようね。
			//ex) virtual void Action() abstract;

		private:

		};

		//------------------------------------------
		//ファイル読み込みクラス
		//------------------------------------------
		//".txt"拡張子のファイル読み取りクラス
		class TextFileReader
			: public AbstractFileReader
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			TextFileReader() = default;

			/*!
				@brief	デストラクタ
			*/
			~TextFileReader() = default;

		protected:
			/*!
				@fn			Read
				@brief		ファイル読み込み
				@param[in]	読み込みファイルパス
				@return		格納したデータ型

				NOTE:".txt"専用の読み込みが出来るようにクラス分けしているが、
					 本サンプルでは3つのクラスで処理が全く同じ。
			*/
			inline AbstractFileData* Read(std::string fileName)override {
				std::string path = fileName;
				std::ifstream ifs(fileName);
				if (ifs.fail()) { return nullptr; }
				std::string sstream;
				std::string buff;//読みとり用のバッファ
				while (getline(ifs, sstream))
				{
					buff += sstream;
				}
				return new TextFileData(buff);
			}
		};

		//".csv"拡張子のファイル読み取りクラス
		class CsvFileReader
			: public AbstractFileReader
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CsvFileReader() = default;

			/*!
				@brief	デストラクタ
			*/
			~CsvFileReader() = default;

			/*!
				@fn			Read
				@brief		ファイル読み込み
				@param[in]	読み込みファイルパス
				@return		格納したデータ型

				NOTE:".csv"専用の読み込みが出来るようにクラス分けしているが、
					 本サンプルでは3つのクラスで処理が全く同じ。
			*/
			AbstractFileData* Read(std::string fileName)override {
				std::ifstream ifs(fileName);
				if (ifs.fail()) { return nullptr; }
				std::string sstream;
				std::string buff;//読みとり用のバッファ
				while (getline(ifs, sstream))
				{
					buff += sstream;
				}
				return new CsvFileData(buff);
			}
		};

		//".md"拡張子のファイル読み取りクラス
		class MdFileReader
			: public AbstractFileReader
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			MdFileReader() = default;

			/*!
				@brief	デストラクタ
			*/
			~MdFileReader() = default;

			/*!
				@fn			Read
				@brief		ファイル読み込み
				@param[in]	読み込みファイルパス
				@return		格納したデータ型
			
				NOTE:".md"専用の読み込みが出来るようにクラス分けしているが、
					 本サンプルでは3つのクラスで処理が全く同じ。
			*/
			AbstractFileData* Read(std::string fileName)override {
				std::ifstream ifs(fileName);
				if (ifs.fail()) { return nullptr; }
				std::string sstream;
				std::string buff;//読みとり用のバッファ
				while (getline(ifs, sstream))
				{
					buff += sstream;
				}
				return new MdFileData(buff);
			}
		};

		//------------------------------------------
		//ファクトリクラス
		//------------------------------------------

		//	ファクトリとして機能させる具象クラス
		class CFileFactory
			:public AbstractFactory
		{
		public:
			/*!
				@brief	コンストラクタ
			*/
			CFileFactory() = default;

			/*!
				@brief	デストラクタ
				@detail	メモリ開放もココで行っている。
			*/
			~CFileFactory() { Destroy(); };

			//	定数宣言
			//NOTE:決定表の宣言/定義
			const std::map<std::string, EFileExtentions>c_Extentions = {
				{".txt",EFileExtentions::txt},
				{".csv",EFileExtentions::csv},
				{".md",EFileExtentions::md}
			};

		protected:
			//ファイルパスから専用のデータクラスに読み込んだデータを格納
			AbstractFileData*CreateFileData(std::string fileName)override final {
				//	拡張子の特定
				auto offset = fileName.rfind(".");				//文字列の後ろから探した"."の位置
				auto extention = fileName.substr(offset);		//拡張子の文字列

				//	ファイルの拡張子
				auto fExtention = c_Extentions.at(extention);	//文字列の拡張子から紐づけた列挙型を取得
				AbstractFileData*file = nullptr;		//データ
				AbstractFileReader*reader = nullptr;	//リーダー

				//	拡張子に応じて、読み込みクラスを切り替える
				switch (fExtention)
				{
					//".txt"
				case GoF::FactoryMethod::txt:
					reader = new TextFileReader;
					break;
					//".csv"
				case GoF::FactoryMethod::csv:
					reader = new CsvFileReader;
					break;
					//".md"
				case GoF::FactoryMethod::md:
					reader = new MdFileReader;
					break;
					//"ERROR"
				default:
					std::cout << "拡張子に該当するものが無い" << std::endl;
					//	今回はエラーチェックを省いています。
					//	あしからず。
					return nullptr;
				}
				file = reader->Create(fileName);	//格納クラスを生成
				delete reader;//メモリリーク防止
				return file;
			}
		private:

		};

#pragma endregion//具象クラス
#pragma endregion//サンプル

	}
}