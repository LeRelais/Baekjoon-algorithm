def to_min(time):
    h, m = map(int, time.split(':'))
    return h * 60 + m

def solution(plans):
    answer = []
    new_plans = []
    
    for subject, start, play in plans:
        new_plans.append([subject, to_min(start), int(play)])
    new_plans.sort(key=lambda x : x[1])
    
    st = []
    
    for i in range(len(new_plans)):
        if i == len(new_plans) - 1 :
            answer.append(new_plans[i][0])
            break
        
        subject, start, play = new_plans[i]
        next_start = new_plans[i+1][1]
        diff = next_start - start
        
        if play > diff:
            st.append([subject, play - diff]) 
        else:
            answer.append(subject)
            remaining = diff - play
            while remaining > 0 and st:
                st_name, st_t = st.pop()
                if st_t <= remaining:
                    remaining -= st_t
                    answer.append(st_name)
                else:
                    st.append([st_name, st_t - remaining])
                    remaining = 0
    while st:
        answer.append(st.pop()[0])
    return answer