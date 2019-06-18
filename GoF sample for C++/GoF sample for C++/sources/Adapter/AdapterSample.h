/*!
	@file	AdapterSample.h
	@date	2019/06/16
	@author	�ԏ� �G�P
	@brief	�A�_�v�^�[�̃T���v���R�[�h

	NOTE:	���ۂ̃Q�[����������肵���󋵂ŃT���v���R�[�h���쐬����
			Target�ɑ΂���Adapter��Adaptee��Target�𑽏d�p������
*/
#pragma once
#include <iostream>

namespace GoF {
	namespace Adapter {

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

			NOTE:	������Adapter�����C��(Adaptee)
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
			@class	CAdapter
			@author	B����
			@brief	B����A����̂������Ă���"CPlayer"�N���X�Ɏ�������Ȃ��悤�ɃA�_�v�^�[�Ń��b�s���O

		*/
		class CAdapter :public CItemCollector, private CPlayer
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CAdapter() :CItemCollector(), CPlayer() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CAdapter() = default;

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

	}
}