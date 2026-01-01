def solution(sequence, k):
    answer = []
    n = len(sequence)
    sum = 0
    left = 0
    min_len = float('inf')
    
    for right in range(n):
        sum += sequence[right]
        
        while sum > k:
            sum -= sequence[left]
            left += 1
        
        if sum == k:
            current_len = right - left + 1
            
            if current_len < min_len:
                min_len = current_len
                answer = [left, right]
        
        
    return answer