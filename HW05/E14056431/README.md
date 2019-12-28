[線上筆記連結](https://hackmd.io/@6R35tGUKTmC5_lms3b3V3g/HJSBL4aaH)

# 物件導向HW5討論報告

## 結果比較

### 第一版
#### 測資3-1
過濾結果：5276
花費時間：3184ms
#### 測資3-2
過濾結果：-
花費時間：超過10小時,但僅處理完不到一半測資
#### 測資3-3
過濾結果：24
花費時間：0ms

### 第二版
#### 測資3-1
過濾結果：5276
花費時間：468ms 
**較第一版快2.716秒**
#### 測資3-2
過濾結果：687166
花費時間：5587171ms (約1.55小時)
**較第一版快超過可能十來小時**
#### 測資3-3
過濾結果：24
花費時間：430ms 
**較第一版慢0.430秒**

## 演算法說明

>已自行重新定義 Point 型別的 == 及 != 運算子

### 第一版
此版使用單純的 "nested for loop" 以及 if/else 判斷式，
讓單點和後續所有點一一比對，並於兩點相同時移除該後續點，同時計數減一，僅保留第一點，
照此步驟持續至陣列結尾，完成所有點的比對。

由於範例程式給的是 Point 的一維陣列，但個人習慣是使用 Point* 的陣列，
原因是習慣用 nullptr 來做物件存在判斷。
考量到任何點皆有可能出現，並提升程式撰寫方便性，
此題我取陣列第一項 Point 作為移除點後 blank 的代表值，
這也是為何底下程式第9行的迴圈入口條件為 第一次迴圈 or 基準點尚未移除。

以下程式：
```cpp=1
// Use first point to represent blank after removing
Point empty = point_array[0];
int left = nPoint;    // left amount

// Check each one with pushing forward starter
for (int i = 0; i < nPoint - 1; ++i)
{
	// Check if the point isn't removed yet
	if (i == 0 || point_array[i] != empty) {
		for (int j = i + 1; j < nPoint; ++j)
		{
			// If same, remove & minus one
			if (point_array[i] == point_array[j])
			{
				point_array[j] = empty;
				left--;
			}
		}
	}
}
```

### 第二版
>已自行重新定義 List(linked list) 及 Node 型別，及其基本函式。

此版的第一副版本是使用單一 linked list 紀錄已出現之非重複點，
接著用所有點對 list 進行查詢及插入。

而後我再進行改良，
畢竟對410萬筆資料的第二測資來說，移除重複點後仍有69萬個點，及list長69萬，
而 List::find() 的方法即完全遍歷，效率上實在不足。

目前最終版，我選擇較為暴力的拆解法，
我根據每個點的三軸座標，將其小數位捨棄化整後，再取其除100的餘數，
最後依照這三個數將其插入該特定的 List 中，
以試圖避免單一 List 過長的問題。

以下為程式：
```cpp=1
// A three-dimension array of linked list
// categorate points by its tail of integer part
List ****result = new List***[100];
for (int i = 0; i < 100; ++i)
	result[i] = new List**[100];
for (int i = 0; i < 100; ++i)
	for (int j = 0; j < 100; ++j)
		result[i][j] = new List*[100];
for (int i = 0; i < 100; ++i)
	for (int j = 0; j < 100; ++j)
		for (int p = 0; p < 100; ++p)
			result[i][j][p] = new List();

// Check if a point exist at its list, if not, insert it
for (int i = 0; i < nPoint; ++i)
{
	int x = (long long int)(point_array[i][0]) >= 0 ? (long long int)(point_array[i][0]) % 100 : (long long int)(-point_array[i][0]) % 100;
	int y = (long long int)(point_array[i][1]) >= 0 ? (long long int)(point_array[i][1]) % 100 : (long long int)(-point_array[i][1]) % 100;
	int z = (long long int)(point_array[i][2]) >= 0 ? (long long int)(point_array[i][2]) % 100 : (long long int)(-point_array[i][2]) % 100;
	if (!result[x][y][z]->find(point_array[i]))
		result[x][y][z]->insert(point_array[i]);
}

// Get sum of sizes
int size = 0;
for (int i = 0; i < 100; ++i)
	for (int j = 0; j < 100; ++j)
		for (int p = 0; p < 100; ++p)
				size += result[i][j][p]->size;
```

## 效率結果討論

這兩版演算法的時間複雜度皆為 O(n^2)

對最糟的結果來說
1. 全相異點
2. 在第二版中皆位於同一 linked list 上

實際上第二版甚至比第一版慢。

但兩者不同的是，
第一版的 nested loop，決定其運算時間的主要是測資點數量，其變動性較低，
無論點分布為何，都無法改變運算時間太多。

第二版的時間複雜度則取決於點在100\*100\*100 List陣列的分布上，
測資數量並不是最大的影響，畢竟n個點我們也就每個點丟進去分析一次，
所謂最糟情況是全部在同一List上，遍歷時間拉高導致單一點的運算量跟著提高，
因此時間複雜度計算為(n+1)\*n/2，即1加到n，
但倘若今天點位較為分散，則將大大提升程式效率。

總結一下，
在看測試時間比較時可以看到，第三筆測資 (132->24) 上，反而原版程式較快，
推測由於第二版有較多記憶體動態分配流程，以及最壞情況下本來程式執行效率就較差的緣故。
但第一二筆測資，分別有31632 和 4123500 的基底資料，
基數的拉高導致倘若分配均勻，第二版程式則會有較第一版程式顯著成長的執行效率。