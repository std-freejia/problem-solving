## Birthday Cake Candles

HackerRank Algorithm Warmup

-----

벡터에서 최대값 원소를 찾는다. 

최대값 원소가 총 몇개인지 리턴하는 문제다.  

</br>

### 내 코드 

```c++

int birthdayCakeCandles(vector<int> a) {
    // 최대 원소 값 
    int max_one = *max_element(a.begin(), a.end());
    // 개수 
    int cnt = count(a.begin(), a.end(), max_one);
    
    return cnt;
}
```

</br>