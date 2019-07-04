
namespace Sample
{

    /******************************/
    /* enumの書き方のサンプルです */
    /******************************/

    /*
     *  型の名前(自分でつける)
        enum ○○〇                    //列挙体の宣言文
        {                              //始カッコ

          //列挙する要素の名前
          △△△ = 0,                      
          △△△ = 1,                      
          △△△ = 2,                      
          //※","で区切るのを忘れずに！
        }                              //終カッコ

        作ったenum型は宣言してあげましょう！
     */

    //サンプルコード
    public class CSample
    {
        //列挙体宣言
        enum Sample
        {
            hoge        　  = 0,
            hogehoge        = 1,
            hogehogehoge    = 2,
        }

        //変数宣言
        Sample sample;


        /********************************/
        /* switchの書き方のサンプルです */
        /********************************/
        void switchSample()
        {
            switch (sample)
            {
                case Sample.hoge:
                    //処理
                    break;
                case Sample.hogehoge:
                    //処理
                    break;
                case Sample.hogehogehoge:
                    //処理
                    break;
            }
        }


        /************************************/
        /* enum型キャスト演算のサンプルです */
        /************************************/
        void castSample()
        {
            /*【注意】
             * 
                上記のenum型は値はintですが、int型を直接いれることは出来ません。
                (※インクリメント(++sample)、デクリメント(--)は出来ます。)

                ×出来ない例
                sample = 0;

                〇出来る例
                sample = Sample.hoge;

                このように値のSample.hogeが0だったとしてもエラーが吐かれ代入することが出来ません。
                注意しましょう。


            しかし、時にはどうしてもenum型にint型を入れたい場面が出てきます。
            その場合は型を変換してから代入してあげることでenum型にint型を入れてあげることが出来ます。
            このように一度型を変換してから代入することを"(型)キャスト"といいます。
            以下に書くのはそのサンプルです。
             */

            sample = (Sample)1;     //これはsampleにSample.hogehogeを入れたのと同義
            int tmp = (int)sample;  //これは現在のsample変数の型をint型に入れている
        }
    }

}