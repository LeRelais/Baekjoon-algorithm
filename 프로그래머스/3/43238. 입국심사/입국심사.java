class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        long low = 1;
        long high = (long)1e9 * (long)1e9;
        
        while(low <= high){
            long mid = (low + high) / 2;
            long cnt = 0;
            
            for(int i = 0; i < times.length; i++){
                cnt += mid / times[i];
                if(cnt >= n)
                    break;
            }
            
            if(cnt >= n){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return answer;
    }
}