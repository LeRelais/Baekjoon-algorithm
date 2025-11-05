import math

pt1 = input()
pt2 = input()

# 1. 행(Row) 차이 계산 (숫자 1-8)
row_diff = abs(int(pt2[1]) - int(pt1[1]))

# 2. 열(Column) 차이 계산 (문자 'a'-'h')
# ord() 함수를 이용해 문자를 ASCII 값으로 변환하여 차이를 구합니다.
col_diff = abs(ord(pt2[0]) - ord(pt1[0]))

# 3. x, y 순서 정렬 (0 <= x <= y 규칙 준수)
# innohorse 타입은 이동 거리 {col_diff, row_diff} 중 작은 값이 x, 큰 값이 y가 됩니다.
x = min(row_diff, col_diff)
y = max(row_diff, col_diff)

# 4. 결과 출력
print(x, y)