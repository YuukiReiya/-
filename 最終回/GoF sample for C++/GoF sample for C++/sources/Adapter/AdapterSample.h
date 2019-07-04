/*!
	@file	AdapterSample.h
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	�A�_�v�^�[�̃T���v���R�[�h

	NOTE:	���ۂ̃Q�[����������肵���󋵂ŃT���v���R�[�h���쐬����
			Target�ɑ΂���CAdapter��Adaptee��Target�𑽏d�p������
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace Adapter {

#pragma region ����

		/*!
			@class	CTarget
			@brief	�Ώۂ̃N���X
			@detail	�@�\�̒ǉ����l���Ă��邪�A�Ȃ�炩�̎���Œ��ڂ�����Ȃ��N���X
					ex)
						���g��"�u���b�N�{�b�N�X","���ƒ��ŒN������ƒ�"etc...

			NOTE:	���g�͋�ɂ��Ƃ��܂��B
		*/
		class CTarget
		{
		public:
			/*!
				@brief	�f�t�H���g�R���X�g���N�^
			*/
			CTarget() = default;

			/*!
				@brief	�f�t�H���g�f�X�g���N�^
			*/
			~CTarget() = default;

			//	���炩�̏���...

		private:

			//	���炩�̃����o�ϐ�

		};

		/*!
			@interface	IAdaptee
			@brief		�ǉ������Q(Adaptee)
			@detail		�ǉ��������@�\�̊֐��Q���������z�֐��Œ�`

			NOTE:		�ǉ��@�\��"Func1 �` Func3"�Ƃ���B
						��C++�Ȃ疢��`�ł��o���邯�ǁAC#�͑��d�p���֎~�����番����K�v������B
		*/
		__interface IAdaptee
		{
			//NOTE:	Interface�Ő錾�����֐��͑S��"�������z�֐�"�Ɠ�������

			/*!
				@fn		Func1
				@brief	�@�\�ǉ��֐�1
			*/
			void Func1();

			/*!
				@fn		Func2
				@brief	�@�\�ǉ��֐�2
			*/
			void Func2();

			/*!
				@fn		Func3
				@brief	�@�\�ǉ��֐�3
			*/
			void Func3();
		}; 

		/*!
			@class	CAdapter
			@brief	�ΏۃN���X�ɋ@�\�ǉ������g���N���X
			
			NOTE:	"Adaptee"��"Target"�̑��d�p��
		*/
		class CAdapter:
			public IAdaptee,private CTarget
		{
		public:
			/*!
				@brief	�f�t�H���g�R���X�g���N�^
			*/
			CAdapter() = default;
			/*!
				@brief	�f�t�H���g�f�X�g���N�^
			*/
			~CAdapter() = default;

			/*!
				@fn		Func1
				@brief	�@�\�ǉ��֐�1

				NOTE:	Interface�Ȃ�A�N�Z�X�C���q�Ɉˑ����Ȃ�!(public)
			*/
			void IAdaptee::Func1() {}

		protected:
			/*!
				@fn		Func2
				@brief	�@�\�ǉ��֐�2

				NOTE:	Interface�Ȃ�A�N�Z�X�C���q�Ɉˑ����Ȃ�!(protected)
			*/
			void IAdaptee::Func2() {}

		private:
			/*!
				@fn		Func3
				@brief	�@�\�ǉ��֐�3

				NOTE:	Interface�Ȃ�A�N�Z�X�C���q�Ɉˑ����Ȃ�!(private)
			*/
			void IAdaptee::Func3() {}
		};
#pragma endregion

#pragma region �T���v��

		/*!
			@class	CPlayer
			@author	A����
			@brief	�v���C���[�N���X

			NOTE:	A�����"Input"�֐��Ŏ肪�����Ȃ��A�A�C�e�����Q�b�g���鏈����B����ɓ������B
					�����Ȃ݂ɖ{���̎g�����Ƃ͈Ⴄ�̂ŁA���̎g�����͂��܂肨���߂ł��Ȃ��B
					�@�A�_�v�^�[�œK��������֐��͉��z�֐��������̓C���^�[�t�F�C�X�̕K�v������B
		*/
		class CPlayer
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CPlayer() :m_ItemCode(0) {};

			/*!
				@brief	�f�X�g���N�^
			*/
			~CPlayer() = default;

			/*!
				@fn		Input
				@brief	���͏���
				@detail	���ݐ��쒆

				NOTE:	�T���v���Ȃ̂ŋ󏈗��B
			*/
			void Input() {};

			/*!
				@fn		GetItemCode
				@brief	�ێ����Ă���A�C�e����ID�擾
				@note	"0" = ������
				@return	�A�C�e����ID
			*/
			inline const int GetItemCode()const { return m_ItemCode; }

			/*!
				@fn			SetItemCode
				@brief		�ێ����Ă���A�C�e���̓o�^
				@param[in]	�A�C�e����ID
			*/
			inline const void SetItemCode(const int id) { m_ItemCode = id; }
		private:
			/*!
				@var	m_ItemCode
				@brief	�v���C���[���ێ����Ă���A�C�e����ID
			*/
			int m_ItemCode;
		};

		/*!
			@class	CItemCollector
			@author	B����
			@brief	�A�C�e�����l������N���X

			NOTE:	������CAdapter�����C��(Adaptee)
		*/
		class CItemCollector
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CItemCollector() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~CItemCollector() = default;

			/*!
				@fn		GetItem
				@brief	�A�C�e���̎擾

				NOTE:	�A�_�v�^�[�Ń��b�v����̂ŉ��z�֐��ɂ��Ƃ��B
			*/
			virtual void GetItem()abstract;
		private:

		};

		/*!
			@class	CPlayerAdapter
			@author	B����
			@brief	B����A����̂������Ă���"CPlayer"�N���X�Ɏ�������Ȃ��悤�ɃA�_�v�^�[�Ń��b�s���O

		*/
		class CPlayerAdapter :public CItemCollector, private CPlayer
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CPlayerAdapter() :CItemCollector(), CPlayer() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CPlayerAdapter() = default;

			/*!
				@fn		GetItem
				@brief	�A�C�e���̎擾

				NOTE:	CItemCollector��GetItem�̒��g
			*/
			void GetItem()override {
				//�A�C�e���̎擾����
				const int c_DummyItem = 1;
				std::cout << "Adapter�̃A�C�e��ID:" << GetItemCode() << std::endl;
				SetItemCode(c_DummyItem);
				std::cout << "Adapter�̃A�C�e��ID:" << GetItemCode() << std::endl;
			}

		private:

		};
#pragma endregion
	}
}