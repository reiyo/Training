int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    if (X == Y) return 0;
    else {
        int cnt = (Y-X)/D;
        return (X+D*cnt < Y)? cnt+1 : cnt;
    }
}
