function maxHeightOfTriangle(red: number, blue: number): number {
    return Math.max(solve(red,blue),solve(blue,red));
};

function solve(x: number, y: number): number{
    const a = 2 * Math.floor(Math.sqrt(x)) - 1;
    const b = 2 * Math.floor((-1+Math.sqrt(1 + 4 * y)) / 2);
    return Math.min(a,b) + 1;
}