# plan

## 仕様

- global変数は禁止
- programの名前はfractol
- 使用可能関数
  - open
  - close
  - read
  - write
  - printf
  - malloc
  - free
  - perror
  - strerror
  - exit
  - all math library
  - all functions of the minilibX
- 作成図形
  - Jlia集合
  - Mandelbrot集合
- マウスホイールでのズームアウトとズームイン（可能な限り）
- フラクタルの深さを示すために、数色を使う（サイケデリックな効果を狙うとよりよい）
- コマンドラインで指定できるもの
  - フラクタルの種類
  - フラクタルそれぞれで必要なパラメータ
- コマンドラインに正しいパラメータが来なかった場合や、パラメータが渡されなかった場合は、パラメータ一覧を表示して終了する
- 様々なパラメータで様々なJulia集合を作れるようにしなければならない（項目重複してる？）
- ESCでプログラムを終了
- bonus
  - もうひとつ別のfractal図形を作成
  - ズームをマウスの位置に従わせる
  - 矢印キーでの移動
  - 色の範囲を変化させる

## todo
- [x] ESCでプログラムを終了
- [x] 簡単な図形の作成