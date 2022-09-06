= ネットワーク編

SPoF（単一障害点）のないネットワーク構成を目指して。

//pagebreak

== インターネット回線

家で普通にインターネットを使う分には、インターネット回線は1回線あれば十分なんだけど、2022年7月にauで大規模通信障害があったように、インターネット回線もいつ何時障害が起きるか分からない。回線が死ぬともう手も足も出せず、通信キャリアの5Gに繋がったスマホで会社のSlackを開いて「うちのインターネットが死んだ……」と書き込むしかなくなってしまうので、そうならないよう回線を多重化しておくことにした。

いまはJCOMの1Gコースをメインの回線、そしてNTTのフレッツ光ネクスト マンションタイプをフェイルオーバー@<fn>{failover}用の回線として契約している。実際、何度かJCOMで回線障害が起きたときに、フレッツ光へフェイルオーバーして事なきを得たことがある。

//footnote[failover][稼働中のシステムで問題が起きたときに、待機させておいた同等のシステムへ自動で切り替わる仕組みのこと。]

インターネット回線は物ではなく、継続的に費用がかかる利用契約なので金額は省略とする。

== ルーター

回線を多重化したので、「メインの回線が死んだら、自動でフェイルオーバーする」という機能を持ったルーターを購入。これで「JCOMの回線が障害？じゃあフレッツ光にフェイルオーバーするぞ！」と手動で頑張らなくても、勝手にフェイルオーバーされるようになった。（@<img>{brtac828}）

//image[brtac828][ASUSのサイト@<fn>{asus}より引用][scale=0.8]{
//}

//footnote[asus][@<href>{https://www.asus.com/jp/Networking-IoT-Servers/WiFi-Routers/ASUS-WiFi-Routers/BRT-AC828/}]

