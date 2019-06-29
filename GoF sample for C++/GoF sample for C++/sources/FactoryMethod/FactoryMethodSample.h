/*!
	@fExtention	FactoryMethodSample.h
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	�t�@�N�g���[���\�b�h�̃T���v���R�[�h
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

namespace GoF {
	namespace FactoryMethod {

#pragma region ����

		//	�ŏ��\��

		/*!
			@class	CTarget
			@brief	��������ΏۃN���X
		*/
		class CTarget
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CTarget() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CTarget() {}

		private:

		};

		/*!
			class	CFactoryMethod
			@brief	�ΏۃN���X�𐶐�����t�@�N�g���N���X	
		*/
		class CFactoryMethod
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CFactoryMethod() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~CFactoryMethod() = default;

			/*!
				@fn		Execute
				@brief	���s����
			*/
			inline CTarget*Execute() { return new CTarget; }

		protected:



		private:

		};
#pragma endregion


#pragma region �T���v��

		//	�񋓌^
		//NOTE:����\��p��������switch���Ɏg���B
		//	�@ (string�^��񋓌^�ɕR�Â���)
		enum EFileExtentions {
			txt,	//	.txt
			csv,	//	.csv
			md,		//	.md
		};

#pragma region ���ۃN���X
		//	�ǂݎ�����f�[�^���i�[���钊�ۃN���X
		//
		//NOTE:�ǂݎ��f�[�^�̊g���q�ɍ��킹�Čʂɏ�����ǉ��o����悤�ɒ��ۃN���X��p��
		//	�@������̓T���v���Ȃ̂œ��Ɍʂȏ����������͂��Ȃ�
		class AbstractFileData abstract
		{
		public:
			/*!
				@brief		�����t���R���X�g���N�^
				@param[in]	�i�[�f�[�^
			*/
			AbstractFileData(std::string data) {
				m_Data = data;
			}

			//�i�[�f�[�^�̎擾
			std::string GetData() { return m_Data; }

		protected:
			std::string m_Data;//�ǂݎ�����f�[�^������ϐ�
		};

		//	�t�@�C���̓ǂݎ����s�����ۃN���X
		//
		//NOTE:�ǂݎ��t�@�C���̎�ނɂ���Đ�p�̏�������������悤�ɒ��ۃN���X��p��
		//	�@ ������̓T���v���Ȃ̂Ő�p�̏������������Ȃ�
		class AbstractFileReader abstract
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			AbstractFileReader() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~AbstractFileReader() = default;

			/*!
				@fn			Create
				@brief		��ۃN���X��Read�֐��̌Ăяo��
				@param[in]	�ǂݍ��ރt�@�C����
				@return		�ǂݍ��񂾃f�[�^���i�[�����f�[�^�^

				NOTE:	�������z�֐��Ń��b�s���O���Ă���̂ŁA
						�p����̏����Ɉˑ��������A�����x�������Ă���B
			*/
			AbstractFileData* Create(std::string fileName) {
				return Read(fileName);
			};

		protected:
			/*!
				@fn		Read
				@brief	�t�@�C���ǂݍ���
			*/
			virtual AbstractFileData* Read(std::string fileName)abstract;
		};

		//	�t�@�N�g���̒��ۃN���X
		class AbstractFactory abstract
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			AbstractFactory() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~AbstractFactory() = default;

			/*!
				@fn			Create
				@brief		�ǂݍ��݃f�[�^�������o�ϐ��ɃX�g�b�N
				@param[in]	�ǂݍ��ރt�@�C���p�X
				@return		�ǂݍ��񂾃f�[�^
			*/
			inline AbstractFileData* Create(std::string fileName) {
				auto fileData = CreateFileData(fileName);
				m_fileData.push_back(fileData);
				return fileData;
			}

			/*!
				@fn		GetFileData
				@brief	�X�g�b�N�����f�[�^�̎擾
				@return	�X�g�b�N�����f�[�^
			*/
			inline std::vector<AbstractFileData*>GetFileData() { return m_fileData; }
		private:
			/*!
				@var	m_fileData
				@brief	�t�@�C���̓ǂݎ����
			*/
			std::vector<AbstractFileData*>m_fileData;

		protected:
			/*!
				@fn		Destroy
				@brief	�j������
			*/
			void Destroy() { m_fileData.clear(); }

			/*!
				@fn			AddFileData
				@brief		�f�[�^���X�g�b�N
				@param[in]	�f�[�^
			*/
			void AddFileData(AbstractFileData*data) {
				m_fileData.push_back(data);
			};

			/*!
				@fn			CreateFileData
				@brief		"Create"�֐��̒��g
				@detail		�������z�֐�
				@param[in]	�ǂݍ��ރt�@�C���p�X
			*/
			virtual AbstractFileData*CreateFileData(std::string fileName)abstract;
		};

