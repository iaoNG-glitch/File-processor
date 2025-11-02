# File-processor

# 프로세스 협력 파일 처리기

 

### 개요

- 클라이언트-서버 모델을 사용하여 파일의 각 줄 처리

- 클라이언트는 파일의 각 줄을 서버에 전송

- 서버는 지정된 처리 모드에 따라 각 줄을 처리한 후 결과를 클라이언트에 반환

- 처리 모드:

  - count: 문자 수 및 단어 수 계산

  - upper: 대문자로 변환

  - lower: 소문자로 변환

  - reverse: 문자열 뒤집기

- 사용법

  
  Server
  ```
  ./file_processor_svr
  ```
  Client
  ```
  ./file_processor_clnt <input_file> <mode>
  ```
- <input_file>: 처리할 텍스트 파일의 경로
- <mode>: count, upper, lower, reverse 중 하나

 

## 실행결과

### 클라이언트: count


./file_processor_clnt test.txt count
```
 1번째 줄 전송...
 1번째 줄 결과 수신: Line 1: 16 chars, 2 words
 2번째 줄 전송...
 2번째 줄 결과 수신: Line 2: 68 chars, 13 words
 3번째 줄 전송...
 3번째 줄 결과 수신: Line 3: 0 chars, 0 words
 4번째 줄 전송...
 4번째 줄 결과 수신: Line 4: 218 chars, 40 words
 5번째 줄 전송...
 5번째 줄 결과 수신: Line 5: 68 chars, 13 words
 6번째 줄 전송...
 6번째 줄 결과 수신: Line 6: 56 chars, 11 words
 7번째 줄 전송...
 7번째 줄 결과 수신: Line 7: 48 chars, 10 words
 
 === 처리 통계 ===
 처리 모드: count
 처리한 줄 수: 7줄
 소요 시간: 0.00초
```

### 클라이언트: upper



./file_processor_clnt test.txt upper
```
 1번째 줄 전송...
 1번째 줄 결과 수신: HELLO, EVERYONE.
 
 2번째 줄 전송...
 2번째 줄 결과 수신: THIS FILE IS A TEXT FOR ASSIGNMENT 4. BELOW ARE SOME VARIOUS QUOTES.
 
 3번째 줄 전송...
 3번째 줄 결과 수신: 
 
 4번째 줄 전송...
 4번째 줄 결과 수신: 1. EVERY SITUATION IN OUR LIVES IS JUST A MOMENT. THEREFORE, IF THE SITUATION IS GOOD, SIMPLY ENJOY IT FULLY. AND EVEN IF THE SITUATION IS NOT GOOD, REMEMBER THAT IT WILL NOT LAST FOREVER AND WILL GRADUALLY GET BETTER.
 
 5번째 줄 전송...
 5번째 줄 결과 수신: 2. NO MATTER HOW DIFFICULT THE PAST WAS, YOU CAN ALWAYS START AGAIN.
 
 6번째 줄 전송...
 6번째 줄 결과 수신: 3. DO NOT TELL PEOPLE YOUR PLANS; SHOW THEM THE RESULTS.
 
 7번째 줄 전송...
 7번째 줄 결과 수신: 4. A MOUNTAIN IS A MOUNTAIN, AND WATER IS WATER.
 
 
 === 처리 통계 ===
 처리 모드: upper
 처리한 줄 수: 7줄
 소요 시간: 0.00초

```

 

### 클라이언트: lower



./file_processor_clnt test.txt lower
```
 1번째 줄 전송...
 1번째 줄 결과 수신: hello, everyone.
 
 2번째 줄 전송...
 2번째 줄 결과 수신: this file is a text for assignment 4. below are some various quotes.
 
 3번째 줄 전송...
 3번째 줄 결과 수신: 
 
 4번째 줄 전송...
 4번째 줄 결과 수신: 1. every situation in our lives is just a moment. therefore, if the situation is good, simply enjoy it fully. and even if the situation is not good, remember that it will not last forever and will gradually get better.
 
 5번째 줄 전송...
 5번째 줄 결과 수신: 2. no matter how difficult the past was, you can always start again.
 
 6번째 줄 전송...
 6번째 줄 결과 수신: 3. do not tell people your plans; show them the results.
 
 7번째 줄 전송...
 7번째 줄 결과 수신: 4. a mountain is a mountain, and water is water.
 
 
 === 처리 통계 ===
 처리 모드: lower
 처리한 줄 수: 7줄
 소요 시간: 0.00초
```

 

### 클라이언트: reverse



./file_processor_clnt test.txt reverse
```
 1번째 줄 전송...
 1번째 줄 결과 수신: .enoyreve ,olleH
 2번째 줄 전송...
 2번째 줄 결과 수신: .setouq suoirav emos era woleB .4 tnemngissA rof txet a si elif sihT
 3번째 줄 전송...
 3번째 줄 결과 수신: 
 4번째 줄 전송...
 4번째 줄 결과 수신: .retteb teg yllaudarg lliw dna reverof tsal ton lliw ti taht rebmemer ,doog ton si noitautis eht fi neve dnA .ylluf ti yojne ylpmis ,doog si noitautis eht fi ,eroferehT .tnemom a tsuj si sevil ruo ni noitautis yrevE .1
 5번째 줄 전송...
 5번째 줄 결과 수신: .niaga trats syawla nac uoy ,saw tsap eht tluciffid woh rettam oN .2
 6번째 줄 전송...
 6번째 줄 결과 수신: .stluser eht meht wohs ;snalp ruoy elpoep llet ton oD .3
 7번째 줄 전송...
 7번째 줄 결과 수신: .retaw si retaw dna ,niatnuom a si niatnuom A .4
 
 === 처리 통계 ===
 처리 모드: reverse
 처리한 줄 수: 7줄
 소요 시간: 0.00초
```

 

### 서버

```
 1번째 줄 처리 중...
 2번째 줄 처리 중...
 3번째 줄 처리 중...
 4번째 줄 처리 중...
 5번째 줄 처리 중...
 6번째 줄 처리 중...
 7번째 줄 처리 중...
```
