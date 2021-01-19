## Mini-Max Sum

Algorithm Warmup

-----

코드포스에서 유용한 벡터 함수 포스팅을 봐서 문제에 써먹었다. 

배열에서 원소의 값을 처음부터 끝까지 누적해서 더할때 반복문 필요 없이 아래처럼 가능하다.

accumulate() 함수가 있다. 

```c++
int sum = accumulate(all(), 0LL); 
// 여기서 0LL은 0과는 다르다. 
```



</br>

### 코드 

```c++
void miniMaxSum(vector<int> arr) {

    sort(arr.begin(), arr.end());
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    
    cout << sum-arr[arr.size()-1] << ' ' << sum - arr[0];
}
```

</br>