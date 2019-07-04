using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// メニューのテキストのコントローラー
/// </summary>
public class MenuTextController : MonoBehaviour {

    //静的インスタンス
    private static MenuTextController _instance;
    public static MenuTextController MTC {
        get {
            //null
            if (!_instance)
            {
                _instance = GameObject.Find("MenuTextController").GetComponent<MenuTextController>();
            }

            return _instance;
        }
    }

    //テキストコンポーネント
    public Text titleText; //タイトル
    public Text introText; //イントロ
    public Text inGameText;//インゲーム
    public Text resultText;//リザルト

    public void SetTitle()
    {
        titleText.color = Color.red;
        introText.color = Color.black;
        inGameText.color = Color.black;
        resultText.color = Color.black;
    }

    public void SetIntro()
    {
        titleText.color = Color.black;
        introText.color = Color.red;
        inGameText.color = Color.black;
        resultText.color = Color.black;
    }

    public void SetInGame()
    {
        titleText.color = Color.black;
        introText.color = Color.black;
        inGameText.color = Color.red;
        resultText.color = Color.black;
    }

    public void SetResult()
    {
        titleText.color = Color.black;
        introText.color = Color.black;
        inGameText.color = Color.black;
        resultText.color = Color.red;
    }
}