ASUSのデュアルバンド オフィス向けWi-Fi無線ルーター（BRT-AC828）は、@<ttb>{30,520円}でした。

 * @<href>{https://www.yodobashi.com/product/100000001003649425/}

=={ups} UPS（無停電電源装置）

回線は多重化したものの、次のSPoF@<fn>{spof}は電源だった。寒い時期にリモートワーク2名とリモート授業1名、あと寒がりなねこ3匹ともなると、複数の部屋でエアコンをつけることになる。それに加えて洗濯乾燥機をぶん回して、さらに電子レンジを使ったりするとさすがにブレーカーが落ちる。

もともとルーターの手前にはAPC ES425というUPS@<fn>{ups}を挟んで、たとえ停電が起きても、無線LANに繋いでいるノートパソコンやスマホは問題なくインターネットを使い続けられるようにしていた。

でも書斎は、私のデスクでも夫のデスクでも速度を求めて基本的に有線LANを使うようにしている。それに無線LANに繋いでいたとしても、ブレーカーが落ちてモニタやカメラ、マイクの電源が切れればZoom会議からは強制退場@<fn>{taizyo}になってしまうのだ。電源の上限を上げることも考えて、東京電力パワーグリッドに問い合わせてみたけれど、部屋単位の上限だけでなくマンションのフロア単位の上限もあるので気軽に上げることはできなさそうだった。

//footnote[taizyo][インターネットに繋がっていれば、Zoomのルームから追い出されるわけではないが、マイクはミュートに、カメラはオフになって、相手から見ると「なんか急に居なくなった？！」という状態になる。]

そこで家庭内で電源がSPoFになってるところにUPSを追加投入することにした。（@<img>{ups}）

//footnote[spof][SPoFとはSingle Point Of Failureの略。日本語にすると単一障害点。そこが壊れたり止まったりすると、全体が動かなくなってしまう箇所のこと。]
//footnote[ups][UPSとは無停電電源装置のこと。コンセントと機器（パソコンなど）の間に挟むことで、普段はUPSの中に電気を溜めておいて、停電があったときにUPSから機器に対して電源を供給できる。といっても、後述する@<hd>{portable}のように、停電時に代替電源として長期間使うようなイメージではなく、あくまで瞬断や短時間の停電があったときに、いきなりブチッと切れるのを防ぐための存在なので電気の供給は15分～1時間程度しか保たない。]

//image[ups][私のデスクの足下に鎮座するUPS][scale=0.6]{
//}

デスク周りで電源が必要なものは全部コンセントをUPSに挿してある。ただ9つあるコンセントの口のうち、6つはバッテリーバックアップとサージ保護@<fn>{hogo}だけど、残り3つはサージ保護のみ。フットマッサージャー@<fn>{foot}みたいに、停電時に止まっても構わないものはサージ保護のみのコンセントに挿してある。

//footnote[hogo][落雷時に起きるサージ（過電圧や過電流）によって電気機器が故障しないように保護してくれる機能]
//footnote[foot][「最高のおうちオフィスではたらく」の「2.15 フットマッサージャー」を参照。]

会議用個室と私のデスクに置いたAPC ES 550（BE550M1-JP）は12,800円が2台で25,600円、夫のデスクに置いたAPC ES 750（BE750M2-JP）は22,380円、ルーターの手前に置いたAPC ES 425は7,990円で、合計@<ttb>{55,970円}でした。

 * @<href>{https://ups.ecbuyers.com/category/UPSS_UPS_ES/BE425MJP.html}
 * @<href>{https://ups.ecbuyers.com/category/UPSS_UPS_ES/BE550M1JP.html}
 * @<href>{https://ups.ecbuyers.com/category/UPSS_UPS_ES/BE750M2JP.html}

=={portable} ポータブル電源とソーラーパネル

2022年3月、東京の電気使用量が供給量に達して停電になるかも、というニュースが出た。もともと大きめの地震があるたびに、首から下げるタイプの懐中電灯とか、電池のストックとかは小まめに買い足していたので、防災用品は大分揃っていた。ポータブル電源は「今までより容量が大きくて値段が安いもの」が毎年出るので、いつ買うか迷ってたんだけど、セールで少し安くなってたのでついにAnkerのAnker PowerHouse II 800を購入！

あと、いくら容量が大きくてもポータブル電源は充電を使い切ったらおしまいなので、太陽光でポータブル電源へ充電できるソーラーパネルも一緒に購入。これで電気の供給が止まっても、一定量は永続的に電気が確保できる。（@<img>{dengen}）

//image[dengen][ソーラーパネルは太陽の方角に向けられるよう角度調節が可能][scale=0.8]{
//}

ソーラーパネルは、使わないときはこんな感じで畳んでおける。（@<img>{solar}）

//image[solar][畳むと4分の1サイズになる][scale=0.6]{
//}

AnkerのAnker PowerHouse II 800 ブラックは63,580円、Anker 625 Solar Panel (100W)は29,900円で、合計@<ttb>{93,480円}でした。

 * @<href>{https://www.ankerjapan.com/products/a1750}
 * @<href>{https://www.ankerjapan.com/products/a2431031}

== スイッチングハブ

ドッキングステーションを@<chapref>{02wife}で紹介した@<hd>{02wife|docking}に替えたら、MacBookが起動した時やスリープから起きたときに、ブロードキャストストームと思われる現象が起きるようになった。MacBook自身だけでなく、同じ有線LANに繋がっているすべての機器がインターネットに繋がらなくなるのだ。相性の問題なのか、ドッキングステーションのファームウェアをアップデートしても、専用のユーティリティを入れても繰り返し発生する。

スイッチングハブの機種を替えたら、この現象は起きなくなりました。わいわい。（@<img>{hub}）

//image[hub][ヨドバシ.comの商品ページより引用][scale=0.6]{
//}

NETGEAR アンマネージプラス スイッチングハブ ギガビット5ポート PoE+対応 63W（GS305EP-100JPS）は@<ttb>{11,600円}でした。

 * @<href>{https://www.yodobashi.com/product/100000001006014519/}
