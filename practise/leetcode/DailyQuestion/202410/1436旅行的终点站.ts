function destCity(paths: string[][]): string {
    const sa = new Set();
    for (const p of paths){
        sa.add(p[0]);
    }
    for (const p of paths){
        if(!sa.has(p[1])){
            return p[1];
        }
    }
    return "";
};