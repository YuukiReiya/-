/*!
	@author	�ԏ�G�P
	@brief	Abstract Factory
	@detail	�����p�^�[���@
*/
#pragma once



#pragma region 	<���n��>

	//���쒆�ɁA����Ȃ��Ƃ͂���܂���ł������H
	//1.�L�����N�^�[�N���X������N���X��ێ����������s���Ă���...
	//ex)
	//	class Player
	//	{
	//	 public:
	//	 // ���퐶��
	//	 void CreateWeapon();		//�������쐬
	//	 void CreateWeapon(int id);	//ID�ɉ������������쐬

	//	 //	base movement
	//	 void Move()override;
	//	 void Attack()override;
	//	 �E
	//	 �E
	//	 �E
	//	 }

	//2.����N���X�̊֐��Ɏ�l���ƓG�̃L�����N�^�[����ێ�����I�[�o�[���[�h���\�b�h���o���Ă��܂���...
	//ex)
	//	class Weapon
	//	{
	//	 public:
	//	 // ��������
	//	 void equip(Player& p){ p.weapon = this; }
	//	 void equip(Enemy& e){ e.weapon = this; }
	//	 }

	//�������������R�[�h�͖��ʂ������A�C���������ɂ����̂ł�߂܂��傤�I
	//�ǂ��R�[�h�Ƃ͗������₷���C�����₷���A���_��ȑΉ����ł���R�[�h�ł��B
#pragma endregion

#pragma region <���_>

	//��L�̃R�[�h(ex)�͂Ȃ��_���Ȃ񂾂��킩��܂����H
	//
	//1. 
	//�E�v���C���[�ɕ��퐶���֐��̒�`���������Ă��܂��ƁA�v���C���[�̕����C�ӂŕς��邱�Ƃ��o���Ȃ��B
	//���_��~
	//�E����L�̑΍�Ƃ��Ĉ�����n�����邱�Ƃŏ_��͉�����邱�Ƃ��ł��܂��B
	//  ���A�G�����Ƃ��������֐���錾��`����K�v���o�Ă��܂��B
	//  ����Ĉ�̊֐��𒼂����ƂɂȂ�ƑS�Ăɑ΂��ĕύX�������Ȃ��Ƃ����Ȃ��Ȃ�܂��B
	//���ێ琫�~
	//�E�R�[�h���ώG�ɂȂ�₷���A�����ɂȂ�Ɨ������ɂ����A�q���[�}���G���[���N���������ł��B
	//���ǐ��~

	//2.
	//�E�L�����N�^�[�������Ă������ɃI�[�o�[���[�h�𑝂₳�Ȃ���΂����܂���B
	//  ������ύX�����ׂĂɑ΂��ĉ����Ȃ���΂Ȃ�Ȃ��Ȃ�̂ł悭����܂���B
	//  ���ێ琫�~
#pragma endregion

#pragma region <�����b�g�E�f�����b�g>
//<�����b�g>
//	�E�N���X���m�̈ˑ��֌W�̐؂藣���ƕێ琫(�J�v�Z����)�̋���
//	���L�����N�^�[���̃R�[�h������ς��邱�ƂȂ��A����̐������s�����Ƃ��o����
//		(�������镐�푤�̃R�[�h�݂̂�ҏW����悤�ɂȂ邽��)
//	�E�_��̌���
//	���L�����N�^�[�Ɉˑ����Ȃ��Ȃ�̂ł������񑝂₷���Ƃ��o����
//<�f�����b�g>
//	�E�v���W�F�N�g����剻���₷��
//	�E�t�@�C��(�\�[�X)�������傷��
#pragma endregion

#pragma region �T�v

#pragma endregion


namespace GoF {
	namespace AbstractFactory {

#pragma region ����

		//	����̃C���^�[�t�F�C�X
		__interface IWeapon
		{
			void create();//��������(�T���v���ł̓_�~�[)
			const char*getWeaponName();
		};

		//	�r�[�����C�t��
		class CBeamRifle:public IWeapon
		{
		public:
			CBeamRifle() = default;
			~CBeamRifle() = default;

			void IWeapon::create() {};
			inline const char* IWeapon::getWeaponName() { return "�r�[�����C�t��"; }
		private:
		};

		//	�����o���J��
		class CHeadBalkan:public IWeapon
		{
		public:
			void IWeapon::create() {};
			inline const char*IWeapon::getWeaponName() { return "�����o���J��"; }
		private:

		};

		//	�r�[���T�[�x��
		class CBeamSaber:IWeapon
		{
		public:
			void IWeapon::create() {}
			inline const char*IWeapon::getWeaponName() { return "�r�[���T�[�x��"; }
		private:

		};

#pragma endregion

#pragma region �t�@�N�g���[
		//	���ۃN���X
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

		//	�A�M�R�̕���Z�b�g
		class CFederalArmySet
		{
		public:
		};

		//	�W�I���̕���Z�b�g
#pragma endregion

#pragma region �L����

		//	�L�����N�^�[�̃C���^�[�t�F�C�X
		__interface ICharacter
		{
			//	��������
			void equip(CAbstractFactory*);

			//TODO: �T���v���Ȃ̂ŃR�����g�A�E�g���Ƃ��܂��B
			//		���ۂ̐���ł͎��������������������c
			//void attack();
			//void move();
		};

		//	�K���_���N���X
		class CGundam:public ICharacter
		{
		public:
			CGundam() = default;
			~CGundam() = default;

			void ICharacter::equip(CAbstractFactory* factory) {factory.};
		private:
			IWeapon*m_pMainWeapon;	//�啺��
			IWeapon*m_pSubWeapon;	//������
			IWeapon*m_pMeleeWeapon;	//�ߐڕ���
		};

		//	�W���N���X
		class CGM
		{

		};
#pragma endregion

	}
}