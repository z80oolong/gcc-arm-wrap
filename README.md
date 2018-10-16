# gcc-arm-wrap -- ARM 系アーキテクチャで ```brew install``` が異常終了する問題を回避する為の gcc ラッパー

## 概要

ARM 系アーキテクチャにおいて、 ```brew install``` コマンドを用いて、各種パッケージをビルドする時、以下のようなエラーメッセージを出力して ```brew install``` コマンドが終了する場合があります。

```
  *** Error in `gcc-4.9': double free or corruption (top): 0x000b6a30 ***
```

