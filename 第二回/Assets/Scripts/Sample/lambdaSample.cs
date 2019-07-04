using UnityEngine;
namespace lambdaSample
{

    /*
     *  C# ラムダ式の基本構文
         
        左辺 => 右辺

        =>演算子のことをgoes to(ゴーズ・トゥ)と読む

        ※---------------------------------------------┐
        | 今回取り上げるラムダ式の書き方は             |
        | "コールバック関数を作るうえでの書き方です。" |
        | LINQとかiteratorとか構文が変わります         |
        ∟_____________________________________________|
     */

    //サンプルコード
    public class CSample
    {
        /****************************/
        /* コールバック関数の型宣言 */
        /****************************/

        //  引数無し、戻り値無しの基本型
        delegate void dSample1();//基本的にこれしか使わない

        //  int型引数、戻り値無しの型
        delegate void dSample2(int arg);

        //  複数の引数、戻り値無しの型
        delegate void dSample3(int arg1, int arg2);

        //  複数の引数、int型戻り値の型
        delegate int dSample4(int arg1, int arg2);

        //  変数宣言
        dSample1 _d1;
        dSample2 _d2;
        dSample3 _d3;
        dSample4 _d4;


        /***************************************/
        /* 無名/匿名関数の書き方のサンプルです */
        /***************************************/
        void namelessSample()
        {
            //  _d1の中に { }内の処理を登録
            _d1 = delegate() { Debug.Log("無名/匿名関数"); };
            /*  ()の省略も可能
             *  
                _d1 = delegate { Debug.Log("無名/匿名関数"); };
             */

            //  _d2に処理を登録
            _d2 = delegate (int arg) { Debug.Log(arg); };


            // _d3に処理を登録
            _d3 = delegate (int arg1, int arg2) { Debug.Log(arg1 + arg2); };

            // _d4に処理を登録
            _d4 = delegate (int arg1, int arg2) { return arg1 + arg2; };
        }


        /**********************************/
        /* ラムダ式の書き方のサンプルです */
        /**********************************/
        void lambdaSample()
        {
            //  _d1の中に { }内の処理を登録
            _d1 = () => { UnityEngine.Debug.Log(""); };

            //  _d2に処理を登録
            _d2 = (int arg) => { Debug.Log(arg); };

            // _d3に処理を登録
            _d3 = (int arg1, int arg2) => { Debug.Log(arg1 + arg2); };

            // _d4に処理を登録
            _d4 = (int arg1, int arg2) => { return arg1 + arg2; };
        }

        /******************************************/
        /* 登録した処理の呼び出し方のサンプルです */
        /******************************************/
        void callSample()
        {
            //  _d1に登録した処理を行う
            _d1();

            //  _d2に登録した処理を引数10で行う
            _d2(10);

            //  _d3に登録した処理を引数1と2で行う
            _d3(1, 2);

            //  _d4に登録した処理を引数1と2で戻り値を取得する
            int ret = _d4(1, 2);
        }
    }
}