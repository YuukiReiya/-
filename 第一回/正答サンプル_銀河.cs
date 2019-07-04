using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// サンプルシーンのメニューコントローラー
/// </summary>
public class MenuController : MonoBehaviour {

    /****************************************************/
    /*下記のメニュー用変数をenumを使って書き直してみよう*/
    /****************************************************/
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

    //! めぬうのえ～なむ
    enum MenuName
    {
        Title   = 0,
        Intro   = 1,
        Game    = 2,
        Result  = 3,
    }

    //  メニュー用変数
    public int _menu;
    
    //!
    MenuName menuName;

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
        // //タイトル
        // if (_menu == 0)
        // {
        //     MenuTextController.MTC.SetTitle();
        // }
        // //イントロ
        // else if (_menu == 1)
        // {
        //     MenuTextController.MTC.SetIntro();
        // }
        // //ゲーム
        // else if (_menu == 2)
        // {
        //     MenuTextController.MTC.SetInGame();
        // }
        // //リザルト
        // else if (_menu == 3)
        // {
        //     MenuTextController.MTC.SetResult();
        // }

        switch (menuName)
        {
            // タイトル
        case MenuName.Title:
            MenuTextController.MTC.SetTitle();
            break; 
            // イントロ
        case MenuName.Intro:
            MenuTextController.MTC.SetIntro();
            break; 
            // ゲーム
        case MenuName.Game:
            MenuTextController.MTC.SetInGame();
            break; 
            // リザルト
        case MenuName.Result:
            MenuTextController.MTC.SetResult();
            break; 
        }
    }

    /// <summary>
    /// 入力処理
    /// </summary>
    void input()
    {
        // //下入力
        // if (getDownKey())
        // {
        //     //変数の加算
        //     _menu++;

        //     //"リザルト"時下を押されたら"タイトル"に戻す
        //     if (_menu > 3) { _menu = 0; }
        // }

        // //上入力
        // if (getUpKey())
        // {
        //     //変数の加算
        //     _menu--;

        //     //"タイトル"時下を押されたら"リザルト"に戻す
        //     if (_menu < 0) { _menu = 3; }
        // }

        //下入力
        if (getDownKey())
        {
            //変数の加算
            menuName++;

            //"リザルト"時下を押されたら"タイトル"に戻す
            if (menuName > MenuName.Result) { menuName = MenuName.Title; }
        }

        //上入力
        if (getUpKey())
        {
            //変数の加算
            menuName--;

            //"タイトル"時下を押されたら"リザルト"に戻す
            if (menuName < MenuName.Title) { menuName = MenuName.Result; }
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
}
