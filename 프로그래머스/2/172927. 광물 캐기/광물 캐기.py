def solution(picks, minerals):
    answer = 0
    
    total_picks = sum(picks)
    minerals = minerals[:total_picks*5]
    
    groups = []
    
    for i in range(0, len(minerals), 5):
        group = minerals[i:i+5]
        dia = group.count("diamond")
        iron = group.count("iron")
        stone = group.count("stone")
        groups.append([dia, iron, stone])
    
    groups.sort(key=lambda x: (x[0], x[1], x[2]), reverse=True)
    
    for g_dia, g_iron, g_stone in groups:
        if picks[0] > 0:
            answer += (g_dia + g_iron + g_stone)
            picks[0] -= 1
        elif picks[1] > 0:
            answer += (g_dia*5 + g_iron + g_stone)
            picks[1] -= 1
        elif picks[2] > 0:
            answer += (g_dia*25 + g_iron*5 + g_stone)
            picks[2] -= 1
    
    return answer