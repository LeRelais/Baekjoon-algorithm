def solution(strArr):
    answer = []
    counter = 0
    
    for item in strArr:
        if counter % 2 == 1:
            item = item.upper()
        else :
            item = item.lower()
        answer.append(item)
        counter += 1
        
    return answer