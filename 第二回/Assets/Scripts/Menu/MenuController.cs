//  ここのマクロをコメントアウトすると列挙体を使わない状態のソースになるよ
#define 列挙体

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// サンプルシーンのメニューコントローラー
/// </summary>
public class MenuController : MonoBehaviour {

    #region 第一回内容
    /****************************************************/
    /*下記のメニュー用変数をenumを使って書き直してみよう*/
    /****************************************************/
    #endregion
    /*
        【条件】
            状態      数値
        ・タイトル を 0
        ・イントロ を 1
        ・ゲーム   を 2
        ・リザルト を 3
        とする

        ※変数名は問いません
    */
    //  メニュー用変数
    #region enum使用
#if 列挙体
    enum EMenu
    {
        eTitle, //タイトル
        eIntro, //イントロ
        eInGame,//インゲーム
        eResult,//リザルト
    }
    EMenu _menu;
#endif
    #endregion
    #region enum未使用
#if 列挙体
#else
    public int _menu;
#endif
    #endregion

    #region 第二回内容
    /******************************************************/
    /* コールバック関数を使ったシーン遷移を実装してみよう */
    /******************************************************/
    #endregion

    // Use this for initialization
    void Start () {
        update();
	}
	
	// Update is called once per frame
	void Update () {

        //入力
        input();

        //更新
        update();
	}

    /****************************************************/
    /*  このupdateとinput関数の中身を書き換えましょう!  */
    /****************************************************/
    /// <summary>
    /// 更新処理
    /// </summary>
    void update()
    {
        #region 入力
#if 列挙体
        #region enum使用
        switch (_menu)
        {
            //  タイトル
            case EMenu.eTitle:  MenuTextController.MTC.SetTitle();  break;

            //  イントロ
            case EMenu.eIntro:  MenuTextController.MTC.SetIntro();  break;

            //  インゲーム
            case EMenu.eInGame: MenuTextController.MTC.SetInGame(); break;

            //  リザルト
            case EMenu.eResult: MenuTextController.MTC.SetResult(); break;
        }
        #endregion
#else
        #region enum未使用
        //タイトル
        if (_menu == 0)
        {
            MenuTextController.MTC.SetTitle();
        }
        //イントロ
        else if (_menu == 1)
        {
            MenuTextController.MTC.SetIntro();
        }
        //ゲーム
        else if (_menu == 2)
        {
            MenuTextController.MTC.SetInGame();
        }
        //リザルト
        else if (_menu == 3)
        {
            MenuTextController.MTC.SetResult();
        }
        #endregion
#endif
        #endregion
    }

    /// <summary>
    /// 入力処理
    /// </summary>
    void input()
    {
        //下入力
        if (getDownKey())
        {
            //変数の加算
            _menu++;

            //"リザルト"時下を押されたら"タイトル"に戻す
#if 列挙体
            if (_menu > EMenu.eResult) { _menu = EMenu.eTitle; }
#else
            if (_menu > 3) { _menu = 0; }
#endif
        }

        //上入力
        if (getUpKey())
        {
            //変数の加算
            _menu--;

            //"タイトル"時下を押されたら"リザルト"に戻す
#if 列挙体
            if (_menu < EMenu.eTitle) { _menu = EMenu.eResult; }
#else
            if (_menu < 0) { _menu = 3; }
#endif
        }

        //決定
        if (getEnterKey())
        {

        }
    }

    /// <summary>
    /// 下入力
    /// </summary>
    /// <returns></returns>
    bool getDownKey()
    {
        return Input.GetKeyDown(KeyCode.S) || Input.GetKeyDown(KeyCode.DownArrow);
    }

    /// <summary>
    /// 上入力
    /// </summary>
    /// <returns></returns>
    bool getUpKey()
    {
        return Input.GetKeyDown(KeyCode.W) || Input.GetKeyDown(KeyCode.UpArrow);
    }

    /// <summary>
    /// 左入力
    /// </summary>
    /// <returns></returns>
    bool getLeftKey()
    {
        return Input.GetKeyDown(KeyCode.A) || Input.GetKeyDown(KeyCode.LeftArrow);
    }

    /// <summary>
    /// 右入力
    /// </summary>
    /// <returns></returns>
    bool getRightKey()
    {
        return Input.GetKeyDown(KeyCode.D) || Input.GetKeyDown(KeyCode.RightArrow);
    }

    /// <summary>
    /// 決定入力
    /// </summary>
    /// <returns></returns>
    bool getEnterKey()
    {
        return Input.GetKeyDown(KeyCode.Space)|| Input.GetKeyDown(KeyCode.Return);
    }
}
