# gcc-arm-wrap -- ARM 系アーキテクチャで ```brew install``` コマンドが異常終了する問題を回避する為の gcc ラッパー

## 概要

[ARM 系アーキテクチャ][ARMP]において、 [Linuxbrew][BREW] を用いて各種パッケージをビルドする時、 ```brew install``` を起動すると、以下のようなエラーメッセージを出力して ```brew install``` コマンドが異常終了する場合があります。

```
  *** Error in `gcc-4.9': double free or corruption (top): 0x000b6a30 ***
```

この問題は、 ```brew install``` コマンドを実行する際に、 gcc コンパイラの起動時に、最適化オプションの一つとして ```-march=native``` を ```gcc``` コマンドに渡しており、また、 ```gcc``` コマンドがこのオプションに基づいて ARM 系アーキテクチャの識別を行う際に、 現行の gcc コンパイラのバージョンにおいて適切に ```-march=native``` のオプションを処理出来ない事が原因であると考えられます。

この git リポジトリに同梱されている ruby スクリプト ```cc``` は、 [Linuxbrew][BREW] において、 ```gcc``` コマンドに渡されるオプションのうち、 ```-march=native``` 及び ```-mcpu=native``` を除去するための gcc コンパイラのラッパースクリプトです。

## gcc ラッパーのインストール

gcc ラッパースクリプト ```cc``` を [Linuxbrew][BREW] に導入するには、以下の ```brew install``` コマンドを実行します。

```
  $ brew install https://raw.githubusercontent.com/z80oolong/gcc-arm-wrap/master/gcc-arm-wrap.rb
```

また、以下のように ```git clone``` コマンドによってこの git リポジトリを取得した後に、以下の通りに ```brew install``` コマンドを実行しても、 gcc ラッパースクリプトを導入出来ます。

```
  $ git clone https://github.com/z80oolong/gcc-arm-wrap.git
  $ cd gcc-arm-wrap
  $ brew install ./gcc-arm-wrap.rb
```

上記コマンドの実行後は、 gcc ラッパースクリプト ```cc``` の導入の他、 ```gcc, g++, gcc-4.9, g++-4.9``` 等のコマンドも ```cc``` へのシンボリックリンクとして生成されます。

## 注意点

この gcc ラッパースクリプト ```cc``` は、ディレクトリ ```$HOMEBREW_PREFIX/bin (ここに、 $HOMEBREW_PREFIX は、 Linuxbrew の導入先となるディレクトリ)``` 以下に導入されるスクリプトです。

従って、この git リポジトリに同梱されている Formula である **```gcc-arm-wrap.rb``` は、 [Linuxbrew][BREW] に gcc コンパイラを導入するための Formula である、 ```gcc@4.9, gcc@5, gcc@6, gcc@7, gcc@8``` 等と衝突する Formula であることに注意して下さい。**

## 使用条件

本リポジトリは、 [Linuxbrew][BREW] において使用するラッパースクリプトとしての Tap リポジトリの一つとして、 [Z.OOL. (mailto:zool@zool.jpn.org)][ZOOL] が著作権を有し、[Linuxbrew][BREW] のライセンスと同様である [BSD 2-Clause License][BSD2] に基づいて配布されるものとします。詳細については、本リポジトリに同梱する ```LICENSE``` を参照して下さい。

<!-- 外部リンク一覧 -->

[ARMP]:https://www.arm.com/
[BREW]:http://linuxbrew.sh/
[BSD2]:https://opensource.org/licenses/BSD-2-Clause
[ZOOL]:http://zool.jpn.org/
