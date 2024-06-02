function distributeCandies(candyType: number[]): number {
    let s = new Set(candyType);
    return Math.min(s.size,candyType.length/2);
};

function distributeCandie(candyType: number[]): number {
    let ctmp:{[key:number]:number}={};
    for(let e of candyType){
        if(e in ctmp){
            ctmp[e]++;
        }else{
            ctmp[e]=1;
        }
    }
    let ans=Math.floor(candyType.length/2); // floor表示向下取整
    return Math.min(ans,Object.keys(ctmp).length);
};