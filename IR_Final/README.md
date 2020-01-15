# 自動答題機器人
此機器人會讀取JSON格式的題目
例如:https://www.dropbox.com/s/kq678nfffzta5zg/20_Questions.json?dl=0

## 題目格式:
{"Question": "什麼事件是指日本嘉永六年（1853年）美國海軍准將馬修·培理率艦隊駛入江戶灣浦賀海面的事件，培理帶著美國總統米勒德·菲爾莫爾的國書向江戶幕府致意，最後雙方於次年（1854年）簽定《神奈川條約》（《日美和親條約》）。", "A": "竹橋事件", "B": "黑船來航", "C": "巨文島事件"}

而機器人在閱讀題目後，根據事先整理好的Wiki 反向索引，去計算A,B,C三個選項與題目關鍵字的關聯度(使用詞頻與TF-IDF)

## TODO:
1. 使用colab，將Wiki_IR.ipynb 開啟
2. 把Wiki_inverse_index 放到自己的google drive
  ( https://drive.google.com/open?id=1vIlw51dGxrtT8V4ZKweXS4nXKNaxlxDV )
3.將自己的Google Drive mount到 colab上 
(在第二個區塊)
from google.colab import drive
drive.mount('/content/drive', force_remount=True)

執行後點選連結，把授權碼貼上，完成Mount的動作

4.依序執行下去

## Result:
若題目的JSON檔中附有正確答案，則可以使用對答案區塊，觀看機器人答題狀況
帶有答案的題目 (200題)
https://www.dropbox.com/s/2vj7asirqh0lcjd/Questions_with_Ans.json?dl=0
將題目區塊的網址改成以上網址即可執行
