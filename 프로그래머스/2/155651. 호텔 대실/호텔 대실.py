import heapq

def to_min(t):
    h, m = map(int, t.split(":"))
    return h * 60 + m

def solution(book_time):
    answer = 0
    
    n = len(book_time)
    times = []
    
    for start, end in book_time:
        times.append([to_min(start), to_min(end)])
    times.sort()
    
    rooms = []
    
    for start, end in times:
        if rooms and rooms[0] <= start:
            heapq.heappop(rooms)
        
        heapq.heappush(rooms, end+10)
    
    answer = len(rooms)
    return answer