#pragma endregion

#pragma region ��ۃN���X

		//------------------------------------------
		//�f�[�^�i�[�N���X
		//------------------------------------------
		//".txt"�g���q�̃t�@�C���f�[�^�i�[�N���X
		class TextFileData
			:public AbstractFileData
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			TextFileData() = default;

			/*!
				@brief		�����t���R���X�g���N�^
				@param[in]	�i�[�f�[�^
			*/
			TextFileData(std::string data) :AbstractFileData(data) {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~TextFileData() = default;

			//�K�v�ɉ�����".txt"��p�̏������L�q�\
			//������͓��ɓ���Ȃ��ł�...
			//void ChangeEncodeUTF8() {}//UTF8�ɕϊ�
			//void ChangeEncodeSJIS() {}//SIFT-JIS�ɕϊ�

			//NOTE:��p��������ꂽ�ꍇ�͎g�p���ŃL���X�g�������́A
			//	   ���ۃN���X�ŉ��z�錾�����Ȃ��Ǝg���Ȃ����A�J�v�Z�������悤�ˁB
			//ex) virtual void Action() abstract;
		};

		//".csv"�g���q�̃t�@�C���f�[�^�i�[�N���X
		class CsvFileData
			:public AbstractFileData
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CsvFileData() = default;

			/*!
				@brief		�����t���R���X�g���N�^
				@param[in]	�i�[�f�[�^
			*/
			CsvFileData(std::string data) :AbstractFileData(data) {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CsvFileData() = default;

			//�K�v�ɉ�����".xlsx"��p�̏������L�q�\
			//������͓��ɓ���Ȃ��ł�...
			//void ConvertXlsx() {}//�`����.xlsx�ɕϊ�

			//NOTE:��p��������ꂽ�ꍇ�͎g�p���ŃL���X�g�������́A
			//	   ���ۃN���X�ŉ��z�錾�����Ȃ��Ǝg���Ȃ����A�J�v�Z�������悤�ˁB
			//ex) virtual void Action() abstract;
		private:

		};

		//".md"�g���q�̃t�@�C���f�[�^�i�[�N���X
		class MdFileData
			:public AbstractFileData
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			MdFileData() = default;

			/*!
				@brief		�����t���R���X�g���N�^
				@param[in]	�i�[�f�[�^
			*/
			MdFileData(std::string data) :AbstractFileData(data) {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~MdFileData() = default;

			//�K�v�ɉ�����".md"��p�̏������L�q�\
			//������͓��ɓ���Ȃ��ł�...
			//void DestnationOfText() {}//�e�L�X�g�`���ɒu��

			//NOTE:��p��������ꂽ�ꍇ�͎g�p���ŃL���X�g�������́A
			//	   ���ۃN���X�ŉ��z�錾�����Ȃ��Ǝg���Ȃ����A�J�v�Z�������悤�ˁB
			//ex) virtual void Action() abstract;

		private:

		};

		//------------------------------------------
		//�t�@�C���ǂݍ��݃N���X
		//------------------------------------------
		//".txt"�g���q�̃t�@�C���ǂݎ��N���X
		class TextFileReader
			: public AbstractFileReader
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			TextFileReader() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~TextFileReader() = default;

		protected:
			/*!
				@fn			Read
				@brief		�t�@�C���ǂݍ���
				@param[in]	�ǂݍ��݃t�@�C���p�X
				@return		�i�[�����f�[�^�^

				NOTE:".txt"��p�̓ǂݍ��݂��o����悤�ɃN���X�������Ă��邪�A
					 �{�T���v���ł�3�̃N���X�ŏ������S�������B
			*/
			inline AbstractFileData* Read(std::string fileName)override {
				std::string path = fileName;
				std::ifstream ifs(fileName);
				if (ifs.fail()) { return nullptr; }
				std::string sstream;
				std::string buff;//�ǂ݂Ƃ�p�̃o�b�t�@
				while (getline(ifs, sstream))
				{
					buff += sstream;
				}
				return new TextFileData(buff);
			}
		};

		//".csv"�g���q�̃t�@�C���ǂݎ��N���X
		class CsvFileReader
			: public AbstractFileReader
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CsvFileReader() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~CsvFileReader() = default;

			/*!
				@fn			Read
				@brief		�t�@�C���ǂݍ���
				@param[in]	�ǂݍ��݃t�@�C���p�X
				@return		�i�[�����f�[�^�^

				NOTE:".csv"��p�̓ǂݍ��݂��o����悤�ɃN���X�������Ă��邪�A
					 �{�T���v���ł�3�̃N���X�ŏ������S�������B
			*/
			AbstractFileData* Read(std::string fileName)override {
				std::ifstream ifs(fileName);
				if (ifs.fail()) { return nullptr; }
				std::string sstream;
				std::string buff;//�ǂ݂Ƃ�p�̃o�b�t�@
				while (getline(ifs, sstream))
				{
					buff += sstream;
				}
				return new CsvFileData(buff);
			}
		};

		//".md"�g���q�̃t�@�C���ǂݎ��N���X
		class MdFileReader
			: public AbstractFileReader
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			MdFileReader() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~MdFileReader() = default;

			/*!
				@fn			Read
				@brief		�t�@�C���ǂݍ���
				@param[in]	�ǂݍ��݃t�@�C���p�X
				@return		�i�[�����f�[�^�^
			
				NOTE:".md"��p�̓ǂݍ��݂��o����悤�ɃN���X�������Ă��邪�A
					 �{�T���v���ł�3�̃N���X�ŏ������S�������B
			*/
			AbstractFileData* Read(std::string fileName)override {
				std::ifstream ifs(fileName);
				if (ifs.fail()) { return nullptr; }
				std::string sstream;
				std::string buff;//�ǂ݂Ƃ�p�̃o�b�t�@
				while (getline(ifs, sstream))
				{
					buff += sstream;
				}
				return new MdFileData(buff);
			}
		};

		//------------------------------------------
		//�t�@�N�g���N���X
		//------------------------------------------

		//	�t�@�N�g���Ƃ��ċ@�\�������ۃN���X
		class CFileFactory
			:public AbstractFactory
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CFileFactory() = default;

			/*!
				@brief	�f�X�g���N�^
				@detail	�������J�����R�R�ōs���Ă���B
			*/
			~CFileFactory() { Destroy(); };

			//	�萔�錾
			//NOTE:����\�̐錾/��`
			const std::map<std::string, EFileExtentions>c_Extentions = {
				{".txt",EFileExtentions::txt},
				{".csv",EFileExtentions::csv},
				{".md",EFileExtentions::md}
			};

		protected:
			//�t�@�C���p�X�����p�̃f�[�^�N���X�ɓǂݍ��񂾃f�[�^���i�[
			AbstractFileData*CreateFileData(std::string fileName)override final {
				//	�g���q�̓���
				auto offset = fileName.rfind(".");				//������̌�납��T����"."�̈ʒu
				auto extention = fileName.substr(offset);		//�g���q�̕�����

				//	�t�@�C���̊g���q
				auto fExtention = c_Extentions.at(extention);	//������̊g���q����R�Â����񋓌^���擾
				AbstractFileData*file = nullptr;		//�f�[�^
				AbstractFileReader*reader = nullptr;	//���[�_�[

				//	�g���q�ɉ����āA�ǂݍ��݃N���X��؂�ւ���
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
					std::cout << "�g���q�ɊY��������̂�����" << std::endl;
					//	����̓G���[�`�F�b�N���Ȃ��Ă��܂��B
					//	�������炸�B
					return nullptr;
				}
				file = reader->Create(fileName);	//�i�[�N���X�𐶐�
				delete reader;//���������[�N�h�~
				return file;
			}
		private:

		};

#pragma endregion//��ۃN���X
#pragma endregion//�T���v��

	}
}