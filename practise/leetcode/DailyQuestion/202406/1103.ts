function distributeCandies(candies: number, num_people: number): number[] {
    let ans: number[] = new Array(num_people).fill(0);
    for (let i = 1; candies > 0; i++){
        ans[(i - 1) % num_people] += Math.min(i, candies);
        candies -= i;
    }
    return ans;
};

function distributeCandie(candies: number, num_people: number): number[] {
    let n = num_people;
    let ans: number[] = new Array(n).fill(0);
    let m = Math.floor((Math.sqrt(8 * candies + 1) - 1) / 2);
    let k = Math.floor(m / n), extra = m % n;
    for (let i = 0; i < n; i++){
        ans[i] = k * (k - 1) / 2 * n + k * (i + 1) + (i < extra ? k * n + i + 1 : 0);
    }
    ans[extra] += candies - m * (m + 1) / 2;
    return ans;
};