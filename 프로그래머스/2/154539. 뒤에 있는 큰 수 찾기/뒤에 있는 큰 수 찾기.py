def solution(numbers):
    n = len(numbers)
    answer = [-1] * n
    stack = []
    
    for i in range(n):
        while stack and numbers[i] > numbers[stack[-1]]:
            answer[stack[-1]] = numbers[i]
            stack.pop()
        stack.append(i)
        
    return answer