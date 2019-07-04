/*!
	@file	VisitorSample.h
	@date	2019/06/18
	@author	�ԏ� �G�P
	@brief	Visitor�p�^�[���̃T���v���R�[�h

	NOTE:	Visitor �� Dispatch
*/
#pragma once

namespace GoF {
	namespace Visitor1 {

		/*!
			1.�K�₷��S�ẴN���X�ɑ΂��āA�@�\�񋟂��s��Visitor�N���X

			2.�K����󂯓����e�N���X�̃C���^�[�t�F�C�X�ɖK����󂯓���郁�\�b�h���`

			<�O��>
			"�v���C���["�A"�G"�A"�A�C�e��"�͂��ꂼ��ʒu���������A������"�L�����N�^�[(�v���C���[�ƓG)"�͔͈͂����Ƃ���B
			"�v���C���["�͔͈͓���"�G"��"�A�C�e��"�����邩�A"�G"��"�v���C���["��"�A�C�e��"�����邩�����ꂼ��ʓr�֐������K�v���o�Ă��Ă��܂��B
			������"�͈͓��ɃI�u�W�F�N�g�����݂��邩"���@�\(�N���X)�Ƃ��ĕ��������ƂŃR�[�h�ʂ����炷�B

			NOTE:	�t�@�C�������͂��Ȃ�(��{�C�����C��)
					�T�O�I�ɂ͑��d�f�B�X�p�b�`�ɋ߂�(�H)
		*/

#pragma region ���N���X
		/*!
			@class	CObject
			@brief	�Q�[���I�u�W�F�N�g�̒��ۃN���X
		*/
		class CObject abstract
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CObject() :pos({ 0,0,0 }) {};

			/*!
				@brief	���z�f�X�g���N�^
			*/
			virtual~CObject() = default;

			/*!
				@struct	SFloat3
				@brief	float�^3�̍\����
			*/
			struct SFloat3
			{
				/*!
					@var	x,y,z
					@brief	�O�����ʒu���
				*/
				float x, y, z;

				/*!
					@operator	==
					@brief		�������Z�q�̒�`

					NOTE:		�ʂɂ���Ȃ����ǁA�������o���Ă����Ƃ�����I
				*/
				inline bool operator ==(SFloat3 other) {
					return this->x == other.x&&this->y == other.y&&this->z == other.z;
				}
			}pos;
			/*!
				@struct	SFloat2
				@brief	float�^3�̍\����
			*/
			struct SFloat2
			{
				/*!
					@var	x,y
					@brief	�񎟌��ʒu���
				*/
				float x, y;
			};


		private:

		};

		/*!
			@class	CCharacter
			@brief	�L�����N�^�[�̊��N���X
		*/
		class CCharacter abstract
			:public CObject
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CCharacter() :CObject() {};

			/*!
				@brief	���z�f�X�g���N�^
			*/
			virtual~CCharacter() = default;

			/*!
				@fn		GetRange
				@brief	�͈͂̎擾
			*/
			const SFloat3 GetRange() const { return m_Range; }

		protected:
			/*!
				@var	m_Range
				@brief	�͈�
			*/
			SFloat3 m_Range;
		};


#pragma endregion

#pragma region �I�u�W�F�N�g

		/*!
			@class	CPlayer
			@brief	�v���C���[�N���X
			@detail	����:�K����󂯓����
		*/
		class CPlayer
			:public CCharacter
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CPlayer() :CCharacter() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CPlayer();

		private:

		};

		/*!
			@class	CEnemy
			@brief	�G�l�~�[�N���X
			@detail	����:�K����󂯓����
		*/
		class CEnemy
			:public CCharacter
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CEnemy() :CCharacter() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CEnemy() = default;

		private:

		};

		/*!
			@class	CItem
			@brief	�A�C�e���N���X
			@detail	����:�K����󂯓����
		*/
		class CItem
			:public CObject
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			CItem() :CObject() {}

			/*!
				@brief	�f�X�g���N�^
			*/
			~CItem() = default;

		private:

		};

#pragma endregion

#pragma region Visitor

		/*!
			@class	RangeInObject
			@brief	�͈͓��ɃI�u�W�F�N�g�����邩�m�F
			@detail	����:Visitor
		*/
		class RangeInObject
		{
		public:
			/*!
				@brief	�R���X�g���N�^
			*/
			RangeInObject() = default;

			/*!
				@brief	�f�X�g���N�^
			*/
			~RangeInObject() = default;

			/*!
				@fn			SetPosition
				@brief		�����ʒu�̐ݒ�
				@param[in]	�����ʒu
			*/
			inline void SetPosition(CObject::SFloat3 pos) { m_Pos = pos; }

			/*!
				@fn			SetRange
				@brief		�����͈͂̐ݒ�
				@param[in]	�����͈�
			*/
			inline void SetRande(CObject::SFloat3 range) { m_Range = range; }

			/*!
				@fn		VisitPlayer
				@brief	Player�̖K��

				NOTE:	����̃P�[�X����"Player"��"AbstractEnemy"�̓����o���ꏏ�Ȃ̂�
						�����A"VisitCharacter"�ł������ǁA�˂����񂶂�_��!
			*/
			void VisitPlayer(CPlayer*player) {
				//	�K�₷��ۂɍׂ����ݒ肵�������
				//	�Ⴆ��...
				//	�X�e�[�^�X�Ƃ�
			}

			/*!
				@fn		VisitEnemy
				@brief	AbstractEnemy�̖K��

				NOTE:	����̃P�[�X����"Player"��"AbstractEnemy"�̓����o���ꏏ�Ȃ̂�
						�����A"VisitCharacter"�ł������ǁA�˂����񂶂�_��!
			*/
			void VisitEnemy(CEnemy*enemy) {
				//	�K�₷��ۂɍׂ����ݒ肵�������
				//	�Ⴆ��...
				//	ID�Ƃ�
			}

			/*!
				@fn		VisitItem
				@brief	Item�̖K��
			*/
			void VisitItem(CItem*item) {
				//	�K�₷��ۂɍׂ����ݒ肵�������
				//	�Ⴆ��...
				//	�A�C�e���̍��W�͎O�����ł͂Ȃ��A�񎟌��ɃR���o�[�g�Ƃ�
			}

			/*!
				@fn		GetResult
				@brief	���茋�ʂ̎擾

				NOTE:	���菈���͓K��
			*/
			const bool GetResult() {
				return m_Pos == m_Range;
			}

		private:
			/*!
				@var	m_Pos
				@brief	�����ʒu
			*/
			CObject::SFloat3 m_Pos;

			/*!
				@var	m_Range
				@brief	�����͈�
			*/
			CObject::SFloat3 m_Range;

		};

#pragma endregion
	}

	namespace Visitor {

		/*!
			@class	CPotision
			@brief	
		*/
		class CPosition
		{
		public:

		private:
				
		};
	}
}