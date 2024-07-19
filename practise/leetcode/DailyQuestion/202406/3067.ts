function countPairsOfConnectableServers(edges: number[][], signalSpeed: number): number[] {
    const n = edges.length + 1;
    const g: [number, number][][] = new Array(n).fill(0).map(() => []);
    for(const [x,y,w] of edges){
        g[x].push([y, w]);
        g[y].push([x, w]);
    }

    const dfs = (x:number,fa:number,sum:number):number=>{
        let cnt = sum % signalSpeed === 0 ? 1 : 0;
        for(const[y,w] of g[x]){
            if(y!==fa){
                cnt += dfs(y, x, sum + w);
            }
        }
        return cnt;
    }

    const ans = new Array(n).fill(0);
    for(let i=0;i<n;i++){
        let sum = 0;
        for(const [y,w] of g[i]){
            const cnt = dfs(y, i, w);
            ans[i] += cnt * sum;
            sum += cnt;
        }
    }
    return ans;
};